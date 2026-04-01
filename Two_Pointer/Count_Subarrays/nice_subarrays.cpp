#include <bits/stdc++.h>
using namespace std;

// Problem: Count Number of Nice Subarrays
// Pattern: Count Subarrays

int numberOfSubarrays(vector<int>& nums, int k) {
    int left = 0, odd = 0, count = 0, res = 0;

    for(int right = 0; right < nums.size(); right++){
        if(nums[right] % 2){
            odd++;
            count = 0;
        }

        while(odd == k){
            if(nums[left] % 2) odd--;
            left++;
            count++;
        }

        res += count;
    }

    return res;
}
