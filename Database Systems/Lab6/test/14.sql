SELECT cust_loc.n_name, (total - total2)
FROM(SELECT n_name, COUNT(l_quantity) AS total
FROM nation, supplier, lineitem, customer, orders
WHERE nation.n_nationkey = supplier.s_nationkey
AND nation.n_nationkey != customer.c_nationkey
AND lineitem.l_orderkey = orders.o_orderkey
AND lineitem.l_suppkey = supplier.s_suppkey
AND customer.c_custkey = orders.o_custkey
AND (l_shipdate BETWEEN '1994-01-01' AND '1994-12-31')
GROUP BY n_name) AS cust_for,
(SELECT n_name, COUNT(l_quantity) AS total2
FROM nation, supplier, lineitem, customer, orders
WHERE nation.n_nationkey != supplier.s_nationkey
AND nation.n_nationkey = customer.c_nationkey
AND lineitem.l_orderkey = orders.o_orderkey
AND lineitem.l_suppkey = supplier.s_suppkey
AND customer.c_custkey = orders.o_custkey
AND (l_shipdate BETWEEN '1994-01-01' AND '1994-12-31')
GROUP BY n_name) AS cust_loc
WHERE cust_loc.n_name = cust_for.n_name;