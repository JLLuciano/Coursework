SELECT SUM(orders.o_totalprice)
FROM orders
JOIN customer ON orders.o_custkey = customer.c_custkey
JOIN nation ON customer.c_nationkey = nation.n_nationkey
JOIN region ON nation.n_regionkey = region.r_regionkey
WHERE region.r_name="ASIA" AND (orders.o_orderdate BETWEEN "1997-01-01" AND "1997-12-31");
