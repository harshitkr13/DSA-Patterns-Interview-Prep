// Problem: Subarrays Divisible by K (LeetCode 974)

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0, count = 0;

        for(int num : nums) {
            sum += num;
            int mod = sum % k;

            if(mod < 0) mod += k;

            if(mp.find(mod) != mp.end())  count += mp[mod];

            mp[mod]++;
        }

        return count;
    }
};
