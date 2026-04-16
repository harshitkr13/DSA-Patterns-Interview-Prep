// Problem: Subarray Sum Equals K (LeetCode 560)

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1; // Base case

        int sum = 0, count = 0;

        for(int num : nums) {
            sum += num;

            // Check if (sum - k) exists
            if(mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }

            mp[sum]++;
        }

        return count;
    }
};
