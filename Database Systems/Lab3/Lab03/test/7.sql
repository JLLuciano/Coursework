SELECT strftime("%Y-%m", l_receiptdate), count(lineitem.l_receiptdate)
FROM lineitem
INNER JOIN orders ON lineitem.l_orderkey = orders.o_orderkey
INNER JOIN customer ON customer.c_custkey = orders.o_custkey
WHERE customer.c_name = "Customer#000000020"
GROUP BY strftime("%Y-%m", l_receiptdate);