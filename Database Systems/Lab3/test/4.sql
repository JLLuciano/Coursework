SELECT count(l_shipdate)
FROM lineitem
WHERE l_shipdate = l_commitdate;