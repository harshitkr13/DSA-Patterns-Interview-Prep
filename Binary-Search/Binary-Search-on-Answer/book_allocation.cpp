#include <bits/stdc++.h>
using namespace std;

bool possible(vector<int>& arr,int students,int pages){
    int count=1,sum=0;

    for(int x:arr){
        if(sum+x>pages){
            count++;
            sum=x;
        }
        else sum+=x;
    }
    return count<=students;
}

int allocateBooks(vector<int>& arr,int students){
    int low=*max_element(arr.begin(),arr.end());
    int high=accumulate(arr.begin(),arr.end(),0);

    while(low<=high){
        int mid=low+(high-low)/2;

        if(possible(arr,students,mid)) high=mid-1;
        else low=mid+1;
    }
    return low;
}
