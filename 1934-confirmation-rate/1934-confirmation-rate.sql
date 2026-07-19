# Write your MySQL query statement below
select
    s.user_id,
    ROUND(IFNULL(SUM(c.action='confirmed')/COUNT(c.user_id),0),2) as confirmation_rate
from Signups s LEFT JOIN Confirmations c
on s.user_id=c.user_id
group by s.user_id;
