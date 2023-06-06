SELECT COUNT(DISTINCT o_custkey)
FROM customer, orders
WHERE customer.c_custkey = orders.o_custkey
AND o_orderkey NOT IN (SELECT DISTINCT o_orderkey FROM orders,supplier,nation,region,lineitem
WHERE orders.o_orderkey = lineitem.l_orderkey
AND supplier.s_suppkey = lineitem.l_suppkey
AND supplier.s_nationkey = nation.n_nationkey
AND nation.n_regionkey = region.r_regionkey
AND r_name NOT IN ("AMERICA"));