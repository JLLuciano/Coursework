SELECT nation.n_name, COUNT(supplier.s_nationkey) AS nationkey, MIN(supplier.s_acctbal)
FROM nation, supplier
WHERE supplier.s_nationkey = nation.n_nationkey
GROUP BY nation.n_name
HAVING nationkey > 5;