/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/richie-rich/problem
*/


#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s){
    int n = s.size();
    for(int i = 0; i < n/2; i++){
        if(s[i] != s[n-i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    
    // First check which indeces need to be changed in order to achive
    // a palindrome, irrespective of the sum. We save these indeces for
    // later if it possible, and print -1 otherwise
    int j{};
    unordered_map<int, int> indeces;
    while(k > 0 && j < n/2){
        if(s[j] != s[n-j-1]){
            s[j] = s[n-j-1] = max(s[j], s[n-j-1]);
            indeces[j] = 1;
            k--;
        }
        j++;
    }
    
    // If we ran out of moves before reaching a palindrome
    if(!isPalindrome(s)){
        cout << -1;
        return 0;
    }
    
    // Next, with the moves we have left, we try to maximize our palindrome
    // starting at the outside. Note that when we are doing a move that
    // requires changing an index we already changed in the last loop,
    // we always subtract one move since we already spent this move in the 
    // last loop, and we assume we could have retroactively maximized it 
    // then, had we known we still had some moves to go.
    int i{};
    while(k > 0 && i < n/2){
        // Either both are smaller than 9, or both are 9,
        // since at this point, we know s is a palindrome.
        if(s[i] < '9' && s[n-i-1] < '9'){
            if(k >= 2){
                s[i] = s[n-i-1] = '9';
                if(indeces.count(i))
                    k--;
                else
                    k-=2;
            }
            else if (k == 1 && indeces.count(i)){
                s[i] = s[n-i-1] = '9';
                k--;
            }
        }
        i++;
    }
    
    // Finally, we may change the middle digit
    if(k >= 1 && n % 2 == 1 && s[n/2] < '9'){
        s[n/2] = '9';
    }
    
    cout << s;
    
    return 0;
}