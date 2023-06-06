SELECT n_name, COUNT(c_custkey)
FROM customer, nation, orders, region
WHERE customer.c_nationkey = nation.n_nationkey
AND customer.c_custkey = orders.o_custkey
AND region.r_regionkey = nation.n_regionkey
AND region.r_name = 'AMERICA'
GROUP BY n_name;