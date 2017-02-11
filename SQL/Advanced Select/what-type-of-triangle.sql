#https://www.hackerrank.com/challenges/what-type-of-triangle
SELECT IF(A+B>C && A+C>B && C+B>A,IF(A=B && B=C,"Equilateral",IF(A=B || B=C || C=A,"Isosceles","Scalene")),"Not A Triangle") FROM TRIANGLES