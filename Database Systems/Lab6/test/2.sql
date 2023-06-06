SELECT COUNT(c_custkey)
FROM( SELECT c_custkey, COUNT(c_custkey) AS cnt
FROM customer, orders
WHERE customer.c_custkey = orders.o_custkey
AND strftime("%Y-%m", o_orderdate) = "1995-11"
GROUP BY c_custkey
HAVING cnt >= 3);