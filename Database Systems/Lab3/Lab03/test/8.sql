SELECT s_name, s_acctbal
FROM supplier
JOIN nation ON supplier.s_nationkey = nation.n_nationkey
JOIN region ON nation.n_regionkey = region.r_regionkey
WHERE r_name = "EUROPE" AND s_acctbal > 7000;