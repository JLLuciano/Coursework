SELECT r_name, COUNT(s_suppkey)
FROM region,nation,supplier
WHERE nation.n_nationkey = supplier.s_nationkey
AND region.r_regionkey = nation.n_regionkey
GROUP BY r_name;