# Write your MySQL query statement below
select distinct num as ConsecutiveNums
from(
    select num,
        LEAD(num,1) over (order by id) as next1,
        LEAD(num,2) over (order by id) as next2
    from Logs
) as subquery
where num=next1 and num=next2;