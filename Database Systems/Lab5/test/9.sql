SELECT partname
FROM (SELECT p_name AS partname
FROM partsupp, supplier, part, nation 
WHERE partsupp.ps_partkey = part.p_partkey
AND supplier.s_suppkey = partsupp.ps_suppkey
AND supplier.s_nationkey = nation.n_nationkey
AND n_name = 'UNITED STATES'
ORDER BY (ps_supplycost * ps_availqty) DESC
LIMIT(SELECT COUNT(DISTINCT ps_partkey)/100
FROM partsupp, supplier, part, nation 
WHERE partsupp.ps_partkey = part.p_partkey
AND supplier.s_suppkey = partsupp.ps_suppkey
AND supplier.s_nationkey = nation.n_nationkey
AND n_name = 'UNITED STATES'));
