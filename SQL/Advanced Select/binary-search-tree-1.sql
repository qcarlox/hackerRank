#https://www.hackerrank.com/challenges/binary-search-tree-1
select n,case   when root = 1 then "Root"
                when parent = 1 && root = 0 then "Inner"
                when parent = 0 then "Leaf" end from 
(select n,p,if(n in (select p from bst),1,0) as parent, if(p is null,1,0) as root from bst) as temp
order by n