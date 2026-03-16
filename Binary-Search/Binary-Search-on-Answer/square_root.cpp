#include <bits/stdc++.h>
using namespace std;

long long floorSqrt(long long n) {
    long long low = 1, high = n, ans = 0;

    while(low <= high){
        long long mid = low + (high-low)/2;

        if(mid*mid <= n){
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }

    return ans;
}

int main(){
    cout << floorSqrt(28);
}
