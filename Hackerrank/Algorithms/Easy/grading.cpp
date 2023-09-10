/*
    Website: Hackerank
    Difficulty: Easy
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/grading/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int grade;
        cin >> grade;
        if(grade >= 38){
            if (grade % 10 == 3)
                grade += 2;
            else if (grade % 10 == 4)
                grade += 1;
            else if (grade % 10 == 8)
                grade += 2;
            else if (grade % 10 == 9)
                grade += 1;
        }
        cout << grade;
        if (i != n - 1) {
            cout << "\n";
        }
    }
    return 0;
}
