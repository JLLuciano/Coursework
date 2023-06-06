SELECT s_name, p_size, MIN(ps_supplycost)
FROM supplier, part, partsupp, nation, region
WHERE supplier.s_suppkey = partsupp.ps_suppkey
AND partsupp.ps_partkey = part.p_partkey
AND supplier.s_nationkey = nation.n_nationkey
AND region.r_regionkey = nation.n_regionkey
AND r_name = 'ASIA'
AND p_type LIKE '%%STEEL'
GROUP BY p_size;