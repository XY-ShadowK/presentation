package experiment2;

import java.sql.*;

public class Experiment2 {
    public static Connection conn;
    public static Statement statement;
    public static ResultSet rset;
    public static LoginFrame loginFrame;
    public static ChooseFrame chooseFrame;
    public static QueryFrame queryFrame;
    public static void main(String[] args) {
        try{
            conn=DriverManager.getConnection("jdbc:MySQL://localhost:3306/stu_edu","root","MySQLRoot");
            statement=conn.createStatement();
            loginFrame=new LoginFrame();
            chooseFrame=new ChooseFrame();
        }catch (SQLException e){
            e.printStackTrace();
        }
    }
}
