// including header files and libraries
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
	// invoking intro function
	intro();
	while(true)   // running the loop body infinitely on selection
	{
		switch(menu())   // calling menu function and handling selctions using switch case
		{
			case 6:
				return 0;    // exiting if user selects 6
			
			case 1:
				clrscr();    // clearing output screen
				cout<<"--------------------------------------"<<endl;
				cout<<"-           Add New Entry            -"<<endl;
				cout<<"--------------------------------------"<<endl<<endl;
				// invoking add_new function of Actor namespace in actor.h
				add_new();
				break;
			case 2:
				clrscr();    // clearing output screen
				cout<<"--------------------------------------"<<endl;
				cout<<"-        Delete Existing Entry       -"<<endl;
				cout<<"--------------------------------------"<<endl<<endl;
				// invoking delete_existing function of Actor namespace in actor.h
				delete_existing();
				break;
			case 3:
				clrscr();    // clearing output screen
				cout<<"--------------------------------------"<<endl;
				cout<<"-            Search By ID            -"<<endl;
				cout<<"--------------------------------------"<<endl<<endl;
				// invoking search_by_id function of Actor namespace in actor.h
				search_by_id();
				break;
			case 4:
				clrscr();    // clearing output screen
				cout<<"--------------------------------------"<<endl;
				cout<<"-          List All Entries          -"<<endl;
				cout<<"--------------------------------------"<<endl<<endl;
				// invoking list_all_entries function of Actor namespace in actor.h
				list_all_entries();
				break;
			case 5:
				clrscr();    // clearing output screen
 				cout<<"--------------------------------------"<<endl;
				cout<<"-       Modify Existing Entry        -"<<endl;
				cout<<"--------------------------------------"<<endl<<endl;
				// invoking modify_existing_entry function of Actor namespace in actor.h
				modify_existing_entry();
				break;
		}
		pause();   // pausing output screen
	}
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