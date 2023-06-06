SELECT strftime("%m",l_shipdate) AS month, sum (l_quantity)
FROM lineitem
WHERE strftime("%Y",l_shipdate) = "1995"
GROUP BY month;