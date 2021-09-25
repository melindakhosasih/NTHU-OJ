int** s(int* a,int len) {
    int maxx;
    for(int i = 0; i < len; i++) {
        for(int j = i+1; j < len; j++) {
            if(*(a+i) > *(a+j)) {
                maxx = *(a+i);
                *(a+i) = *(a+j);
                *(a+j) = maxx;
            }
        }
    }
    int index = 0;
    int len2 = (int)sqrt(len);
    int** arr = (int**)malloc(len2*sizeof(int*));
    for(int i = 0; i < len2; i++) {
        arr[i] = i*len2 + a;
    }

    return arr;
}
