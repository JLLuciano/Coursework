SELECT s_name, c_name, o_totalprice
FROM supplier, customer, orders, lineitem
WHERE supplier.s_suppkey = lineitem.l_suppkey
AND lineitem.l_orderkey = orders.o_orderkey
AND customer.c_custkey = orders. o_custkey
AND o_orderstatus = 'F'
AND orders.o_totalprice = (SELECT MIN(o_totalprice) FROM orders);