SELECT us_revenue/asia_revenue
FROM (SELECT SUM(l_extendedprice * (1 - l_discount)) AS us_revenue
FROM nation n1, nation n2, region, customer, lineitem, orders, supplier
WHERE n1.n_nationkey = customer.c_nationkey
AND n1.n_regionkey = region.r_regionkey
AND n2.n_nationkey = supplier.s_nationkey
AND customer.c_custkey = orders.o_custkey
AND lineitem.l_orderkey = orders.o_orderkey
AND lineitem.l_suppkey = supplier.s_suppkey
AND (l_shipdate BETWEEN '1997-01-01' AND '1997-12-31')
AND n2.n_name = 'UNITED STATES'
AND r_name = 'ASIA'),
(SELECT SUM(l_extendedprice * (1 - l_discount)) AS asia_revenue
FROM nation, region, customer,lineitem, orders, supplier
WHERE nation.n_nationkey = customer.c_nationkey
AND nation.n_regionkey = region.r_regionkey
AND customer.c_custkey = orders.o_custkey
AND lineitem.l_orderkey = orders.o_orderkey
AND lineitem.l_suppkey = supplier.s_suppkey
AND (l_shipdate BETWEEN '1997-01-01' AND '1997-12-31')
AND r_name = 'ASIA');