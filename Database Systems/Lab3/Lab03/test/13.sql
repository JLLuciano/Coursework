SELECT SUM(customer.c_acctbal)
FROM customer
JOIN nation ON customer.c_nationkey = nation.n_nationkey
JOIN region ON nation.n_regionkey = region.r_regionkey
WHERE region.r_name = 'ASIA' AND customer.c_mktsegment = 'MACHINERY';