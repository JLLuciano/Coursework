SELECT strftime("%Y", orders.o_orderdate), COUNT(lineitem.l_quantity)
FROM orders
INNER JOIN lineitem ON lineitem.l_orderkey = orders.o_orderkey
INNER JOIN supplier ON supplier.s_suppkey = lineitem.l_suppkey
INNER JOIN nation ON nation.n_nationkey = supplier.s_nationkey
WHERE (nation.n_name = 'FRANCE' 
OR nation.n_name = 'GERMANY')
AND orders.o_orderpriority = '3-MEDIUM'
GROUP BY strftime("%Y", orders.o_orderdate);