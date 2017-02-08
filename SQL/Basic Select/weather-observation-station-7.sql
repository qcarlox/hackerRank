#https://www.hackerrank.com/challenges/weather-observation-station-7
SELECT DISTINCT CITY FROM STATION WHERE RIGHT(LOWER(CITY),1) IN ('a','e','i','o','u')
