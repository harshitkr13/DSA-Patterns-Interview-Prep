//Maximum Sum Rectangle (GFG)

class Solution {
public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        int maxSum = INT_MIN;

        for(int left = 0; left < C; left++) {
            vector<int> temp(R, 0);

            for(int right = left; right < C; right++) {
                for(int i = 0; i < R; i++)
                    temp[i] += M[i][right];

                int sum = 0, maxi = INT_MIN;

                for(int i = 0; i < R; i++) {
                    sum += temp[i];
                    maxi = max(maxi, sum);
                    if(sum < 0) sum = 0;
                }

                maxSum = max(maxSum, maxi);
            }
        }

        return maxSum;
    }
};
