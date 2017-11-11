#ifndef COMPANY_H
#define COMPANY_H

// all properties of a department will be added
class Company
{
  int id;
  char name[30];
public:
  Company();
  void get_details();
  void show_details();
  void modify();
  int get_id();
};

#endif
