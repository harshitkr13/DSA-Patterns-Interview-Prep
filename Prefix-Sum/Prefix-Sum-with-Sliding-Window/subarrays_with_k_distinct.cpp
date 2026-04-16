//Subarrays with K Different Integers (LC-992)

class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int l = 0, count = 0;

        for(int r = 0; r < nums.size(); r++) {
            if(mp[nums[r]]++ == 0) k--;

            while(k < 0) {
                if(--mp[nums[l]] == 0) k++;
                l++;
            }

            count += r - l + 1;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
