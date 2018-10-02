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
public class StdList {
    private Node h;
    public StdList(){
        h = new Node();
        h.data=null;
        h.next=null;
    }
    public boolean insertStd(StudentSystem std)
    {
        Node n = new Node();
        n.data=std;
        n.next=h.next;
        h.next=n;
        
        return true;
    }
    public boolean haveRollno(String roll)
    {
        Node a = h.next;
        boolean have = false;
        while(a!=null)
        {
            if(roll.equals(a.data.getRoll()))
            {
                have = true;
                break;
            }
            a=a.next;
        }
        return have;
    }
    public StudentSystem fetchData(String roll)
    {
        StudentSystem data = null;
        Node p = h.next;
        while(p!=null)
        {
            if(p.data.getRoll().equals(roll))
            {
                data = p.data;
                break;
            }
            p = p.next;
        }
        return data;
    }
    
    public void deleteStudent(String roll)
    {
        Node p=h;
        Node q=h.next;
        while(q!=null && !(q.data.getRoll().equals(roll)))
        {
            p=q;
            q=q.next;
        }
        if(q!=null)
        {
            p.next=q.next;
        }
        else{
            //No Data found
            System.out.println("Data not found.............");
        }
    }
    public void showAll(){
        Node n = h.next;
        while(n!=null){
            System.out.println(n.data.toString());
            n=n.next;
        }
    }
    
    
    class Node{
        private StudentSystem data;
        private Node next;
    }
}
