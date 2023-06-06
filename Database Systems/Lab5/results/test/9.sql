SELECT COUNT(DISTINCT orders.o_clerk)
FROM orders
INNER JOIN lineitem ON lineitem.l_orderkey = orders.o_orderkey
INNER JOIN supplier ON supplier.s_suppkey = lineitem.l_suppkey
INNER JOIN nation ON nation.n_nationkey = supplier.s_nationkey
WHERE nation.n_name = 'UNITED STATES';