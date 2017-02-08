#https://www.hackerrank.com/challenges/weather-observation-station-10
SELECT DISTINCT CITY FROM STATION WHERE RIGHT(LOWER(CITY),1) NOT IN ('a','e','i','o','u')