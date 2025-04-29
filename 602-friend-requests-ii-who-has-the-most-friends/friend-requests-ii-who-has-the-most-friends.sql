# Write your MySQL query statement below

with cte as (
select requester_id as id , count(requester_id) as num 
from RequestAccepted 
group by 1
union all
select accepter_id as id , count(accepter_id) as num 
from RequestAccepted 
group by 1
)
select id , sum(num) as num 
from cte 
group by 1 
order by num desc
limit 1;
