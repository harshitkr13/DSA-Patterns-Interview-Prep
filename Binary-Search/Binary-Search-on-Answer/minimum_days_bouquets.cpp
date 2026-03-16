#include <bits/stdc++.h>
using namespace std;

bool canMake(vector<int>& bloom,int day,int m,int k){
    int bouquets=0,flowers=0;

    for(int x:bloom){
        if(x<=day){
            flowers++;
            if(flowers==k){
                bouquets++;
                flowers=0;
            }
        }
        else flowers=0;
    }

    return bouquets>=m;
}

int minDays(vector<int>& bloom,int m,int k){
    long long need=(long long)m*k;
    if(need>bloom.size()) return -1;

    int low=*min_element(bloom.begin(),bloom.end());
    int high=*max_element(bloom.begin(),bloom.end());

    while(low<=high){
        int mid=low+(high-low)/2;

        if(canMake(bloom,mid,m,k)) high=mid-1;
        else low=mid+1;
    }

    return low;
}
