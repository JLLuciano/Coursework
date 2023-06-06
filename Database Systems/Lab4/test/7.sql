SELECT nation.n_name, orders.o_orderstatus, COUNT(orders.o_custkey)
FROM nation
INNER JOIN customer ON customer.c_nationkey = nation.n_nationkey
INNER JOIN orders ON orders.o_custkey = customer.c_custkey
INNER JOIN region ON region.r_regionkey = nation.n_regionkey
WHERE region.r_name = 'AMERICA'
GROUP BY nation.n_name, orders.o_orderstatus;