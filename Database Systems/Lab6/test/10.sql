SELECT r_name
FROM(SELECT r_name, SUM(l_extendedprice) AS spend
FROM region, nation, customer,supplier, lineitem, orders
WHERE supplier.s_nationkey = nation.n_nationkey
AND nation.n_regionkey = region.r_regionkey
AND customer.c_nationkey = supplier.s_nationkey
AND lineitem.l_orderkey = orders.o_orderkey
AND supplier.s_suppkey = lineitem.l_suppkey
AND customer.c_custkey = orders.o_custkey
GROUP BY r_name
ORDER BY spend
LIMIT 1);

