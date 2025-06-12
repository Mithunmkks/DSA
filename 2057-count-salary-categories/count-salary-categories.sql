# Write your MySQL query statement below
with cte as (
    select * , case when income < 20000 then "Low Salary"
                    when income >=2000 and income <= 50000 then "Average Salary"
                    else "High Salary" end as category
    from Accounts
),
cte1 as (
    select category,count(*)  as ca
    from cte 
    group by 1 
),
cte2 (category) AS (
    SELECT 'Low Salary' AS category
    UNION ALL
    SELECT 'Average Salary'
    UNION ALL
    SELECT 'High Salary'
)
SELECT a.category   , coalesce(b.ca,0) as accounts_count
from cte2 as a 
left join 
cte1 as b 
on a.category=b.category;


