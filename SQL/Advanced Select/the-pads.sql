#https://www.hackerrank.com/challenges/the-pads
SELECT CONCAT(NAME,"(",LEFT(OCCUPATION,1),")") FROM OCCUPATIONS ORDER BY NAME;
SELECT CONCAT("There are total ",COUNT(*)," ", LOWER(OCCUPATION),"s.") FROM OCCUPATIONS GROUP BY OCCUPATION ORDER BY COUNT(*), OCCUPATION;