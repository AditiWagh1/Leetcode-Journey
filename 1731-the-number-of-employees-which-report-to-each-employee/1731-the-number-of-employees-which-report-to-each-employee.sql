# Write your MySQL query statement below
select 
    mgr.employee_id,
    mgr.name,
    COUNT(emp.employee_id) as reports_count,
    ROUND(AVG(emp.age)) as average_age
from Employees mgr
join Employees emp on mgr.employee_id=emp.reports_to
group by mgr.employee_id,mgr.name 
order by mgr.employee_id;