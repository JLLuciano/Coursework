SELECT MIN(cmpr_dis)
FROM
(SELECT AVG(l_discount) AS avg_dis, o_orderdate AS avg_date
FROM orders, lineitem
WHERE orders.o_orderkey = lineitem.l_orderkey
AND (o_orderdate BETWEEN '1996-01-10' AND '1996-31-10')),
(SELECT o_orderdate, l_discount AS cmpr_dis
FROM orders, lineitem
WHERE orders.o_orderkey = lineitem.l_orderkey
AND (o_orderdate BETWEEN '1996-01-10' AND '1996-31-10')
GROUP BY cmpr_dis)
WHERE cmpr_dis > avg_dis;