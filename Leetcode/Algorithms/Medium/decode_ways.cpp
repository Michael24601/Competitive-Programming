/*
    Website: Leetcode
    Difficulty: Medium
    Language: c++
    Link: https://leetcode.com/problems/decode-ways/
*/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:

    int numDecodings(string s) {

        // dp[i] is the number of different ways
        // to decode s up to i characters.
        // So dp[0] = 0 is just a dummy value
        // placed there to simplify the algorithm
        vector<int> dp(s.size() + 1);
        dp[0] = 1;

        // If the string starts with 0, it is impossible
        if(s[0] == '0') return 0;

        // dp[1] is alwys 1 assuming teh first digit is not 0
        dp[1] = 1;
        
        // Else 
        for(int i = 2; i <= s.size(); i++){
            int index = i-1;

            // If the current digit is 0,
            // then the case only works
            // if we have 10 or 20
            if(s[index] == '0'){
                if(s[index-1] == '1' || s[index-1] == '2'){
                    // dp[i-2] since we are forced to take 2 digits
                    dp[i] = dp[i-2];
                    continue;
                }
                else{
                    break;
                }
            }

            // If the digit before this one is 0
            // Then we are forced to have taken
            // that digit as part of a 10 or 20
            // previously, so the next digit has
            // to be taken individually
            if(s[index-1] == '0'){
                dp[i] = dp[i-1];
                continue;
            }

            // If the two digit number that can
            // be made from the current index
            // and the one before is between
            // 1 and 26, then we can consider it
            // as well as the single digit.
            int num = (s[index] - '0');
            num += 10 * (s[index-1] - '0');
            if(num >= 1 && num <= 26){
                dp[i] = dp[i-1] + dp[i-2];
            }
            else{
                dp[i] = dp[i-1];
            }  
        }   
        
        return dp[s.size()];
    }
};