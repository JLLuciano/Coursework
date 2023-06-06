SELECT c_mktsegment, SUM(c_acctbal)
FROM customer
GROUP BY c_mktsegment;