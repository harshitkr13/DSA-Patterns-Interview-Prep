int countSmallerEqual(vector<int> &row, int x){
    return upper_bound(row.begin(), row.end(), x) - row.begin();
}

int matrixMedian(vector<vector<int>> &mat, int n, int m){
    int low = 1, high = 1e9;

    while(low <= high){
        int mid = low + (high - low)/2;

        int count = 0;
        for(int i = 0; i < n; i++) count += countSmallerEqual(mat[i], mid);

        if(count <= (n*m)/2) low = mid + 1;
        else  high = mid - 1;
    }
    return low;
}
