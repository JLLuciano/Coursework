SELECT SUM(ps_supplycost)
FROM partsupp, part,lineitem
WHERE partsupp.ps_partkey = part.p_partkey
AND lineitem.l_partkey = partsupp.ps_partkey
AND ps_suppkey NOT IN (SELECT l_suppkey FROM lineitem,partsupp,part
WHERE lineitem.l_suppkey = partsupp.ps_suppkey
AND part.p_partkey = partsupp.ps_partkey
AND l_extendedprice < 2000
AND (l_shipdate BETWEEN '1996-01-01' AND '1996-12-31'))
AND (l_shipdate BETWEEN '1997-01-01' AND '1997-12-31')
AND p_retailprice < 1000;