#include <bits/stdc++.h>
using namespace std;

int upperBound(vector<int>& arr, int x){
    int low = 0, high = arr.size()-1;
    int ans = arr.size();

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] > x){
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }

    return ans;
}

int main(){
    vector<int> arr = {1,2,3,3,5,7};
    cout << upperBound(arr,3);
}
