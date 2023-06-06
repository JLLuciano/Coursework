SELECT nation.n_name, COUNT(DISTINCT orders.o_orderkey) as cnt--lineitem.l_orderkey works
FROM supplier
INNER JOIN nation ON nation.n_nationkey = supplier.s_nationkey
INNER JOIN lineitem ON lineitem.l_suppkey = supplier.s_suppkey
INNER JOIN orders ON orders.o_orderkey = lineitem.l_orderkey
WHERE orders.o_orderstatus = 'F'
AND (orders.o_orderdate BETWEEN '1995-01-01' AND '1995-12-31')
GROUP BY nation.n_name
HAVING cnt > 50;