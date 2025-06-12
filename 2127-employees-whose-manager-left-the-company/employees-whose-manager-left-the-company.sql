# Write your MySQL query statement below

-- select employee_id 
-- from Employees 
-- where salary < 30000 and  manager_id is null or manager_id not in (select employee_id from Employees);


-- cte filtering out only employees whose salary is less than 30k

with employee as (
    select * 
    from Employees 
    where salary < 30000
)
select employee_id 
from employee
where manager_id not in (select employee_id from employees)
order by 1;