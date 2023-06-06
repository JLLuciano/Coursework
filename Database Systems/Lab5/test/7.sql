SELECT OP,Parts
FROM 
(SELECT o_orderpriority AS OP, COUNT(p_partkey) AS Parts
FROM orders,part, lineitem
WHERE orders.o_orderkey = lineitem.l_orderkey
AND part.p_partkey = lineitem.l_partkey
AND (o_orderdate BETWEEN '1997-01-01' AND '1997-12-31')
AND l_receiptdate > l_commitdate
GROUP BY OP);