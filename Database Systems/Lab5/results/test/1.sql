SELECT c_name, SUM(o_totalprice)
FROM customer, orders, nation
WHERE customer.c_custkey = orders.o_custkey
AND nation.n_nationkey = customer.c_nationkey
AND nation.n_name = 'FRANCE'
AND (orders.o_orderdate BETWEEN '1995-01-01' AND '1995-12-31')
GROUP BY c_name;