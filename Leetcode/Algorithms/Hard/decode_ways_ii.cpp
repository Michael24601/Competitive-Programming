/*
    Website: Leetcode
    Difficulty: Hard
    Language: c++
    Link: https://leetcode.com/problems/decode-ways-ii/
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
        vector<long> dp(s.size() + 1);
        long mod = 1'000'000'007;
        dp[0] = 1;

        // If the string starts with 0, it is impossible
        if(s[0] == '0') return 0;

        // dp[1] is 1 assuming the first digit is not 0 or *
        dp[1] = 1;
        // If * then it is 9
        if(s[0] == '*') dp[1] = 9; 
        
        // Else 
        for(int i = 2; i <= s.size(); i++){

            // At each step we ensure the last entry
            // is modulo 10^9 + 7
            dp[i-1] = dp[i-1] % mod;

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
                // It also works if we have *0 as it can
                // be either 10 or 20
                else if(s[index-1] == '*'){
                    // 2* because it's 10 or 20
                    dp[i] = 2 * dp[i-2]; 
                    continue;
                }
                else{
                    return 0;
                }
            }

            // If the digit before this one is 0
            // Then we are forced to have taken
            // that digit as part of a 10 or 20
            // previously, so the next digit has
            // to be taken individually
            if(s[index-1] == '0'){
                // if *
                if(s[index] == '*')
                    dp[i] = 9 * dp[i-1];
                // if not *
                else
                    dp[i] = dp[i-1];

                continue;
            }

            // Else we have 2 digits without 0

            // If both digits are **
            // we have 9 * dp[i-1] options
            // and 15 * dp[i-2] options
            if(s[index-1] == '*' && s[index] == '*'){
                dp[i] = 9 * dp[i-1] + 15 * dp[i-2];
                continue;
            }
            // If only the first digit is *
            // then we can have 1, and possibly
            // 2 options, if the second number is less
            // than or equal to 6
            else if (s[index-1] == '*'){
                // We have 1- or 2-
                if(s[index] <= '6'){
                    dp[i] = dp[i-1] + 2 * dp[i-2];
                }
                // Otherwise only 1- case
                else{
                    dp[i] = dp[i-1] + dp[i-2];
                }
                continue;
            }
            // If only the second digit is *
            // then if the first digit is 1,
            // we have 9 * dp[i-1] and 9 * dp[i-2]
            // cases (9 one digit numbers, or 9 two digit
            // numbers), if the first digit is 2,
            // we only have 9 * dp[i-1] and 6 * dp[i-2]
            // (9 one digit numbers, or 6 two digit
            // numbers up to 26 only)
            // Otherwise we only have  9 * dp[i-1].
            else if (s[index] == '*'){
                if(s[index-1] >= '3'){
                    dp[i] = 9 * dp[i-1];
                }
                else if(s[index-1] == '2'){
                    dp[i] = 9 * dp[i-1] + 6 * dp[i-2];
                }
                else if(s[index-1] == '1'){
                    dp[i] = 9 * dp[i-1] + 9 * dp[i-2];
                }
                continue;
            }


            // If the first digit is *
            // Then we have either 1 or 2 
            // options based on whether the second
            // is 

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

        // We also perform mod on the last dp
        dp[s.size()] = dp[s.size()] % mod;
        
        return dp[s.size()];
    }
};