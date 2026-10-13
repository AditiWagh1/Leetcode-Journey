# Write your MySQL query statement below
WITH DailyTotals AS (
    SELECT 
        visited_on,
        SUM(amount) AS daily_amount
    FROM Customer
    GROUP BY visited_on
)
SELECT 
    a.visited_on,
    SUM(b.daily_amount) AS amount,
    ROUND(SUM(b.daily_amount) / 7.0, 2) AS average_amount
FROM DailyTotals a
JOIN DailyTotals b 
  ON DATEDIFF(a.visited_on, b.visited_on) BETWEEN 0 AND 6
GROUP BY a.visited_on
HAVING COUNT(b.visited_on) = 7
ORDER BY a.visited_on ASC;