# Write your MySQL query statement below
with cte as (
select *,
id - row_number() over(order by visit_date ) as diff 
from Stadium
where people>=100
),
 cte2 as (
select id,visit_date,people,diff,
count(diff) over(partition by diff)  as cnt
from cte ) 
select id,visit_date,people from cte2 where cnt>=3
order by id

