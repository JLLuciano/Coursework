SELECT supplier.s_name, orders.o_orderpriority, COUNT(DISTINCT part.p_partkey)
FROM supplier
INNER JOIN lineitem ON lineitem.l_suppkey = supplier.s_suppkey
INNER JOIN part ON part.p_partkey = lineitem.l_partkey
INNER JOIN nation ON nation.n_nationkey = supplier.s_nationkey
INNER JOIN orders ON orders.o_orderkey = lineitem.l_orderkey
WHERE nation.n_name = 'CANADA'
GROUP BY supplier.s_name, orders.o_orderpriority;