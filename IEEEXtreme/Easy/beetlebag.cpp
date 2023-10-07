/*
    Website: IEEEXtreme
    Difficulty: Easy
    Language: c++
    Link: https://csacademy.com/ieeextreme-practice/task/ed8629419f140a5a2c923b049aba1224/
*/

#include <bits/stdc++.h>

using namespace std;

struct Gadget {
    int power;
    int weight;
};

// Uses the 1/0 knapsack algorithm, a classic dynamic programming algorithm
int maxPower(int n, int c, vector<Gadget>& Gadgets) {
    
    // The approach to this problem is to fill a 2D array of dimension n+1, c+1,
    // with the following values: dp[i][j] is the maximum power we get from
    // having the first i gadgets while having under j weight. At this point
    // dp[i][j], we can't select from the elements after i, but we can omit elements
    // between 1 and i to have the maximal power while adhering to the weight j.
    // We first set the first row all to 0 sicne we have 0 gadgets,
    // and the first column will be 0 as well since we can't have any gadgets
    // with less than 0 weight.
    // This is a popular dynamic programming approach to this kind of problem,
    // which is usually much faster than an iterative approach.
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
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c; j++) {
            if (Gadgets[i - 1].weight <= j) {
                dp[i][j] = max(dp[i - 1][j], 
                    dp[i - 1][j - Gadgets[i - 1].weight] + Gadgets[i - 1].power);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int maxPower = dp[n][c];
    return maxPower;
}

int main() {
    
    int t;
    cin >> t;
    
    while(t--) {
        int n, c;
        cin >> c >> n;
    
        vector<Gadget> Gadgets(n);
        for (int i = 0; i < n; ++i) {
            cin >> Gadgets[i].weight >> Gadgets[i].power;
        }
    
        int maximum = maxPower(n, c, Gadgets);
        cout << maximum << "\n";
    }

    return 0;
}