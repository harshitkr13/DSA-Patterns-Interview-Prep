#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int>& nums,int div,int threshold){
    int sum=0;

    for(int x:nums) sum+=ceil((double)x/div);
    return sum<=threshold;
}

int smallestDivisor(vector<int>& nums,int threshold){
    int low=1,high=*max_element(nums.begin(),nums.end());

    while(low<=high){
        int mid=low+(high-low)/2;

        if(possible(nums,mid,threshold))  high=mid-1;
        else low=mid+1;
    }
    return low;
}
