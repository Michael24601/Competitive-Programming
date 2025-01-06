#
#    Website: Leetcode
#    Difficulty: Medium
#    Language: python
#    Link: https://leetcode.com/problems/unique-paths/
#


class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """

        """
        Given an m by n grid where m is the number of rows,
        the robot will always go down m-1 times, and right n-1
        times.
        So the number of unique paths essentially asks how
        many unique permuations there are of a string
        with m-1 D and n-1 R characters.
        This is given by (m + n - 2)! / (n-1)!(m-1)!
        The issue is that calculating (m + n - 2)!
        takes too much space, same for (n-1)!(m-1)!
        So we use python instead of c++
        """
        
        return math.factorial(m + n - 2) // (math.factorial(m - 1) * math.factorial(n - 1))


        