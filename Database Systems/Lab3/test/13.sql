SELECT SUM(customer.c_acctbal)
FROM customer
INNER JOIN nation ON nation.n_nationkey = customer.c_nationkey
INNER JOIN region ON  region.r_regionkey = nation.n_regionkey
WHERE region.r_name = 'ASIA' AND customer.c_mktsegment = 'MACHINERY';