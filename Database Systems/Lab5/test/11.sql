SELECT p_name
FROM(SELECT p_name, MIN(l_extendedprice*(1-l_discount))
FROM lineitem, part
WHERE lineitem.l_partkey = part.p_partkey
AND l_shipdate > '1996-10-02'
);