#ifndef BOOK_H
#define BOOK_H

class Book
{
  char name[30];
  char author[30];
  float price;
  int book_id;
  int quantity;
public:
    void getdata();
    void showdata();
    void modify();
    int get_book_id();
};
#endif
