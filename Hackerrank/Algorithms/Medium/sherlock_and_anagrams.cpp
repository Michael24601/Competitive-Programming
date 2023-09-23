/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: c++
    Link: https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int q;
    cin >> q;
    
    while(q--){
        
        string s;
        cin >> s;
        
        // If a string a is an anargarm of b and c, then b
        // is an anagram of c. So we can just sort all of the
        // susbtrings of the string, place them in a hashmap,
        // and add to the count each time we see a repeated 
        // string. However, we can't just do count++ each time
        // we encounter the same string, we have to incremenet it
        // by a value equal to the number of anagrammatic strings
        // we already found, since all of these now form a new pair
        // with the new string.
        
        unordered_map<string, int> m;
        int count{};
        
        // Lengths of substrings
        for(int i = 1; i < s.size(); i++){
            
            // substrings 
            for(int j = 0; j < s.size() - i + 1; j++){
                string sub = s.substr(j, i);
                sort(sub.begin(), sub.end());
                m[sub]++;
                if (m[sub] > 1){
                    count += m[sub] - 1;
                }
            }
        } 
        
        cout << count << "\n";
    }
    
    return 0;
}