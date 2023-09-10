/*
    Website: Hackerank
    Difficulty: Easy
    Type: Databases
    Language: sql
    Link: https://www.hackerrank.com/challenges/weather-observation-station-5/problem
*/


(SELECT CITY, LENGTH(CITY) 
FROM STATION 
ORDER BY LENGTH(CITY) ASC, CITY ASC 
LIMIT 1)
UNION
(SELECT CITY, LENGTH(CITY)
FROM STATION 
ORDER BY LENGTH(CITY) DESC, CITY ASC 
LIMIT 1);