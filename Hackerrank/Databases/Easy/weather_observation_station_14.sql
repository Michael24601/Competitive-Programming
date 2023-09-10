/*
    Website: Hackerank
    Difficulty: Easy
    Type: Databases
    Language: sql
    Link: https://www.hackerrank.com/challenges/weather-observation-station-14/problem
*/


SELECT MAX(ROUND(LAT_N, 4)) FROM STATION
WHERE LAT_N < 137.2345;