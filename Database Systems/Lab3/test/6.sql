SELECT DISTINCT nation.n_name
FROM nation
INNER JOIN customer ON customer.c_nationkey = nation.n_nationkey
INNER JOIN orders ON orders.o_custkey = customer.c_custkey
WHERE orders.o_orderdate BETWEEN "1994-09-09" AND "1994-09-11"
ORDER BY nation.n_name;