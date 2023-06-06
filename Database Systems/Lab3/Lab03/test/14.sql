SELECT COUNT(orders.o_orderpriority)
FROM orders
JOIN customer ON orders.o_custkey = customer.c_custkey
JOIN nation ON customer.c_nationkey = nation.n_nationkey
WHERE orders.o_orderpriority = '1-URGENT' AND nation.n_name = 'PERU' AND (orders.o_orderdate BETWEEN "1995-01-01" AND "1997-12-31");