SELECT COUNT(s_suppkey)
FROM(SELECT s_suppkey, COUNT(DISTINCT l_orderkey) AS cnt 
FROM supplier, orders, nation, customer, lineitem
WHERE supplier.s_suppkey = lineitem.l_suppkey
AND lineitem.l_orderkey = orders.o_orderkey
AND nation.n_nationkey = customer.c_nationkey
AND customer.c_custkey = orders.o_custkey
AND (n_name = "GERMANY"
OR n_name = "FRANCE")
GROUP BY s_suppkey
HAVING cnt < 50);