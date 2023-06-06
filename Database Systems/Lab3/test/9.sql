SELECT nation.n_name, COUNT(supplier.s_nationkey) AS num, MIN(supplier.s_acctbal)
FROM supplier
INNER JOIN nation ON nation.n_nationkey = supplier.s_nationkey
GROUP BY nation.n_name
HAVING num > 5;