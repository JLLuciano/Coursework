// STEP: Import required packages
import java.sql.*;
import java.io.FileWriter;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.File;

public class Lab_7 {
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

    private void createTable() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Create table");
        try{
            Statement stmt = c.createStatement();

            //Create Warehouse table
            String sql = "CREATE TABLE warehouse(" +
            "w_warehousekey DECIMAL(9,0) NOT NULL," +
            "w_name CHAR(100) NOT NULL," +
            "w_capacity DECIMAL(6,0) NOT NULL," +
            "w_suppkey DECIMAL(9,0) NOT NULL," +
            "w_nationkey DECIMAL(2,0) NOT NULL)";
            stmt.execute(sql);

            c.commit();

            stmt.close();
        }
        catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
            try {
                c.rollback();
            } catch (Exception e1) {
                System.err.println(e1.getClass().getName() + ": " + e1.getMessage());
            }
            System.out.println("success-create");
        System.out.println("++++++++++++++++++++++++++++++++++");
    }
}

    private void populateTable() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Populate table");
        try{
        String sql = "INSERT INTO warehouse " +
        "VALUES(?, ?, ?, ?, ?)";
        

        String sql2 = "WITH test AS (SELECT s_name,s_suppkey,n_name, n_nationkey,COUNT(*) as cnt " +
        "FROM supplier, customer, lineitem, nation, part, orders " +
        "WHERE supplier.s_suppkey = lineitem.l_suppkey AND " +
        "customer.c_nationkey = nation.n_nationkey AND " + 
        "customer.c_custkey = orders.o_custkey AND " +
        "part.p_partkey = lineitem.l_partkey AND " +
        "lineitem.l_orderkey = orders.o_orderkey " +
        "GROUP BY s_name,n_name) " +
        "SELECT * FROM " +
        "(SELECT *, ROW_NUMBER() OVER (PARTITION BY s_name ORDER BY cnt DESC) AS t1 " +
        "FROM test) " +
        "WHERE t1 <= 2 ";
        String sql3 = "SELECT MAX(maxs) FROM (SELECT s_name,s_suppkey,n_name, n_nationkey, SUM(p_size) * 2 as maxs " +
        "FROM supplier, customer, lineitem, nation,part, orders " +
        "WHERE supplier.s_suppkey = lineitem.l_suppkey AND " +
        "customer.c_nationkey = nation.n_nationkey AND " +
        "customer.c_custkey = orders.o_custkey AND " +
        "part.p_partkey = lineitem.l_partkey AND " +
        "lineitem.l_orderkey = orders.o_orderkey " +
        "GROUP BY s_name,n_nationkey) " +
        "GROUP BY s_name";
        PreparedStatement stmt = c.prepareStatement(sql);
        PreparedStatement stmt2 = c.prepareStatement(sql2);
        PreparedStatement stmt3 = c.prepareStatement(sql3);

        ResultSet rs = stmt2.executeQuery();
        ResultSet rs2 = stmt3.executeQuery();
        int i = 0;
        int s_cap = 0;
        rs2.next();
        while(rs.next()){
        stmt.setInt(1,++i);
        String supp = rs.getString(1) + "___";
        String _wname = supp + rs.getString(3);
        stmt.setString(2,_wname);  
        stmt.setInt(4, rs.getInt(2));
        stmt.setInt(5,rs.getInt(4));
        if(i%2 == 0){
            
            stmt.setInt(3,s_cap);
            rs2.next();
        } else{
            s_cap = rs2.getInt(1);
            stmt.setInt(3,s_cap);
        }
        stmt.executeUpdate();
    
                }
        c.commit();
        stmt.close();
        stmt2.close();
        stmt3.close();
        rs.close();
        rs2.close();
        }catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
            try {
                c.rollback();
            } catch (Exception e1) {
                System.err.println(e1.getClass().getName() + ": " + e1.getMessage());
            }
        }
        System.out.println("success-POPULATED");    
        System.out.println("++++++++++++++++++++++++++++++++++");
    }

    private void dropTable() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Drop table");

        try {
            Statement stmt = c.createStatement();

            String sql = "DROP TABLE IF EXISTS warehouse";
            stmt.execute(sql);
            c.commit();
            stmt.close();

        } catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
            try {
                c.rollback();
            } catch (Exception e1) {
                System.err.println(e1.getClass().getName() + ": " + e1.getMessage());
            }
        }

        System.out.println("++++++++++++++++++++++++++++++++++");
    }

    private void Q1() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Q1");

        try {
            FileWriter writer = new FileWriter("output/1.out", false);
            PrintWriter printer = new PrintWriter(writer);
            String sql = "Select * FROM warehouse ORDER BY w_warehousekey";

            PreparedStatement stmt = c.prepareStatement(sql);
            ResultSet rs = stmt.executeQuery();
                
            printer.printf("%10s %-40s %10s %10s %10s\n", "wId", "wName", "wCap", "sId", "nId");
            
            while (rs.next()) {
                int w_key = rs.getInt(1);
                String w_name  = rs.getString(2);
                int w_cap = rs.getInt(3);
                int w_supp = rs.getInt(4);
                int w_nation = rs.getInt(5);
                printer.printf("%10d %-40s %10d %10d %10d\n", w_key, w_name, w_cap, w_supp, w_nation);
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

    private void Q2() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Q2");

        try {
            FileWriter writer = new FileWriter("output/2.out", false);
            PrintWriter printer = new PrintWriter(writer);

            String sql = "SELECT n_name, COUNT(w_nationkey) AS cnt,SUM(w_capacity) AS total " +
            "FROM warehouse,nation " +
            "WHERE w_nationkey = n_nationkey " +
            "GROUP BY n_name " +
            "ORDER BY cnt DESC,total DESC ";

            PreparedStatement stmt = c.prepareStatement(sql);
            ResultSet rs = stmt.executeQuery();

            printer.printf("%-40s %10s %10s\n", "nation", "numW", "totCap");
            
            while (rs.next()) {
                String n_name  = rs.getString(1);
                int w_total= rs.getInt(2);
                int w_cap = rs.getInt(3);
                printer.printf("%-40s %10d %10d\n", n_name, w_total, w_cap);
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
            File fn = new File("input/3.in");
            FileReader reader = new FileReader(fn);
            BufferedReader in = new BufferedReader(reader);
            String nation = in.readLine();
            in.close();

            FileWriter writer = new FileWriter("output/3.out", false);
            PrintWriter printer = new PrintWriter(writer);

            String sql = "SELECT s_name, n_name, w_name " +
            "FROM warehouse,nation, supplier " +
            "WHERE s_nationkey = n_nationkey " +
            "AND w_suppkey = s_suppkey " + 
            "AND w_name LIKE '%" + nation + 
            "%' GROUP BY s_name";

            PreparedStatement stmt = c.prepareStatement(sql);
            ResultSet rs = stmt.executeQuery();

            printer.printf("%-20s %-20s %-40s\n", "supplier", "nation", "warehouse");

            while (rs.next()) {
                String s_name = rs.getString(1);
                String n_name = rs.getString(2);
                String w_name = rs.getString(3);
                printer.printf("%-40s %-40s %-40s\n", s_name, n_name, w_name);
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
            File fn = new File("input/4.in");
            FileReader reader = new FileReader(fn);
            BufferedReader in = new BufferedReader(reader);
            String region = in.readLine();
            int cap = Integer.parseInt(in.readLine());
            in.close();

            FileWriter writer = new FileWriter("output/4.out", false);
            PrintWriter printer = new PrintWriter(writer);

            String sql ="SELECT w_name, w_capacity " +
            "FROM warehouse,nation, region " +
            "WHERE w_nationkey = n_nationkey " +
            "AND n_regionkey = r_regionkey " +
            "AND w_capacity > " + cap + " " +
            "AND r_name = '" + region + "' " + 
            "GROUP BY w_name "  +
            "ORDER BY w_capacity DESC";

            PreparedStatement stmt = c.prepareStatement(sql);
            ResultSet rs = stmt.executeQuery();

            printer.printf("%-40s %10s\n", "warehouse", "capacity");

            while (rs.next()) {
                String w_name = rs.getString(1);
                int w_cap = rs.getInt(2);
                printer.printf("%-40s %10d\n", w_name, w_cap);
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

    private void Q5() {
        System.out.println("++++++++++++++++++++++++++++++++++");
        System.out.println("Q5");

        try {
            File fn = new File("input/5.in");
            FileReader reader = new FileReader(fn);
            BufferedReader in = new BufferedReader(reader);
            String nation = in.readLine();
            in.close();

            FileWriter writer = new FileWriter("output/5.out", false);
            PrintWriter printer = new PrintWriter(writer);

            String sql = "SELECT r_name, SUM(w_capacity) " +
            "FROM warehouse,nation, region, supplier " +
            "WHERE w_nationkey = n_nationkey " +
            "AND n_regionkey = r_regionkey " +
            "AND w_suppkey = s_suppkey " + 
            "AND s_suppkey IN( SELECT s_suppkey FROM supplier, nation " + 
            "WHERE s_nationkey = n_nationkey " +
            "AND n_name = '" + nation + "') " + 
            "GROUP BY r_name";

            PreparedStatement stmt = c.prepareStatement(sql);
            ResultSet rs = stmt.executeQuery();

            String sql2 = "SELECT r_name " +
            "FROM region ";

            PreparedStatement stmt2 = c.prepareStatement(sql2);
            ResultSet rs2 = stmt2.executeQuery();

            printer.printf("%-20s %20s\n", "region", "capacity");

            rs.next();
            while (rs2.next()) {
                String region = (rs.getString(1));
                String region2 = (rs2.getString(1));
              if(region.equals(region2)){
                int t_cap = rs.getInt(2);
                printer.printf("%-40s %10d\n", region, t_cap);
                rs.next();
              }
              else{
                printer.printf("%-40s %10d\n", region2, 0);
              }
            }

            printer.close();
            writer.close();
            rs.close();
            rs2.close();
            stmt.close();
            stmt2.close();
        } catch (Exception e) {
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
        }

        System.out.println("++++++++++++++++++++++++++++++++++");
    }


    public static void main(String args[]) {
        Lab_7 sj = new Lab_7();
        
        sj.openConnection("tpch.sqlite");

        sj.dropTable();
        sj.createTable();
        sj.populateTable();

        sj.Q1();
        sj.Q2();
        sj.Q3();
        sj.Q4();
        sj.Q5();

        sj.closeConnection();
    }
}
