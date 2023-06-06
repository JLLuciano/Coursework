SELECT COUNT(DISTINCT o_orderkey)
FROM
(SELECT *, customer.c_acctbal AS c_bal
FROM customer
INNER JOIN orders ON orders.o_custkey = customer.c_custkey
),
(SELECT *, supplier.s_acctbal AS s_bal
FROM supplier
INNER JOIN lineitem ON lineitem.l_suppkey = supplier.s_suppkey
)
WHERE l_orderkey = o_orderkey AND s_bal < 0 AND c_bal > 0;