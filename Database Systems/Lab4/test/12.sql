SELECT nation.n_name, MAX(supplier.s_acctbal) AS bal
FROM supplier
INNER JOIN nation ON nation.n_nationkey = supplier.s_nationkey
GROUP BY nation.n_name
HAVING bal > 9000;