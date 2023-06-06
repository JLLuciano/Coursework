SELECT COUNT(DISTINCT customer.c_custkey)
FROM customer
INNER JOIN orders ON orders.o_custkey = customer.c_custkey
INNER JOIN lineitem ON lineitem.l_orderkey = orders.o_orderkey
WHERE l_discount >= 0.07;