#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int>& nums,int k,int maxSum){
    int parts=1,sum=0;

    for(int x:nums){
        if(sum+x>maxSum){
            parts++;
            sum=x;
        }
        else sum+=x;
    }
    return parts<=k;
}

int splitArray(vector<int>& nums,int k){
    int low=*max_element(nums.begin(),nums.end());
    int high=accumulate(nums.begin(),nums.end(),0);

    while(low<=high){
        int mid=low+(high-low)/2;

        if(possible(nums,k,mid))  high=mid-1;
        else low=mid+1;
    }
    return low;
}
