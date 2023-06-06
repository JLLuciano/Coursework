SELECT part.p_type, MIN(lineitem.l_discount), MAX(lineitem.l_discount)
FROM part 
INNER JOIN lineitem ON lineitem.l_partkey = part.p_partkey
WHERE part.p_type LIKE 'ECONOMY%COPPER'
GROUP BY part.p_type;