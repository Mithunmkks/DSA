# Write your MySQL query statement below
with cte as (
select customer_id , case when order_date = customer_pref_delivery_date then  1
else 0 end as choice 
from Delivery
where (customer_id,order_date) in (
    select customer_id , min(order_date) 
    from Delivery 
    group by 1 
)
)
select round(sum(choice)/count(*)*100,2) as immediate_percentage
from cte
