SELECT COUNT(l_orderkey) --lineitem.l_orderkey wouldnt work
FROM (SELECT *
FROM supplier
INNER JOIN lineitem ON lineitem.l_suppkey = supplier.s_suppkey
INNER JOIN nation ON nation.n_nationkey = supplier.s_nationkey
INNER JOIN region ON region.r_regionkey = nation.n_regionkey
WHERE region.r_name = 'AFRICA'
),
(SELECT *
FROM customer
INNER JOIN orders ON orders.o_custkey = customer.c_custkey
INNER JOIN nation ON nation.n_nationkey = customer.c_nationkey
WHERE nation.n_name = 'UNITED STATES')
WHERE l_orderkey = o_orderkey;