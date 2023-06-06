SELECT COUNT(p_partkey)
FROM(SELECT p_partkey, COUNT(DISTINCT s_suppkey) AS cnt
FROM supplier, part, nation, partsupp
WHERE supplier.s_suppkey = partsupp.ps_suppkey
AND partsupp.ps_partkey = part.p_partkey
AND nation.n_nationkey = supplier.s_nationkey
AND n_name = "UNITED STATES"
GROUP BY p_partkey
HAVING cnt = 2
);