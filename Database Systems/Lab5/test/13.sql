SELECT o_orderpriority, COUNT(DISTINCT o_orderkey)
FROM orders, lineitem
WHERE orders.o_orderkey = lineitem.l_orderkey
AND (o_orderdate BETWEEN '1997-10-01' AND '1997-12-31')
AND l_receiptdate < l_commitdate
GROUP BY o_orderpriority;