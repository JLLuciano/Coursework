SELECT customer.c_name, COUNT(orders.o_custkey)
FROM customer
INNER JOIN nation ON nation.n_nationkey = customer.c_nationkey
INNER JOIN orders ON orders.o_custkey = customer.c_custkey
WHERE nation.n_name = 'GERMANY'
AND (orders.o_orderdate BETWEEN '1993-01-01' AND '1993-12-31')
GROUP BY customer.c_name;