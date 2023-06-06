SELECT Manufacturer
FROM
(SELECT p_mfgr AS Manufacturer, MIN(ps_availqty) 
FROM part, supplier, partsupp
WHERE part.p_partkey = partsupp.ps_partkey
AND partsupp.ps_suppkey = supplier.s_suppkey
AND s_suppkey = 10);