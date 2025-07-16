-- -- # Write your MySQL query statement below
-- -- with cte as (
-- -- select * , sum(frequency) over (order by num) rs,
-- -- sum(frequency) over() cnt
-- -- from Numbers
-- -- ), cte2 as (
-- --     select *,lag(rs) over() as prs
-- --     from cte
-- -- )
-- -- select num as median from cte2
-- -- where (cnt%2=0 and (rs>cnt div 2 and COALESCE(prs, 0) < cnt div 2)) or (cnt%2=0 and (rs>(cnt div (2+1)) and COALESCE(prs, 0) < (cnt div (2+1)))) or (cnt%2=1 and (rs>(cnt div (2+1)) and COALESCE(prs, 0) < (cnt div (2+1))));

-- with cte1 as (
-- select *,  sum(frequency) over(order by num) as cum_sum
-- from numbers),

-- cte2 as (
--     select row_number() over() as rn
--     from cte1 a join cte1 b on 1=1
-- ),

-- cte3 as (select a.num, row_number() over() as frn,
-- count(a.frequency) over() as fcs
-- from cte2 b
-- join cte1 a 
-- on b.rn<= a.cum_sum and b.rn >a.cum_sum - a.frequency
-- order by b.rn)

-- select * from cte3
-- -- where frn= fcs/2 or frn = fcs/2+1 or frn = (fcs+1)/2

with cte as(
    select num,frequency ,
    sum(frequency ) over(order by num ) fr,
    sum(frequency ) over(order by num desc)lr
    from Numbers 
)


select avg(num)*1.0 as median
from cte
where abs(fr-lr)<=frequency