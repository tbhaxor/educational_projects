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
public class HashTable {
    private StdList[] arr;
    private int size;
    private int totalstudent;
    public HashTable(){
        size=1000;
        arr=new StdList[1000];
    }
    public int HashCode(String roll){
        int asciis=0;
        int codevalue=0;
        for(int i=0;i<roll.length();i++)
        {
            asciis=asciis+(int)roll.charAt(i);
        }
        codevalue=asciis% arr.length;
        
        return codevalue;
    }
    public boolean insert(int key,StudentSystem data)
    {
        if(arr[key]==null)
        {
            arr[key]= new StdList();
        }
        arr[key].insertStd(data);
        totalstudent++;
        return true;
    }
    public int getTotal(){
        return totalstudent;
    }
    public StudentSystem fetchStdInfo(String roll)
    {
        int key = HashCode(roll);
        if(arr[key]==null)
        return null;
        else{
            StudentSystem q= arr[key].fetchData(roll);
            if(q!=null)
            {
                return q;
            }
            else
                return null;
        }
    }
    public boolean deleteStd(String roll)
    {
        boolean have=arr[HashCode(roll)].haveRollno(roll);
        if(have)
        {
            int key=HashCode(roll);
            arr[key].deleteStudent(roll);
            totalstudent--;
            return true;
        }
        return false;
    }
    public void showData()
    {
        for(int i=0;i<arr.length;i++)
        {
            if(arr[i]!=null)
            {
                arr[i].showAll();
            }
        }
    }
}
