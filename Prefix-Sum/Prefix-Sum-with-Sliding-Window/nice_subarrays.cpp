//Count Number of Nice Subarrays (LC-1248)

class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if(k < 0) return 0;

        int l = 0, count = 0;

        for(int r = 0; r < nums.size(); r++) {
            if(nums[r] % 2) k--;

            while(k < 0) if(nums[l++] % 2) k++;

            count += r - l + 1;
        }

        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
