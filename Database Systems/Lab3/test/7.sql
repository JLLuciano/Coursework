SELECT strftime("%Y-%m", l_receiptdate), count(lineitem.l_commitdate)
FROM lineitem
INNER JOIN orders ON orders.o_orderkey = lineitem.l_orderkey
INNER JOIN customer ON customer.c_custkey = orders.o_custkey 
WHERE customer.c_custkey = '20'
GROUP BY strftime("%Y-%m", l_receiptdate);