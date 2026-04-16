//Corporate Flight Bookings (LC-1109)

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n, 0);

        for(auto &b : bookings) {
            int l = b[0] - 1, r = b[1] - 1, val = b[2];
            diff[l] += val;
            if(r + 1 < n) diff[r + 1] -= val;
        }

        vector<int> ans(n, 0);
        ans[0] = diff[0];

        for(int i = 1; i < n; i++)
            ans[i] = ans[i - 1] + diff[i];

        return ans;
    }
};
