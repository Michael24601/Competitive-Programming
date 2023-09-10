/*
    Website: Hackerank
    Difficulty: Easy
    Type: Databases
    Language: sql
    Link: https://www.hackerrank.com/challenges/weather-observation-station-3/problem
*/


SELECT DISTINCT CITY
FROM STATION
WHERE MOD(ID, 2) = 0;