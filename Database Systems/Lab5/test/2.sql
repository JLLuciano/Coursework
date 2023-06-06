SELECT Region, COUNT(Supplier)
FROM 
(SELECT r_name AS Region, AVG(s_acctbal) AS r_bal
FROM supplier, nation, region
WHERE supplier.s_nationkey = nation.n_nationkey
AND nation.n_regionkey = region.r_regionkey
GROUP BY region.r_name),
(SELECT r_name AS s_region, s_name AS Supplier, s_acctbal AS bal
FROM supplier, nation, region
WHERE supplier.s_nationkey = nation.n_nationkey
AND nation.n_regionkey = region.r_regionkey)
WHERE bal < r_bal
AND s_region = Region
GROUP BY Region;