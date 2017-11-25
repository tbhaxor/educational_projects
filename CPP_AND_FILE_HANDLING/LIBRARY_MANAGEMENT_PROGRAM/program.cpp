#include <iostream>
#include <cstdlib>
#include "actor.h"
#include "config.h"
using namespace std;
using namespace Actor;

// prototyping some functions
void intro();
int menu();
void pause();
void clrscr();

// main function
int main()
{
	info();
	return 0;
}

// defining intro function
void intro()
{
	clrscr();
	cout<<"--------------------------------------"<<endl;
	cout<<"-     Liberary Book Info Manager     -"<<endl;
	cout<<"--------------------------------------"<<endl<<endl;
	cout<<"Coded By : "<<CODER<<endl;
	cout<<"Submitted To : "<<SUBMITTED_TO<<endl;
	cout<<"Institution : "<<INSTITUTION<<endl;
	pause();
}

// defining pause function
void pause()
{
	cout<<"\n\n[!] Press Enter To Continue . . .";
	cin.get();   // get is used to with untill and unless enter key is not pressed
}

// defining clrscr function
void clrscr()
{ 
	system(CLEAR);   // function defined in cstdlib to run system commands
}

// defining menu function
int menu()
{
	int opt;
	clrscr();
	cout<<"--------------------------------------"<<endl;
	cout<<"-                Menu                -"<<endl;
	cout<<"--------------------------------------"<<endl<<endl;
	cout<<"1. Add New Detail"<<endl;
	cout<<"2. Delete Existing"<<endl;
	cout<<"3. Search"<<endl;
	cout<<"4. List All"<<endl;
	cout<<"5. Modify Existing"<<endl;
	cout<<"6. Exit"<<endl;
	cout<<"> ";
	cin>>opt;
	cin.ignore(); // ignoring input stream buffer
	return opt;
}