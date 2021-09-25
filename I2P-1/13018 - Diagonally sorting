void array2d_sort(int row, int col, long long arr[][500])
{
    for(int k = 0; k < row-1; k++){
        for(int i = 0; i < row-1; i++){
            for(int j = 0; j < col-1; j++){
                if(arr[i][j] > arr[i+1][j+1]){
                    long long maxx = arr[i][j];
                    arr[i][j] = arr[i+1][j+1];
                    arr[i+1][j+1] = maxx;
                }
            }
        }
    }
}
