SELECT n_name
FROM(SELECT n_name, COUNT(o_totalprice) AS lowest
FROM nation, customer, orders
WHERE customer.c_nationkey = nation.n_nationkey
AND customer.c_custkey = orders.o_custkey
GROUP BY n_name
ORDER BY lowest
LIMIT 1
);