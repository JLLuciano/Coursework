SELECT n_name
FROM(SELECT n_name, SUM(l_extendedprice) AS total
FROM nation,supplier, lineitem
WHERE supplier.s_nationkey = nation.n_nationkey
AND lineitem.l_suppkey = supplier.s_suppkey
AND (l_shipdate BETWEEN '1995-01-01' AND '1995-12-31')
GROUP BY n_name
ORDER BY total DESC
LIMIT 1
);