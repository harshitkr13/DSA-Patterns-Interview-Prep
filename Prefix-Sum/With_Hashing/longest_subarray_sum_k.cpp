// Problem: Longest Subarray with Sum K (GeeksforGeeks)

class Solution {
public:
    int lenOfLongSubarr(int A[], int N, int K) {
        unordered_map<int, int> mp;

        int sum = 0, maxLen = 0;

        for(int i = 0; i < N; i++) {
            sum += A[i];

            if(sum == K)  maxLen = i + 1;
            if(mp.find(sum - K) != mp.end())  maxLen = max(maxLen, i - mp[sum - K]);
            if(mp.find(sum) == mp.end())  mp[sum] = i;
        }

        return maxLen;
    }
};
