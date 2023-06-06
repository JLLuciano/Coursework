SELECT COUNT(DISTINCT s_name)
FROM supplier, partsupp, part
WHERE supplier.s_suppkey = partsupp.ps_suppkey
AND partsupp.ps_partkey = part.p_partkey
AND p_type LIKE '%POLISHED%'
AND (p_size = 3
OR p_size = 23
OR p_size = 36
OR p_size = 49);