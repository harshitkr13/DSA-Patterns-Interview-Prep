#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& arr, int x){
    int low=0, high=arr.size()-1, ans=arr.size();

    while(low<=high){
        int mid=low+(high-low)/2;

        if(arr[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }

    return ans;
}

int upperBound(vector<int>& arr, int x){
    int low=0, high=arr.size()-1, ans=arr.size();

    while(low<=high){
        int mid=low+(high-low)/2;

        if(arr[mid]>x){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }

    return ans;
}

int countOcc(vector<int>& arr,int x){
    return upperBound(arr,x)-lowerBound(arr,x);
}

int main(){
    vector<int> arr={1,2,2,2,3,4};
    cout<<countOcc(arr,2);
}
