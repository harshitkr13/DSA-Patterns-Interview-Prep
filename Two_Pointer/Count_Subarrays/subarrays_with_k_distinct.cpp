#include <bits/stdc++.h>
using namespace std;

// Problem: Subarrays with K Distinct
// Pattern: Count Subarrays

int helper(vector<int>& nums, int k){
    unordered_map<int,int> mp;
    int left = 0, count = 0;

    for(int right = 0; right < nums.size(); right++){
        mp[nums[right]]++;

        while(mp.size() > k){
            mp[nums[left]]--;
            if(mp[nums[left]] == 0) mp.erase(nums[left]);
            left++;
        }

        count += (right - left + 1);
    }

    return count;
}

int subarraysWithKDistinct(vector<int>& nums, int k) {
    return helper(nums, k) - helper(nums, k - 1);
}
