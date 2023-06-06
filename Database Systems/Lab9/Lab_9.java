// STEP: Import required packages
import java.sql.*;
import java.io.FileWriter;
import java.io.PrintWriter;

public class Lab_9 {
    private Connection c = null;
    private String dbName;
    private boolean isConnected = false;

    private void openConnection(String _dbName) {
        dbName = _dbName;

        if (false == isConnected) {
            System.out.println("++++++++++++++++++++++++++++++++++");
            System.out.println("Open database: " + _dbName);

            try {
                String connStr = new String("jdbc:sqlite:");
                connStr = connStr + _dbName;

                // STEP: Register JDBC driver
                Class.forName("org.sqlite.JDBC");

                // STEP: Open a connection
                c = DriverManager.getConnection(connStr);

                // STEP: Diable auto transactions
                c.setAutoCommit(false);

                isConnected = true;
                System.out.println("success");
            } catch (Exception e) {
                System.err.println(e.getClass().getName() + ": " + e.getMessage());
                System.exit(0);
            }

            System.out.println("++++++++++++++++++++++++++++++++++");
        }
    }

    private void closeConnection() {
        if (true == isConnected) {
            System.out.println("++++++++++++++++++++++++++++++++++");
            System.out.println("Close database: " + dbName);

            try {
                // STEP: Close connection
                c.close();

                isConnected = false;
                dbName = "";
                System.out.println("success");
            } catch (Exception e) {
                System.err.println(e.getClass().getName() + ": " + e.getMessage());
                System.exit(0);
            }

            System.out.println("++++++++++++++++++++++++++++++++++");
        }
    }

    private void create_View1() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Create V1");

