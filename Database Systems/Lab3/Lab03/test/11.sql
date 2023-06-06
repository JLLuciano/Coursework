SELECT COUNT( DISTINCT customer.c_custkey)
FROM customer
JOIN orders ON customer.c_custkey = orders.o_custkey
JOIN lineitem ON orders.o_orderkey = lineitem.l_orderkey
WHERE lineitem.l_discount >= 0.07;