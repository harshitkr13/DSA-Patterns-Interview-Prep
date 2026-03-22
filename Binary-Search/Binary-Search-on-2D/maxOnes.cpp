#include<bits/stdc++.h>
using namespace std;

int firstOne(vector<int> &row, int m){
    int low = 0, high = m - 1;
    int ans = m;

    while(low <= high){
        int mid = low + (high - low)/2;

        if(row[mid] == 1){
            ans = mid;
            high = mid - 1; 
        } else low = mid + 1;
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> &mat, int n, int m){
    int maxCount = 0, index = -1;

    for(int i = 0; i < n; i++){
        int first = firstOne(mat[i], m);
        int count = m - first;

        if(count > maxCount){
            maxCount = count;
            index = i;
        }
    }
    return index;
}
