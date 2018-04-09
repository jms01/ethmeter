
void statSample(struct STATSAMPLE*);

void statUpdate(){
    struct STATSTRUCT* stat = &AppStruct->stat;

    struct STATSAMPLE* lastSample = stat->lastSample;
    struct STATSAMPLE* thisSample = &stat->samples[0];

    if (lastSample == 0) {
        lastSample = &stat->samples[0];
    }

    if (lastSample == &stat->samples[0]) {
        thisSample = &stat->samples[1];
    }

    statSample(thisSample);

    stat->bytesDown = thisSample->bytesDown - lastSample->bytesDown;
    stat->bytesUp   = thisSample->bytesUp   - lastSample->bytesUp;

    stat->lastSample = thisSample;
}

PERF_OBJECT_TYPE* statFindObjectType(PERF_DATA_BLOCK*, DWORD);
PERF_COUNTER_DEFINITION* statFindCounterDef(PERF_OBJECT_TYPE*, DWORD);

void statSample(struct STATSAMPLE* sample){
    struct STATSTRUCT* stat = &AppStruct->stat;

    DWORD bufSize = sizeof(stat->perfBuf);

    PERF_DATA_BLOCK* pdb;
    PERF_OBJECT_TYPE* pot;
    PERF_COUNTER_DEFINITION* pcd;
    PERF_INSTANCE_DEFINITION* pid;
    PERF_COUNTER_BLOCK* pcb;

    RegQueryValueEx(HKEY_PERFORMANCE_DATA, "510", 0, 0, (BYTE*)&stat->perfBuf, &bufSize);

    (BYTE*)pdb = (BYTE*)&stat->perfBuf;

    pot = statFindObjectType(pdb, 510); // network interface object

    // Get counter offsets
    pcd = statFindCounterDef(pot, 264); // download counter
    DWORD downOffset = pcd->CounterOffset;

    pcd = statFindCounterDef(pot, 506); // upload counter
    DWORD upOffset = pcd->CounterOffset;

    // Aggregate counter values
    (BYTE*)pid = (BYTE*)pot + pot->DefinitionLength;
    (BYTE*)pcb = (BYTE*)pid + pid->ByteLength;

    sample->bytesDown = 0;
    sample->bytesUp   = 0;

    for(int i=0; i<pot->NumInstances; i++){
        DWORD* downBytes = (DWORD*) ((BYTE*)pcb + downOffset);
        DWORD* upBytes   = (DWORD*) ((BYTE*)pcb + upOffset);

        sample->bytesDown += *downBytes;
        sample->bytesUp   += *upBytes;

        (BYTE*)pid = (BYTE*)pcb + pcb->ByteLength;
        (BYTE*)pcb = (BYTE*)pid + pid->ByteLength;
    }
}

PERF_OBJECT_TYPE* statFindObjectType(PERF_DATA_BLOCK* pdb, DWORD objectIndex){
    PERF_OBJECT_TYPE* pot;
    (BYTE*)pot = (BYTE*)pdb + pdb->HeaderLength;

    while (pot->ObjectNameTitleIndex != objectIndex) {
        (BYTE*)pot = (BYTE*)pot + pot->TotalByteLength;
    }

    return pot;
}

PERF_COUNTER_DEFINITION* statFindCounterDef(PERF_OBJECT_TYPE* pot, DWORD counterIndex){
    PERF_COUNTER_DEFINITION* pcd;
    (BYTE*)pcd = (BYTE*)pot + pot->HeaderLength;

    while (pcd->CounterNameTitleIndex != counterIndex) {
        (BYTE*)pcd = (BYTE*)pcd + pcd->ByteLength;
    }

    return pcd;
}
