SELECT s_region, c_region, strftime('%Y', l_shipdate), SUM(l_extendedprice * (1 - l_discount))
FROM
(SELECT *, region.r_name AS s_region
FROM supplier
INNER JOIN nation ON nation.n_nationkey = supplier.s_nationkey
INNER JOIN region ON region.r_regionkey = nation.n_regionkey
INNER JOIN lineitem ON lineitem.l_suppkey = supplier.s_suppkey
),
(SELECT *, region.r_name AS c_region 
FROM customer
INNER JOIN nation ON nation.n_nationkey = customer.c_nationkey
INNER JOIN region ON region.r_regionkey = nation.n_regionkey
INNER JOIN orders ON orders.o_custkey = customer.c_custkey)
WHERE l_orderkey = o_orderkey
AND (l_shipdate BETWEEN '1996-01-01' AND '1997-12-31')
GROUP BY s_region, c_region,strftime('%Y', l_shipdate);