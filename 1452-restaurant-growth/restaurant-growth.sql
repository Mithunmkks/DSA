# Write your MySQL query statement below

with cte as (
    select
    row_number() over(order by visited_on) as rk ,
    visited_on , sum(amount)  as amount
    from Customer 
    group by 2 
    
),
cte2 as (
select rk,visited_on , 
    sum(amount) over(order by visited_on rows between 6 preceding and current row )  as amount,
    round(avg(amount) over(order by visited_on rows between 6 preceding and current row ),2 )
    as average_amount 
    from cte 
)
select visited_on , amount,average_amount from cte2 where rk>6;
    
