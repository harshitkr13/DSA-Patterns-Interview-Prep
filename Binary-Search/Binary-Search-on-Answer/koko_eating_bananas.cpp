#include <bits/stdc++.h>
using namespace std;

bool canEat(vector<int>& piles,int speed,int h){
    long long time=0;

    for(int p:piles)
        time += ceil((double)p/speed);

    return time <= h;
}

int minEatingSpeed(vector<int>& piles,int h){
    int low=1, high=*max_element(piles.begin(),piles.end());
    int ans=high;

    while(low<=high){
        int mid=low+(high-low)/2;

        if(canEat(piles,mid,h)){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }

    return ans;
}
