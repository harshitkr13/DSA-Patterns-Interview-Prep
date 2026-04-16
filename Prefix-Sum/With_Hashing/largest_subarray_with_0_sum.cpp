// Problem: Largest Subarray with 0 Sum (GeeksforGeeks)

class Solution {
public:
    int maxLen(vector<int>& A, int n) {
        unordered_map<int, int> mp;

        int sum = 0, maxLen = 0;

        for(int i = 0; i < n; i++) {
            sum += A[i];

            if(sum == 0)  maxLen = i + 1;

            // If sum seen before
            if(mp.find(sum) != mp.end())  maxLen = max(maxLen, i - mp[sum]); 
            else  mp[sum] = i; 
        }
        return maxLen;
    }
};
