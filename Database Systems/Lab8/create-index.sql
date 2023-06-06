CREATE INDEX customer_idx_c_name ON customer(c_name);
CREATE INDEX lineitem_idx_l_returnflag_l_receiptdate ON lineitem (l_returnflag, l_receiptdate);
CREATE INDEX customer_idx_c_mktsegment ON customer(c_mktsegment);
CREATE INDEX nation_idx_n_nationkey_n_name ON nation(n_nationkey, n_name);
CREATE INDEX customer_idx_c_custkey ON customer(c_custkey);
CREATE INDEX orders_idx_o_orderdate ON orders(o_orderdate);
CREATE INDEX lineitem_idx_l_orderkey ON lineitem(l_orderkey);
CREATE INDEX orders_idx_o_custkey_o_orderkey ON orders(o_custkey, o_orderkey);
CREATE INDEX customer_idx_c_name_c_custkey ON customer(c_name, c_custkey);
CREATE INDEX supplier_idx_s_nationkey_s_acctbal ON supplier(s_nationkey, s_acctbal);
CREATE INDEX nation_idx_n_regionkey_n_nationkey ON nation(n_regionkey, n_nationkey);
CREATE INDEX region_idx_r_name_r_regionkey ON region(r_name, r_regionkey);
CREATE INDEX nation_idx_n_name ON nation(n_name);
CREATE INDEX orders_idx_o_custkey_o_orderdate ON orders(o_custkey, o_orderdate);
CREATE INDEX customer_idx_c_nationkey_c_custkey ON customer(c_nationkey, c_custkey);
CREATE INDEX orders_idx_o_orderkey ON orders(o_orderkey);
CREATE INDEX lineitem_idx_l_discount ON lineitem(l_discount);
CREATE INDEX region_idx_r_regionkey_r_name ON region(r_regionkey, r_name);
CREATE INDEX orders_idx_o_orderstatus ON orders(o_orderstatus);
CREATE INDEX orders_idx_o_orderpriority_o_orderdate ON orders(o_orderpriority, o_orderdate);
CREATE INDEX lineitem_idx_l_orderkey_l_suppkey ON lineitem(l_orderkey, l_suppkey);
CREATE INDEX supplier_idx_s_nationkey_s_suppkey ON supplier(s_nationkey, s_suppkey);
CREATE INDEX orders_idx_o_orderpriority_o_orderkey ON orders(o_orderpriority, o_orderkey);





