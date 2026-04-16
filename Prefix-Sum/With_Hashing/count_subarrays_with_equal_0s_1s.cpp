// Problem: Count Subarrays with Equal 0s and 1s (GeeksforGeeks)

class Solution {
public:
    int countSubarrWithEqualZeroAndOne(int arr[], int n) {
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0, count = 0;

        for(int i = 0; i < n; i++) {
            if(arr[i] == 0) sum += -1;
            else sum += 1;

            if(mp.find(sum) != mp.end())  count += mp[sum];
            mp[sum]++;
        }

        return count;
    }
};
