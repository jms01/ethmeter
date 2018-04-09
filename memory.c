
void* malloc(int argSize){
    return HeapAlloc(AppStruct->heap, 0, argSize);
}
BOOL free(void* argMem){
    return HeapFree(AppStruct->heap, 0, argMem);
}
