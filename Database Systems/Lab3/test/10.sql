SELECT SUM(orders.o_totalprice)
FROM orders
INNER JOIN customer ON customer.c_custkey = orders.o_custkey
INNER JOIN nation ON nation.n_nationkey = customer.c_nationkey
INNER JOIN region ON region.r_regionkey = nation.n_regionkey
WHERE strftime('%Y', orders.o_orderdate) = '1997' AND region.r_name = 'ASIA';