#ifndef BANK_H
#define BANK_H

class Bank
{
  int acc_number, phone_number;
  float balance;
  char acc_type, name[30], email[30];
public:
  Bank();
  void get_details();
  void show_details();
  int is_acc_no();
  float get_curr_bal();
  void credit(float);
  void debit(float);
};

#endif
