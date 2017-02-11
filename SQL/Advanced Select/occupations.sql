#https://www.hackerrank.com/challenges/occupations
set @num := 0;
set @type := '';
select min(doctor), min(professor), min(singer), min(actor) from
(select case when occupation = "Doctor" then name end as doctor,
        case when occupation = "Professor" then name end as professor,
        case when occupation = "Singer" then name end as singer,
        case when occupation = "Actor" then name end as actor,
if(@type=occupation,@num:=@num+1,@num:=1) as rowNumber,
@type:=occupation as type
from occupations order by occupation,name) 
as temp group by rowNumber