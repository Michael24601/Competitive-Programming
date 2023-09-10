/*
    Website: Hackerank
    Difficulty: Easy
    Type: Databases
    Language: sql
    Link: https://www.hackerrank.com/challenges/earnings-of-employees/problem
*/


SELECT SALARY * MONTHS, COUNT(NAME)
FROM EMPLOYEE WHERE SALARY * MONTHS =
    (SELECT MAX(SALARY*MONTHS)
    FROM EMPLOYEE)
GROUP BY (SALARY*MONTHS);