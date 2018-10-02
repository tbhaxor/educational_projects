/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package studentsystem;

/**
 *
 * @author meg2tron
 */
public class Main {
    public static void main(String[] args) {
        HashTable hashtable = new HashTable();
        StudentSystem std1 = new StudentSystem("Abhishek","1502665",7.8);
        StudentSystem std2 = new StudentSystem("Abhijeet","1502660",7.0);
        StudentSystem std3 = new StudentSystem("Japsimran","1502807",7.2);
        StudentSystem std4 = new StudentSystem("Jigyasa","1502813",7.8);
        StudentSystem std5 = new StudentSystem("Kanika","1502816",7.5);
        StudentSystem std6 = new StudentSystem("Kapil","1502817",7.8);
        StudentSystem std7 = new StudentSystem("Kappu","1502718",7.8);
        
        int std1key=hashtable.HashCode(std1.getRoll());
        int std2key=hashtable.HashCode(std2.getRoll());
        int std3key=hashtable.HashCode(std3.getRoll());
        int std4key=hashtable.HashCode(std4.getRoll());
        int std5key=hashtable.HashCode(std5.getRoll());
        int std6key=hashtable.HashCode(std6.getRoll());
        int std7key=hashtable.HashCode(std7.getRoll());
                
        
        hashtable.insert(std1key, std1);
        hashtable.insert(std2key, std2);
        hashtable.insert(std3key, std3);
        hashtable.insert(std4key, std4);
        hashtable.insert(std5key, std5);
        hashtable.insert(std6key, std6);
        hashtable.insert(std6key, std7);
        
        hashtable.showData();
        //StudentSystem test=hashtable.fetchStdInfo(std5.getRoll());
        //System.out.println(test.toString());
hashtable.deleteStd(std7.getRoll());
    hashtable.showData();
    }
    
}
