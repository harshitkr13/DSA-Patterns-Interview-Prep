#include <bits/stdc++.h>
using namespace std;

int floorVal(vector<int>& arr, int x){
    int low = 0, high = arr.size()-1;
    int ans = -1;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] <= x){
            ans = arr[mid];
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}

int ceilVal(vector<int>& arr, int x){
    int low = 0, high = arr.size()-1;
    int ans = -1;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] >= x){
            ans = arr[mid];
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}

int main(){
    vector<int> arr = {10,20,30,40,50};
    int x = 25;

    cout << "Floor: " << floorVal(arr,x) << endl;
    cout << "Ceil: " << ceilVal(arr,x) << endl;
}
