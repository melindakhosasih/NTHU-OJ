unsigned*** new_3d_array(unsigned n,unsigned m,unsigned k) {
    unsigned ***arrayn = (unsigned***)malloc(n*sizeof(unsigned**));
    unsigned **arraym = (unsigned**)malloc(n*m*sizeof(unsigned*));
    unsigned *arrayk = (unsigned*)malloc(n*m*k*sizeof(unsigned));
    for(int i = 0; i < n; i++) {
            arrayn[i] = i*m + arraym;
        for(int j = 0; j < m; j++) arraym[i*m+j] = (i*m+j)*k + arrayk;
    }
    return arrayn;
}

void delete_3d_array(unsigned ***arr) {
    free(arr[0][0]);
    free(arr[0]);
    free(arr);
}
