/*
    Website: IEEEXtreme
    Difficulty: Easy
    Language: java
    Link: https://csacademy.com/ieeextreme-practice/task/96c8b1313edd72abf600facb0a14dbab/
*/


package Easy;

import java.util.*;
import java.math.BigInteger;

// This is a trick question.
// While the naive approach would be to use combinations
// or permutations, these either take too long or, in the
// case of gactorial memoization, too much space. 
// In reality, the answer to the question is none other than
// the nth fibonacci number. 
// We use Java for the added capability of dealing with very
// large numbers.

public class running_up_stairs {
    
    // Calculate Fibonacci using BigInteger
    static BigInteger fibonacci(int n) {
        if (n <= 0) {
            return BigInteger.ZERO;
        } else if (n == 1) {
            return BigInteger.ONE;
        } else if (n == 2) {
            return BigInteger.valueOf(2);
        }

        BigInteger val1 = BigInteger.valueOf(1);
        BigInteger val2 = BigInteger.valueOf(0);

        for (int i = 1; i <= n; i++) {
            BigInteger val = val1.add(val2);
            val2 = val1;
            val1 = val;
        }

        return val1;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int t = in.nextInt();
        while (t-- > 0) {
            int n = in.nextInt();
            System.out.println(fibonacci(n));
        }
    }
}