#ifndef BOOK_H
#define BOOK_H

// datatype for books
class Book
{
	int id, quantity;
	float price;
	char title[30], author[30];
public:
	Book();
	void get();
	void show();
	bool is_ID(int);
	void modify();
};

#endif