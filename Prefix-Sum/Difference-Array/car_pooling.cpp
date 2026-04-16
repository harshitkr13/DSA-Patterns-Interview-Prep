//Car Pooling (LC-1094)

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0);

        for(auto &t : trips) {
            int num = t[0], from = t[1], to = t[2];
            diff[from] += num;
            diff[to] -= num;
        }

        int curr = 0;

        for(int i = 0; i <= 1000; i++) {
            curr += diff[i];
            if(curr > capacity) return false;
        }

        return true;
    }
};
