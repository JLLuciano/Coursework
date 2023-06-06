SELECT supplier.s_name, supplier.s_acctbal
FROM supplier
INNER JOIN nation ON nation.n_nationkey = supplier.s_nationkey
INNER JOIN region ON region.r_regionkey = nation.n_regionkey
WHERE supplier.s_acctbal > 7000 AND region.r_name = 'EUROPE';