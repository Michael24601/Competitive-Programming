
#include <bits/stdc++.h>

using namespace std;


vector<int> maxSum(vector<int>& v){
    sort(v.begin(), v.end());
    int numOne{}, numZero{};
    int i = 0;
    for(; i < v.size() && v[i] <= 1; i++){
        if(v[i] == 0) numZero++;
        else if (v[i] == 1) numOne++;
    }

    vector<int> sorted;
    while(numZero > 0){
        sorted.push_back(0);
        numZero--;
    }
    if(numOne == 1)
        sorted.push_back(1);
    else if (numOne > 1){
        while(numOne > 1){
            sorted.push_back(1);
            numOne--;
        }
    }

    // Pick up from where we left off
    vector<int> alternateVector(v.size() - i);
    for(int j = 0; i < v.size(); j++, i++){
        if (j % 2 == 0) {
            alternateVector[(j+1)/2] = v[i];
        } else {
            // Place elements from the end of the sorted vector
            alternateVector[alternateVector.size() - (j+1)/2] = v[i];
        }
    }

    // Push back into original
    for(int a: alternateVector){
        sorted.push_back(a);
    }

    if(numOne > 0)
        sorted.push_back(1);

    return sorted;
}

long sum(vector<int>& v){
    long s{};
    for(int i = 0; i < v.size() - 1; i++){
        s += v[i] * v[i+1];
    }
    return s;
}

int main() {

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0; i < n ; i++){
            cin >> v[i];
        }
        vector<int> s = maxSum(v);
        cout << sum(s) << "\n";
        for(int a: v){
            cout << a << " ";
        }
        cout << "\n";
    }

    return 0;
}