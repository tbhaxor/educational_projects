#ifndef LIBRARY_H_
#define LIBRARY_H_

// datatype for library staff
class Library
{
	int inchargeID;
	char name[30], post[20];
	float salary;
public:
	void get();
	void show();
	bool is_ID(int);
};

#endif