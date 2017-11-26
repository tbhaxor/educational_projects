// including header files and libraries
#include <iostream>
#include <fstream>
#include "library.h"
using namespace std;

// defining Library class constructor
Library::Library()
{
	this->id = 0;
	this->salary = 0.0F;
	this->name[0] = '\0';
	this->post[0] = '\0';
}

// defining get method of library class
void Library::get()
{
	cout<<"enter id : ";
	cin>>this->id;  // getting library staff id
	cin.ignore();   // ignoring input stream buffer
	cout<<"enter name : ";
	cin.getline(this->name, 30);    // getting staff name
	cout<<"enter post : ";
	cin.getline(this->post, 30);    // getting staff post
	cout<<"enter salary : ";
	cin>>this->salary;    // getting staff salary
	cin.ignore();    // ignoring input stream buffer
}

// defining show method of Library class
void Library::show()
{
	cout<<"Staff ID : "<<this->id<<endl;
	cout<<"Name : "<<this->name<<endl;
	cout<<"Post : "<<this->post<<"\t\tSalary : "<<this->salary<<endl;
	cout<<"--------------------------------------------------"<<endl;
}

// defining is_ID method of Library class
bool Library::is_ID(int id)
{
	return this->id == id;   // returns true if id passed by value is equal to id of staff present database else returns false 
}

// defining modify method of class Library
void Library::modify()
{
	int opt;
	cout<<"What you wana change ? "<<endl;
	cout<<"1. Name\t2. Post\t3. Salary\n> ";
	cin>>opt;
	cin.ignore();  // ignoring input stream buffer
	switch(opt) // handling selections
	{
		case 1:
			cout<<"enter new name : ";
			cin.getline(this->name, 30);  // overwriting name  value
			break;
		case 2:
			cout<<"enter new post : ";
			cin.getline(this->post, 30);   // overwriting post value
			break;
		case 3:
			cout<<"enter new salary amount : ";
			cin>>this->salary;  // overwriting salary value
			cin.ignore(); // ignoring input stream buffer
			break;
	}
}	