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
public class StudentSystem {

    /**
     * @param args the command line arguments
     */
    private String name;
    private String roll;
    private double cgpa;

    public StudentSystem(String name, String roll, double cgpa) {
        this.name = name;
        this.roll = roll;
        this.cgpa = cgpa;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getRoll() {
        return roll;
    }

    public void setRoll(String roll) {
        this.roll = roll;
    }

    public double getCgpa() {
        return cgpa;
    }

    public void setCgpa(double cgpa) {
        this.cgpa = cgpa;
    }
    public String toString(){
        return "Name "+ name +" Roll no "+ roll +" CGPA "+cgpa;
    }
}
