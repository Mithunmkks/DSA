# Write your MySQL query statement below
with cte as (
select * , sum(weight) over(order by turn) as rs 
from Queue
),
cte2 as (
select * , lead(rs) over() as nw 
from cte )
select person_name 
from cte2
where rs<=1000 and (nw > 1000 OR nw IS NULL);