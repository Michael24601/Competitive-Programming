/*
    Website: Leetcode
    Difficulty: Hard
    Language: c++
    Link: https://leetcode.com/problems/number-of-digit-one/
*/


#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {

        // Naive approach is nlog(n)
        // We loop over ever number from 1 to n,
        // then loop over each's digits (whcih is log(n)).

        // Now for the correct approach, which is log(n) time.
        // We can find the number of times 1 appears in each
        // digit individually.
        // For example, suppose we have number 578.
        // 1 will appear in the unit digit 58 times:
        // when the first two digits are 00, then 01, 02... until 57.
        // Which totals 58 times.
        // So if we have xy5, the number of 1 digits in
        // the unit place is (xy+1).
        // If we want to calculate the number of digits 1
        // in the tenth place, we will likewise look at the number
        // before it, which is 5, and we will have 6*10 digits 1.
        // We have 6 because we will take x+1 (since we will start
        // counting from 0 to x, which is x+1), and we have *10
        // because the digit 1 being in the tenth place means
        // each time it is repeated 10 times in a row:
        // for example: 10, 11, 12, 13... 19 is one instance.
        // Finally, to count the number of digits 1 in teh hundredth
        // place, we can imagine an implicit 0 before, it, and
        // count the number as (0 + 1) * 100.
        
        // There is a caveat however:
        // If we have 56708 for example, and we want
        // the number of 1 digits in the 10th place, instead
        // of (567 + 1) * 10, we instead do (567) * 10:
        // This is because we have 0 in the tenth digit,
        // which means the last instance, at 567, does not
        // count, since 1 hasn't been reached, 
        // so we only count instances from 0 to 566.
        // So if we have xyz0u, 1 appears (xyz) * 10 times
        // in the tenth digit.
        
        // Another special case is 56718. Since we have 1
        // in the tenth digit, we also haven't completed the
        // 567th instance, but we have started it,
        // and out of 10 times the digit 1 should appear
        // in each instance of the 10th place, 1 has only
        // appeared 9 times: we know it's 9 because after
        // the tenth digit, we have the number 8, which
        // means 1 has appeared in 10, 11, 12... 18,
        // which is 9 times.
        // So if we have xyz1uv, the number of digits 1
        // in the hundredth place is (xyz) * 100 + (uv+1).

        // The only exceptions is if we are counting the units
        // digit, or the last digit, as there is no number
        // before or after them. We handle these cases
        // by just checking to see if we are at these indexes:
        // if so, we just set the number in question to 0.

        string s = to_string(n);

        long sum = 0;
        // Magnitude (1, 10, 100...)
        long mag = 1;

        for(int i = 0; i < s.size(); i++){

            // Number before current digit
            long number = 0;
            string sub = s.substr(0, s.size() - i - 1);
            // The special case where we are at the unit digit
            // and there are no numbers after it is handled here.
            if(sub.size() > 0){
                number = stoi(sub);
            }

            // Current digit
            char c = s[s.size() - 1 -i];

            // If larger than 1
            if(c > '1'){
                sum += mag * (number+1);
            }
            // If 0
            else if (c < '1'){
                sum += mag * number;
            }
            // If 1
            else{
                // Number after the current digit
                long number2 = 0;
                string sub2 = s.substr(s.size() - i);
                // The special case where we are at the unit digit
                // and there are no numbers after it is handled
                // here.
                if(sub2.size() > 0){
                    number2 = stoi(sub2);
                }

                sum += mag * number + number2 + 1;
            }

            // Magnitude increased each iteration
            mag *= 10;
        }

        // Note that this method is generalizable for counting any
        // digit (where we only need to change the '1' character
        // in the code to anotehr digit), and also any number system
        // (where we just change how much the magnitude is changed
        // each ietration. For example, in base 4, the magnitude is
        // 1, 4, 16, 64...).

        return sum;
    }
};