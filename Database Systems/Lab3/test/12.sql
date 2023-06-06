SELECT region.r_name, COUNT(orders.o_orderstatus)
FROM orders
INNER JOIN customer ON customer.c_custkey = orders.o_custkey
INNER JOIN nation ON nation.n_nationkey = customer.c_nationkey
INNER JOIN region ON region.r_regionkey = nation.n_regionkey
WHERE orders.o_orderstatus = 'P'
GROUP BY region.r_name;