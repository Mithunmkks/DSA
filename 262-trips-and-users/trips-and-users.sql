with cte as 
(
    select *,
    case when status='completed'
    then 0 
    else 1 
    end as succes_trips
    from Trips
    where 
    client_id not 
in (select users_id from Users where banned='Yes') and 
driver_id not 
in (select users_id from Users where banned='Yes')
and Request_at between '2013-10-01' and '2013-10-03'
)

select  request_at as 'Day' , 
round(sum(succes_trips)*1.0/count(id),2) as 'Cancellation Rate'
from cte 
group by 1 ;