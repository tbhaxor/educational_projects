// including header files and libraries
#include <iostream>
#include "book.h"
using namespace std;

// defining Book class constructor
Book::Book()
{
	this->id = this->quantity = 0;
	this->price = 0.0F;
	this->title[0] = this->author[0] = '\0';
}

// defining get method of class Book
void Book::get()
{
	cout<<"enter book id : ";
	cin>>this->id;  // getting book id
	cin.ignore();   // ignoring input stream buffer
	cout<<"enter book title : ";
	cin.getline(this->title, 30);  // getting book title
	cout<<"enter book author name : ";
	cin.getline(this->author, 30); // getting book author name
	cout<<"enter quantity : ";
	cin>>this->quantity; // getting number of books
	cin.ignore();   // ignoring input stream buffer
	cout<<"enter price : ";
	cin>>this->price; // getting price
}

// defining is_ID method of class Book
bool Book::is_ID(int id)
{
	return this->id == id; // returns true if id passed by value is equal to id of book present database else returns false 
}

// defining show method of class Book
void Book::show()
{
	cout<<"Book ID : "<<this->id<<endl;
	cout<<"Book Title : "<<this->title<<endl;
	cout<<"Book Author : "<<this->author<<endl;
	cout<<"Price : "<<this->price<<"\t\tQuantity : "<<this->quantity<<endl;
	cout<<"----------------------------------------------------------------"<<endl;
}

// defining modify method of class Book
void Book::modify()
{
	int opt;
	cout<<"What you wana change ?"<<endl;
	cout<<"1. Title\t2. Author\t3. Price\t4. Quantity\n> ";
	cin>>opt;   // getting user selection
	cin.ignore();  // ignore input stream buffer
	switch(opt)   // using switch-case to handle user input selection
	{
		case 1:
			cout<<"enter new book title title : ";
			cin.getline(this->title, 30);   // overwriting exiting title
			break;
		case 2:
			cout<<"enter new author name : ";
			cin.getline(this->author, 30);   // overwriting exiting author
			break;
		case 3:
			cout<<"enter new price : ";
			cin>>this->price;   // overwriting previous price
			cin.ignore();   // ignoring input stream buffer
			break;
		case 4:
			cout<<"enter new quantity : ";
			cin>>this->quantity;   // overwriting previous quantity
			cin.ignore();   // ignoring input stream buffer
			break;
	}
}