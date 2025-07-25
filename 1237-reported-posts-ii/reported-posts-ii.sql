with cte as(select action_date ,
count(distinct b.post_id )/count(distinct a.post_id)rnk
from actions a 
left join removals b using(post_id ) where action='report' and extra='spam' group by 1)
select round(100*avg(rnk),2)average_daily_percent
from cte