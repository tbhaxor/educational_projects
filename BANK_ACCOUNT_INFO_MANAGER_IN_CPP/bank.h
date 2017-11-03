#ifndef BANK_H_
#define BANK_H_

class Bank
{
  int acc_no;
  float balance;
  char name[50];
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
