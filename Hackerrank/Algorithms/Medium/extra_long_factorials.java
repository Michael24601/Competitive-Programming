package Medium;
/*
    Website: Hackerank
    Difficulty: Medium
    Type: Algorithms
    Language: java
    Link: https://www.hackerrank.com/challenges/extra-long-factorials/problem
*/

import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

public class extra_long_factorials {
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
         BigInteger b = new BigInteger("1");
        for(int i = 2; i <= n; i++){
            b = b.multiply(BigInteger.valueOf(i));
        }
        System.out.print(b);
    }
}