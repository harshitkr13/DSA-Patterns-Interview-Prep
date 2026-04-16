//ange Addition (LC-370)

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> diff(length, 0);

        for(auto &u : updates) {
            int l = u[0], r = u[1], val = u[2];
            diff[l] += val;
            if(r + 1 < length) diff[r + 1] -= val;
        }

        vector<int> ans(length, 0);
        ans[0] = diff[0];

        for(int i = 1; i < length; i++)
            ans[i] = ans[i - 1] + diff[i];

        return ans;
    }
};
