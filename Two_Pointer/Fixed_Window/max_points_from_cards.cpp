#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum Points You Can Obtain from Cards
// Pattern: Fixed Window

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);

    int windowSize = n - k;
    int curr = 0;

    for(int i = 0; i < windowSize; i++){
        curr += cardPoints[i];
    }

    int minSum = curr;

    for(int i = windowSize; i < n; i++){
        curr += cardPoints[i];
        curr -= cardPoints[i - windowSize];
        minSum = min(minSum, curr);
    }

    return total - minSum;
}
