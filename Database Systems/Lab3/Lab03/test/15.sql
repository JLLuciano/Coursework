SELECT strftime('%Y',orders.o_orderdate), COUNT(lineitem.l_quantity)
FROM lineitem
JOIN supplier ON lineitem.l_suppkey = supplier.s_suppkey
JOIN nation ON supplier.s_nationkey = nation.n_nationkey
JOIN orders ON lineitem.l_orderkey = orders.o_orderkey
WHERE (nation.n_name = 'GERMANY' OR nation.n_name = 'FRANCE') AND orders.o_orderpriority = '3-MEDIUM'
GROUP BY strftime('%Y',orders.o_orderdate);