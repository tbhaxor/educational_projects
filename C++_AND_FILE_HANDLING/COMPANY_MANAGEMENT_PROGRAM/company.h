#ifndef COMPANY_H
#define COMPANY_H

#include "employee.h"
// all properties of a department will be added
class Company : protected Employee
{
  char name[30];
public:
  void get();
  void show();
};

#endif
