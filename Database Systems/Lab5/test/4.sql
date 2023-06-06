SELECT n_name, COUNT(DISTINCT c_name), COUNT(DISTINCT s_name)
FROM customer, nation, region, supplier
WHERE customer.c_nationkey = nation.n_nationkey
AND region.r_regionkey = nation.n_regionkey
AND supplier.s_nationkey = nation.n_nationkey
AND r_name = 'AFRICA'
GROUP BY n_name;

