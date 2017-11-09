#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
  char name[20], post[20], address[35], join_date[10];
  char department[30];
  int id;
  float salary;
public:
  Employee();
  void get_details(char*);
  void show_details();
  void modify();
  int get_id();
};

#endif
