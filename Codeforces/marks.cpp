/*
    Website: Codeforces
    Language: c++
    Contest: https://codeforces.com/group/MWSDmqGsZm/contests  
    Link: https://codeforces.com/group/MWSDmqGsZm/contest/223340/problem/F
*/


#include <bits/stdc++.h>

using namespace std;
 
int max(int* a, int l) {
    int max = a[0];
    for (int i = 1; i < l; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}
 
int main() {
 
    int n, m;
    cin >> n >> m;
    int** a = new int* [m];
    for (int i = 0; i < m; i++) {
        a[i] = new int[n];
    }
    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[j][i] = int(s[j]) - '0';
        }
    }
    vector<int> win;
    int num = 0;
    for (int j = 0; j < n; j++) {
    for (int i = 0; i < m; i++) {
            if (a[i][j] == max(a[i], n)) {
                if (count(win.begin(), win.end(), j) == 0) {
                    win.push_back(j);
                    num++;
                    break;
                }
            }
        }
    }
    cout << num;
 
    return 0;
}