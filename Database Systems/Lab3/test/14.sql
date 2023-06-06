SELECT COUNT(orders.o_orderpriority)
FROM orders
INNER JOIN customer ON customer.c_custkey = orders.o_custkey
INNER JOIN nation ON nation.n_nationkey = customer.c_nationkey
WHERE nation.n_name = 'PERU' 
AND orders.o_orderpriority  = '1-URGENT'
AND (orders.o_orderdate BETWEEN '1995-01-01' 
AND '1997-12-31');