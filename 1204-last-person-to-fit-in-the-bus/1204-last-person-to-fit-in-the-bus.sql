# Write your MySQL query statement below
select person_name
from(
    select person_name,
    SUM(weight) over (order by turn) as cumulative_weight
    from Queue
) as subquery
where cumulative_weight<=1000
order by cumulative_weight DESC
limit 1;