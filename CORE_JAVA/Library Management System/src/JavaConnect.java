
import java.sql.*;
import javax.swing.JOptionPane;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author meg2tron
 */
@SuppressWarnings("InitializerMayBeStatic")
public class JavaConnect {
    
    public static Connection ConnecrDb(){
    try{
        Class.forName("org.sqlite.JDBC");
        Connection conn=DriverManager.getConnection("jdbc:sqlite:/run/media/meg2tron/SOFTWARE/Java/Library Management System/Library_new.sqlite");
    return conn;
    }
    catch(Exception e)
    {
        JOptionPane.showMessageDialog(null, e);
    return null;
    }
}
}
