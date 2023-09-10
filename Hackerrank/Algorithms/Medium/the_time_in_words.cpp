/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/the-time-in-words/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int h, m;
    cin >> h >> m;
    string s;
    string nums [29]{
    "one", 
    "two", 
    "three", 
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
    "ten",
    "eleven",
    "twelve",
    "thirteen",
    "fourteen",
    "quarter",
    "sixteen",
    "seventeen",
    "eighteen",
    "nineteen",
    "twenty",
    "twenty one",
    "twenty two",
    "twenty three",
    "twenty four",
    "twenty five",
    "twenty six",
    "twenty seven",
    "twenty eight",
    "twenty nine",
    };

    if(m == 0) cout << nums[h-1] + " o' clock";
    else if(m == 1) cout << "one minute past " << nums[h-1];
    else if(m < 15) cout << nums[m-1] << " minutes past " <<  nums[h-1];    
    else if(m == 15) cout << "quarter past " << nums[h-1];
    else if(m < 30) cout << nums[m-1] << " minutes past " <<  nums[h-1]; 
    else if(m == 30) cout << "half past " << nums[h-1]; 
    else if(m < 45) cout << nums[60-m-1] << " minutes to " <<  nums[h];
    else if(m == 45) cout << "quarter to " <<  nums[h];
    else if(m < 59) cout << nums[60-m-1] << " minutes to " <<  nums[h];
    else if(m == 59) cout << "1 minute to " << nums[h];
    
    return 0;
}