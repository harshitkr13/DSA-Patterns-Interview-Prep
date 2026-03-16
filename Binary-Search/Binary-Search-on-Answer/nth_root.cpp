#include <bits/stdc++.h>
using namespace std;

int NthRoot(int n, int m){
    int low = 1, high = m;

    while(low <= high){
        long long mid = low + (high-low)/2;

        long long val = pow(mid,n);

        if(val == m) return mid;

        if(val < m) low = mid + 1;
        else high = mid - 1;
    }

    return -1;
}
