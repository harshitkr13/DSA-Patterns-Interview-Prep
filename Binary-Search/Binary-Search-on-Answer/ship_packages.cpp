#include <bits/stdc++.h>
using namespace std;

bool canShip(vector<int>& w,int cap,int days){
    int need=1,load=0;

    for(int x:w){
        if(load+x>cap){
            need++;
            load=x;
        }
        else load+=x;
    }

    return need<=days;
}

int shipWithinDays(vector<int>& weights,int days){
    int low=*max_element(weights.begin(),weights.end());
    int high=accumulate(weights.begin(),weights.end(),0);

    while(low<=high){
        int mid=low+(high-low)/2;

        if(canShip(weights,mid,days)) high=mid-1;
        else low=mid+1;
    }

    return low;
}
