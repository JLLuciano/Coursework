SELECT COUNT(s_suppkey)
FROM(SELECT s_suppkey, COUNT(DISTINCT p_partkey) AS cnt
FROM supplier, part, nation, partsupp
WHERE supplier.s_suppkey = partsupp.ps_suppkey
AND partsupp.ps_partkey = part.p_partkey
AND nation.n_nationkey = supplier.s_nationkey
AND n_name = "UNITED STATES"
GROUP BY s_suppkey
HAVING cnt > 40
);