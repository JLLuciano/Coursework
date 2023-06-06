SELECT n_name
FROM(SELECT n_name, COUNT(c_custkey) AS cnt 
FROM nation, customer
WHERE customer.c_nationkey = nation.n_nationkey
GROUP BY n_name
ORDER BY cnt
LIMIT 1
);