        try{
        String drop = "DROP VIEW IF EXISTS V1";
        String view = "CREATE VIEW V1(c_custkey, c_name, c_address, c_phone, c_acctbal, c_mktsegment, c_comment, c_nation," +
        "c_region) AS select c_custkey, c_name, c_address, c_phone, c_acctbal, c_mktsegment, c_comment, n_name, r_name " +
         "from customer, nation, region " +
         "where c_nationkey = n_nationkey and r_regionkey = n_regionkey";

         PreparedStatement st = c.prepareStatement(drop);
         st.executeUpdate();
         c.commit();

        PreparedStatement stmt = c.prepareStatement(view);
        stmt.executeUpdate();
        c.commit();  
        
        stmt.close();
        st.close();
        }catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
        }
      


        System.out.println("++++++++++++++++++++++++++++++++++");
    }

    private void Q1() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Q1");

        try {
            FileWriter writer = new FileWriter("output/1.out", false);
            PrintWriter printer = new PrintWriter(writer);

            String sql = "select c_name, round(sum(o_totalprice),2)" +
            "from V1, orders " +
            "where o_custkey = c_custkey and " +
            "c_nation = 'FRANCE' and " +
            "o_orderdate like '1995-__-__' " +
            "group by c_name";

            PreparedStatement stmt = c.prepareStatement(sql);
            ResultSet rs = stmt.executeQuery();
                

            while(rs.next()){
                String name = rs.getString(1);
                double sum = rs.getDouble(2);
                
                printer.println(name + "|" + sum);
                
            }
                
            printer.close();
            writer.close();
            rs.close();
            stmt.close();
        } catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
        }

        System.out.println("++++++++++++++++++++++++++++++++++");
    }

    private void create_View2() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Create V2");
        try{
        String drop = "DROP VIEW IF EXISTS V2";
        PreparedStatement st = c.prepareStatement(drop);
        st.executeUpdate();
        c.commit();

        String view = "CREATE VIEW V2(s_suppkey, s_name, s_address, s_phone, s_acctbal, s_comment, s_nation, s_region) " + 
        "AS select s_suppkey, s_name, s_address, s_phone, s_acctbal, s_comment, n_name, r_name from " +
        "supplier, nation, region where " +
        "s_nationkey = n_nationkey and r_regionkey = n_regionkey";
        PreparedStatement stmt = c.prepareStatement(view);
        stmt.executeUpdate();
        c.commit();

        stmt.close();
        st.close();
        }catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
        }


        System.out.println("++++++++++++++++++++++++++++++++++");
    }

    private void Q2() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Q2");

        try {
            FileWriter writer = new FileWriter("output/2.out", false);
            PrintWriter printer = new PrintWriter(writer);

            String sql = "select s_region, count(*) " + 
            "from V2 " +
            "group by s_region";

            PreparedStatement stmt = c.prepareStatement(sql);
            ResultSet rs = stmt.executeQuery();

            while(rs.next()){
                String name = rs.getString(1);
                int count = rs.getInt(2);
                
                printer.println(name + "|" + count);
                
            }

            printer.close();
            writer.close();
            rs.close();
            stmt.close();
        } catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
        }

        System.out.println("++++++++++++++++++++++++++++++++++");
    }

    private void Q3() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Q3");

        try {
            FileWriter writer = new FileWriter("output/3.out", false);
            PrintWriter printer = new PrintWriter(writer);

            String sql= "select c_nation, count(*) " +
            "from orders, V1 " +
            "where c_custkey = o_custkey " +
            "and c_region = 'AMERICA' " +
            "group by c_nation";

        PreparedStatement stmt = c.prepareStatement(sql);
        ResultSet rs = stmt.executeQuery();

        
        while(rs.next()){
            String name = rs.getString(1);
            int count = rs.getInt(2);
            
            printer.println(name + "|" + count);
            
        }

            printer.close();
            writer.close();
            rs.close();
            stmt.close();
        } catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
        }

        System.out.println("++++++++++++++++++++++++++++++++++");
    }

    private void Q4() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Q4");

        try {
            FileWriter writer = new FileWriter("output/4.out", false);
            PrintWriter printer = new PrintWriter(writer);

            String sql = "select s_name, count(ps_partkey) "+
            "from partsupp, V2, part " +
            "where p_partkey = ps_partkey " +
                "and ps_suppkey = s_suppkey " + 
                "and s_nation = 'CANADA' " +
                "and p_size < 20 " +
            "group by s_name";

            PreparedStatement stmt = c.prepareStatement(sql);
            ResultSet rs = stmt.executeQuery();
    
            
            while(rs.next()){
                String name = rs.getString(1);
                int count = rs.getInt(2);
                
                printer.println(name + "|" + count);
                
            }
    
            rs.close();
            stmt.close();
            printer.close();
            writer.close();
        } catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
        }

        System.out.println("++++++++++++++++++++++++++++++++++");
    }

    private void create_View5() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Create V5");

        try{
            String drop = "DROP VIEW IF EXISTS V5";
            PreparedStatement st = c.prepareStatement(drop);
            st.executeUpdate();
            c.commit();

            String view = "CREATE VIEW V5(o_orderkey, o_custkey, o_orderstatus, " +
            "o_totalprice, o_orderyear, o_orderpriority, o_clerk, " +
            "o_shippriority, o_comment) AS " +
            "select o_orderkey, o_custkey, o_orderstatus, o_totalprice, " +
            "strftime('%Y',o_orderdate) as o_orderyear, o_orderpriority, o_clerk, " +
            "o_shippriority, o_comment " +
            "from orders";

            PreparedStatement stmt = c.prepareStatement(view);
            stmt.executeUpdate();
            c.commit();
        }catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
        }

        System.out.println("++++++++++++++++++++++++++++++++++");
    }

    private void Q5() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Q5");

        try {
            FileWriter writer = new FileWriter("output/5.out", false);
            PrintWriter printer = new PrintWriter(writer);

            String sql = "select c_name, count(*) " +
            "from V5, customer, nation "  +
            "where o_custkey = c_custkey " +
                "and c_nationkey = n_nationkey " +
                "and n_name = 'GERMANY' " +
                "and o_orderyear like '1993' " +
            "group by c_name";

            PreparedStatement stmt = c.prepareStatement(sql);
            ResultSet rs = stmt.executeQuery();
    
            
            while(rs.next()){
                String name = rs.getString(1);
                int count = rs.getInt(2);
                
                printer.println(name + "|" + count);
                
            }

            rs.close();
            stmt.close();
            printer.close();
            writer.close();
        } catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
        }

        System.out.println("++++++++++++++++++++++++++++++++++");
    }

    private void Q6() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Q6");

        try {
            FileWriter writer = new FileWriter("output/6.out", false);
            PrintWriter printer = new PrintWriter(writer);
        
            String sql = "select s_name, o_orderpriority, count(distinct ps_partkey) " +
            "from partsupp, V5,lineitem, supplier, nation " +
            "where l_orderkey = o_orderkey " +
                "and l_partkey = ps_partkey " +
                "and l_suppkey = ps_suppkey " + 
                "and ps_suppkey = s_suppkey " +
                "and s_nationkey = n_nationkey " +
                "and n_name = 'CANADA' " +
            "group by s_name, o_orderpriority";

            PreparedStatement stmt = c.prepareStatement(sql);
            ResultSet rs = stmt.executeQuery();
    
            
            while(rs.next()){
                String name = rs.getString(1);
                String priority = rs.getString(2);
                int count = rs.getInt(3);
                
                printer.println(name + "|" + priority + "|" + count);
                
            }

            rs.close();
            stmt.close();
            printer.close();
            writer.close();
        } catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
        }

        System.out.println("++++++++++++++++++++++++++++++++++");
    }

    private void Q7() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Q7");

        try {
            FileWriter writer = new FileWriter("output/7.out", false);
            PrintWriter printer = new PrintWriter(writer);

            String sql = "select c_nation, o_orderstatus, count(*) " +
            "from V1,V5 " +
            "where o_custkey = c_custkey " +
            "and c_region='AMERICA' " +
            "group by c_nation, o_orderstatus";

            PreparedStatement stmt = c.prepareStatement(sql);
            ResultSet rs = stmt.executeQuery();
    
            
            while(rs.next()){
                String name = rs.getString(1);
                String priority = rs.getString(2);
                int count = rs.getInt(3);
                
                printer.println(name + "|" + priority + "|" + count);
                
            }

            rs.close();
            stmt.close();
            printer.close();
            writer.close();
        } catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
        }

        System.out.println("++++++++++++++++++++++++++++++++++");
    }

    private void Q8() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Q8");

        try {
            FileWriter writer = new FileWriter("output/8.out", false);
            PrintWriter printer = new PrintWriter(writer);

            String sql = "select s_nation, count(distinct l_orderkey) as co " + 
            "from V2, V5, lineitem " +
            "where o_orderkey = l_orderkey " + 
            "and l_suppkey = s_suppkey " + 
            "and o_orderstatus = 'F' " +
            "and o_orderyear like '1995' " + 
            "group by s_nation " + 
            "having co > 50";

            PreparedStatement stmt = c.prepareStatement(sql);
            ResultSet rs = stmt.executeQuery();
    
            
            while(rs.next()){
                String name = rs.getString(1);
                int count = rs.getInt(2);
                
                printer.println(name + "|" + count);
                
            }

            rs.close();
            stmt.close();
            printer.close();
            writer.close();
        } catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
        }

        System.out.println("++++++++++++++++++++++++++++++++++");
    }

    private void Q9() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Q9");

        try {
            FileWriter writer = new FileWriter("output/9.out", false);
            PrintWriter printer = new PrintWriter(writer);

            String sql = "select count(distinct o_clerk) " + 
            "from V2, V5, lineitem " + 
            "where o_orderkey = l_orderkey " + 
            "and l_suppkey = s_suppkey " +
            "and s_nation = 'UNITED STATES'";

            PreparedStatement stmt = c.prepareStatement(sql);
            ResultSet rs = stmt.executeQuery();
    
            
            while(rs.next()){
        
                int count = rs.getInt(1);
                
                printer.println(count);
                
            }

            rs.close();
            stmt.close();
            printer.close();
            writer.close();
        } catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
        }

        System.out.println("++++++++++++++++++++++++++++++++++");
    }

    private void create_View10() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Create V10");
        try{
        String drop = "DROP VIEW IF EXISTS V10";
        PreparedStatement st = c.prepareStatement(drop);
        st.executeUpdate();
        c.commit();

        String view = "CREATE VIEW V10(p_type, min_discount, max_discount) AS " +
        "select p_type, MIN(l_discount) as min_discount, MAX(l_discount) as max_discount " + 
        "from part, lineitem where p_partkey = l_partkey group by p_type";
        PreparedStatement stmt = c.prepareStatement(view);
        stmt.executeUpdate();
        c.commit();
        }catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
        }


        System.out.println("++++++++++++++++++++++++++++++++++");
    }

    private void Q10() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Q10");

        try {
            FileWriter writer = new FileWriter("output/10.out", false);
            PrintWriter printer = new PrintWriter(writer);

            String sql = "select p_type, min_discount, max_discount " +
            "from V10 " + 
            "where p_type like '%ECONOMY%' " + 
            "and p_type like '%COPPER%' " + 
            "group by p_type";

            PreparedStatement stmt = c.prepareStatement(sql);
            ResultSet rs = stmt.executeQuery();
    
            while(rs.next()){
                String type = rs.getString(1);
                String min = rs.getString(2);
                String max = rs.getString(3);

               
                
                printer.println(type + "|" + min + "|" + max);
                
            }

            rs.close();
            stmt.close();
            printer.close();
            writer.close();
        } catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
        }

        System.out.println("++++++++++++++++++++++++++++++++++");
    }

    private void Q11() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Q11");

        try {
            FileWriter writer = new FileWriter("output/11.out", false);
            PrintWriter printer = new PrintWriter(writer);

            String sql = "select s.s_region, s.s_name, s.s_acctbal " + 
            "from V2 s " + 
            "where s.s_acctbal = (select max(s1.s_acctbal) " + 
            "from V2 s1 " + 
            "where s.s_region = s1.s_region) order by s.s_region";

            PreparedStatement stmt = c.prepareStatement(sql);
            ResultSet rs = stmt.executeQuery();
    
            while(rs.next()){
                String region = rs.getString(1);
                String name = rs.getString(2);
                String bal = rs.getString(3);

               
                
                printer.println(region + "|" + name + "|" + bal);
                
            }

            rs.close();
            stmt.close();
            printer.close();
            writer.close();
        } catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
        }

        System.out.println("++++++++++++++++++++++++++++++++++");
    }

    private void Q12() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Q12");

        try {
            FileWriter writer = new FileWriter("output/12.out", false);
            PrintWriter printer = new PrintWriter(writer);

            String sql = "select s_nation, max(s_acctbal) as mb " + 
            "from V2 " + 
            "group by s_nation " + 
            "having mb > 9000 ";

            PreparedStatement stmt = c.prepareStatement(sql);
            ResultSet rs = stmt.executeQuery();
    
            while(rs.next()){
                String nation = rs.getString(1);
                String max = rs.getString(2);
               
                
                printer.println(nation + "|" + max);
                
            }

            rs.close();
            stmt.close();
            printer.close();
            writer.close();
        } catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
        }

        System.out.println("++++++++++++++++++++++++++++++++++");
    }

    private void Q13() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Q13");

        try {
            FileWriter writer = new FileWriter("output/13.out", false);
            PrintWriter printer = new PrintWriter(writer);

            String sql = "select count(*) " + 
            "from V1, V2, orders, lineitem " + 
            "where o_orderkey = l_orderkey " + 
                "and o_custkey = c_custkey " + 
                "and l_suppkey = s_suppkey " +
                "and s_region = 'AFRICA' " + 
                "and c_nation = 'UNITED STATES'";

            PreparedStatement stmt = c.prepareStatement(sql);
            ResultSet rs = stmt.executeQuery();
    
            while(rs.next()){
                String count = rs.getString(1);
               
                
                printer.println(count);
                
            }

            rs.close();
            stmt.close();
            printer.close();
            writer.close();
        } catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
        }

        System.out.println("++++++++++++++++++++++++++++++++++");
    }

    private void Q14() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Q14");

        try {
            FileWriter writer = new FileWriter("output/14.out", false);
            PrintWriter printer = new PrintWriter(writer);

            String sql = "select s_region as suppRegion, c_region as custRegion, max(o_totalprice) " + 
            "from V1, V2, lineitem, orders " + 
            "where l_suppkey = s_suppkey " + 
            "and l_orderkey = o_orderkey " + 
            "and o_custkey = c_custkey " + 
            "group by s_region, c_region";

            PreparedStatement stmt = c.prepareStatement(sql);
            ResultSet rs = stmt.executeQuery();
    
            while(rs.next()){
                String region1 = rs.getString(1);
                String region2 = rs.getString(2);
                String bal = rs.getString(3);

               
                
                printer.println(region1 + "|" + region2 + "|" + bal);
                
            }

            rs.close();
            stmt.close();
            printer.close();
            writer.close();
        } catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
        }

        System.out.println("++++++++++++++++++++++++++++++++++");
    }

    private void create_View151() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Create V151");

        try{

            String drop = "DROP VIEW IF EXISTS V151";
            PreparedStatement st = c.prepareStatement(drop);
            st.executeUpdate();
            c.commit();

            String view = "CREATE VIEW V151(c_custkey, c_name, c_nationkey, c_acctbal) AS " +
            "select c_custkey, c_name, c_nationkey, c_acctbal from customer where c_acctbal > 0";
            PreparedStatement stmt = c.prepareStatement(view);
            stmt.executeUpdate();
            c.commit();

            }catch (Exception e) {
                System.err.println(e.getClass().getName() + ": " + e.getMessage());
            }

        System.out.println("++++++++++++++++++++++++++++++++++");
    }

    private void create_View152() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Create V152");

        try{

            String drop = "DROP VIEW IF EXISTS V152";
            PreparedStatement st = c.prepareStatement(drop);
            st.executeUpdate();
            c.commit();

            String view = "CREATE VIEW V152(s_suppkey, s_name, s_nationkey, s_acctbal) AS " +
            "select s_suppkey, s_name, s_nationkey, s_acctbal from supplier where s_acctbal < 0";
            PreparedStatement stmt = c.prepareStatement(view);
            stmt.executeUpdate();
            c.commit();

            }catch (Exception e) {
                System.err.println(e.getClass().getName() + ": " + e.getMessage());
            }
        System.out.println("++++++++++++++++++++++++++++++++++");
    }

    private void Q15() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Q15");

        try {
            FileWriter writer = new FileWriter("output/15.out", false);
            PrintWriter printer = new PrintWriter(writer);

            String sql = "select count(distinct l_orderkey) " + 
            "from lineitem, V152,orders, V151 " + 
            "where l_suppkey = s_suppkey " + 
            "and l_orderkey = o_orderkey " + 
            "and o_custkey = c_custkey ";

            PreparedStatement stmt = c.prepareStatement(sql);
            ResultSet rs = stmt.executeQuery();
    
            while(rs.next()){
                String count = rs.getString(1);
               
                
                printer.println(count);
                
            }

            rs.close();
            stmt.close();
            printer.close();
            writer.close();
        } catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
        }

        System.out.println("++++++++++++++++++++++++++++++++++");
    }

    public static void main(String args[]) {
        Lab_9 sj = new Lab_9();
        
        sj.openConnection("tpch.sqlite");

        sj.create_View1();
        sj.Q1();

        sj.create_View2();
        sj.Q2();

        sj.Q3();
        sj.Q4();

        sj.create_View5();
        sj.Q5();

        sj.Q6();
        sj.Q7();
        sj.Q8();
        sj.Q9();

        sj.create_View10();
        sj.Q10();

        sj.Q11();
        sj.Q12();
        sj.Q13();
        sj.Q14();

        sj.create_View151();
        sj.create_View152();
        sj.Q15();

        sj.closeConnection();
    }
}
