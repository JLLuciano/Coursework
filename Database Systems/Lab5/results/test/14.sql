SELECT s_region, c_region, MAX(o_totalprice)
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
GROUP BY s_region, c_region;