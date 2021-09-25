int** malloc_ptr(int array_size) {
    int**ptr;
    ptr = (int**)malloc(array_size*sizeof(int*));
    return ptr;
}

void malloc_array(int **array, int array_size) {
    return *array = (int*)malloc(array_size*sizeof(int));
}

void pointer_ptr_to_array(int *array, int **ptr,int N) {
    for(int i = 0; i < N; i++) {
        ptr[i] = &array[(i+1)*i/2];
    }
}
