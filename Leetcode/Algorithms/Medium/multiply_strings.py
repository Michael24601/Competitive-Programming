# 
#    Website: Leetcode
#    Difficulty: Medium
#    Language: python
#    Link: https://leetcode.com/problems/multiply-strings/
#

class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        n1 = int(num1)
        n2 = int(num2)
        n = n1 * n2
        return str(n)