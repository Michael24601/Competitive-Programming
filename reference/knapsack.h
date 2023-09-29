#include <bits/stdc++.h>

using namespace std;


// 1/0 knapsack algorithm. Used when we have objects with a weight and power,
// and a bag with c capacity for weight, and we need to maximize the power
// we can have in our bag.

struct Object {
    int power;
    int weight;
};

int knapsackMaxPower(int n, int c, vector<Object>& objects, 
    vector<int>& selectedObjects) {

    // The approach to this problem is to fill a 2D array of dimension n+1, c+1,
    // with the following values: dp[i][j] is the maximum power we get from
    // having the first i gadgets while having under j weight. At this point
    // dp[i][j], we can't select from the elements after i, but we can omit elements
    // between 1 and i to have the maximal power while adhering to the weight j.
    // We first set the first row all to 0 sicne we have 0 gadgets,
    // and the first column will be 0 as well since we can't have any gadgets
    // with less than 0 weight.
    vector<vector<int>> dp(n + 1, vector<int>(c + 1, 0));

    // Then, to build the array, we can iterate in a nested loop over all of the
    // elements. At any given element dp[i][j], we have a choice. At this point,
    // we have an element gadget[i-1] (ith element) with weight and power.
    // If this gadget alone weighs more than our current weigh threshold j,
    // we simply can't use it and ignore it, and put d[i][j] as the same as the
    // last element d[i-1][j].
    // If however, it doesn't exceed j, we still need to check whether 
    // there is still enough weight to add it to d[i-1][j] as is, or wether
    // we must remove some other elements first. So we make its value
    // the maximum between not adding it, or adding it to the maximum power
    // we had already gotten for a weight threshold of the current threshold
    // minus the weight of this gadget.
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= c; ++j) {
            if (objects[i - 1].weight <= j) {
                dp[i][j] = max(dp[i - 1][j], 
                dp[i - 1][j - objects[i - 1].weight] + objects[i - 1].power);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int maxPower = dp[n][c];
    int i = n, j = c;

    // We then backtrack to find selected objects, each time if the current
    // power is different than the last, we've definitely added this current
    // object's power (at each step, we either add or do not add the
    // current object).
    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i - 1][j]) {
            selectedObjects.push_back(i - 1);
            j -= objects[i - 1].weight;
        }
        i--;
    }

    return maxPower;
}