#ifndef COMPANY_H
#define COMPANY_H

#include "employee.h"

// all properties of a department will be added
class Company
{
  int id;
  char name[30];
public:
  Company();
  void get_details();
  void show_details();
  int get_id();
  char* get_name();
};

#endif
