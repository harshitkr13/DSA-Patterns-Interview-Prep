#include <bits/stdc++.h>
using namespace std;

int stationsRequired(vector<int>& arr,double dist){
    int count=0;

    for(int i=1;i<arr.size();i++){
        double gap=arr[i]-arr[i-1];
        count+=gap/dist;
    }
    return count;
}

double minimiseMaxDistance(vector<int>& arr,int k){
    double low=0;
    double high=arr.back()-arr.front();

    while(high-low>1e-6){
        double mid=(low+high)/2;

        if(stationsRequired(arr,mid)>k)  low=mid;
        else  high=mid;
    }
    return high;
}
