# Write your MySQL query statement below
select a.employee_id , a.name  , 
count(b.employee_id) as reports_count , 
round(avg(b.age),0) as average_age
from Employees as a 
join 
Employees as b 
on a.employee_id = b.reports_to 
group by 1,2 
order by 1,2;