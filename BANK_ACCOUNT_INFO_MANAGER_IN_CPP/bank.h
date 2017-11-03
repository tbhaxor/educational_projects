#ifndef BANK_H_
#define BANK_H_

#include <iostream>
using namespace std;
class Bank
{
  int acc_no;
  float balance;
  string name;
  char type;
public:
  Bank();
  ~Bank();
  void get();
  void put();
  bool search(int);
  int is_acc_no();
};

#endif // Bank
