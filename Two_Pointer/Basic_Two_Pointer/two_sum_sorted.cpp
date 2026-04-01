#include <bits/stdc++.h>
using namespace std;

// Problem: Two Sum II (Sorted Array)
// Pattern: Basic Two Pointer

vector<int> twoSum(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while(left < right){
        int sum = arr[left] + arr[right];

        if(sum == target) return {left, right};
        else if(sum < target) left++;
        else right--;
    }

    return {-1, -1};
}
