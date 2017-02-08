#https://www.hackerrank.com/challenges/weather-observation-station-6
SELECT DISTINCT CITY FROM STATION WHERE LEFT(LOWER(CITY),1) IN ('a','e','i','o','u')