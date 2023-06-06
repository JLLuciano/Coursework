SELECT r_name, COUNT(DISTINCT c_name)
FROM (SELECT *
FROM nation, region, orders, customer
WHERE customer.c_nationkey = nation.n_nationkey
AND nation.n_regionkey = region.r_regionkey
AND c_custkey NOT IN (SELECT o_custkey FROM orders)
)
WHERE c_acctbal < (SELECT AVG(c_acctbal) FROM customer)
GROUP BY r_name;

