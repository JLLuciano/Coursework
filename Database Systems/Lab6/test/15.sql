SELECT DISTINCT cust_loc.n_name,
    CASE 
        WHEN STRFTIME('%Y', dates) BETWEEN '1994' AND '1995'
            THEN (final - final2)
            END,
    CASE
        WHEN STRFTIME('%Y', dates) BETWEEN '1995' AND '1996'
            THEN (final2 - final3)
            END
FROM(SELECT cust_for, (total - total2) AS final
FROM(SELECT n_name AS cust_for COUNT(l_quantity) AS total, l_shipdate AS dates
FROM nation, supplier, lineitem, customer, orders
WHERE nation.n_nationkey = supplier.s_nationkey
AND nation.n_nationkey != customer.c_nationkey
AND lineitem.l_orderkey = orders.o_orderkey
AND lineitem.l_suppkey = supplier.s_suppkey
AND customer.c_custkey = orders.o_custkey
AND (l_shipdate BETWEEN '1994-01-01' AND '1994-12-31')
GROUP BY n_name)
(SELECT n_name AS cust_loc, COUNT(l_quantity) AS total2
FROM nation, supplier, lineitem, customer, orders
WHERE nation.n_nationkey != supplier.s_nationkey
AND nation.n_nationkey = customer.c_nationkey
AND lineitem.l_orderkey = orders.o_orderkey
AND lineitem.l_suppkey = supplier.s_suppkey
AND customer.c_custkey = orders.o_custkey
AND (l_shipdate BETWEEN '1994-01-01' AND '1994-12-31')
GROUP BY n_name)
WHERE cust_loc = cust_for),
(SELECT cust_for2, (total - total2) AS final2
FROM(SELECT n_name AS cust_for2, COUNT(l_quantity) AS total
FROM nation, supplier, lineitem, customer, orders
WHERE nation.n_nationkey = supplier.s_nationkey
AND nation.n_nationkey != customer.c_nationkey
AND lineitem.l_orderkey = orders.o_orderkey
AND lineitem.l_suppkey = supplier.s_suppkey
AND customer.c_custkey = orders.o_custkey
AND (l_shipdate BETWEEN '1995-01-01' AND '1995-12-31')
GROUP BY n_name) 
(SELECT n_name AS cust_loc2, COUNT(l_quantity) AS total2
FROM nation, supplier, lineitem, customer, orders
WHERE nation.n_nationkey != supplier.s_nationkey
AND nation.n_nationkey = customer.c_nationkey
AND lineitem.l_orderkey = orders.o_orderkey
AND lineitem.l_suppkey = supplier.s_suppkey
AND customer.c_custkey = orders.o_custkey
AND (l_shipdate BETWEEN '1995-01-01' AND '1995-12-31')
GROUP BY n_name) 
WHERE cust_loc2 = cust_for2),
(SELECT cust_loc3, (total - total2) AS final3
FROM(SELECT n_name AS cust_for3, COUNT(l_quantity) AS total
FROM nation, supplier, lineitem, customer, orders
WHERE nation.n_nationkey = supplier.s_nationkey
AND nation.n_nationkey != customer.c_nationkey
AND lineitem.l_orderkey = orders.o_orderkey
AND lineitem.l_suppkey = supplier.s_suppkey
AND customer.c_custkey = orders.o_custkey
AND (l_shipdate BETWEEN '1996-01-01' AND '1996-12-31')
GROUP BY n_name)
(SELECT n_name AS cust_loc3, COUNT(l_quantity) AS total2
FROM nation, supplier, lineitem, customer, orders
WHERE nation.n_nationkey != supplier.s_nationkey
AND nation.n_nationkey = customer.c_nationkey
AND lineitem.l_orderkey = orders.o_orderkey
AND lineitem.l_suppkey = supplier.s_suppkey
AND customer.c_custkey = orders.o_custkey
AND (l_shipdate BETWEEN '1996-01-01' AND '1996-12-31')
GROUP BY n_name)
WHERE cust_loc3 = cust_for3)
WHERE cust_loc = cust_for2
AND cust_loc3 = cust_for2;
