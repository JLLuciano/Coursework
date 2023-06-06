SELECT COUNT(DISTINCT s_suppkey)
FROM part,partsupp, supplier
WHERE part.p_partkey = partsupp.ps_partkey
AND supplier.s_suppkey = partsupp.ps_suppkey
AND p_retailprice = (SELECT MAX(p_retailprice) FROM part);