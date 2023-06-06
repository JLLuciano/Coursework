SELECT COUNT(c_name)
FROM customer, nation, region
WHERE customer.c_nationkey = nation.n_nationkey
AND nation.n_regionkey = region.r_regionkey
AND r_name NOT IN ('AFRICA', 'EUROPE', 'ASIA');