#include <iostream>
#include "config.h"
#include <cstdlib>
using namespace std;

// making a user defined data type for Student Details
struct Student
{
	int rollno;
	float marks[TOTAL_SUBJECTS], average;
	char name[30], email[30];
	long unsigned int phoneNumber;
	Student* next;
};

// prototyping functions
int menu();
void pause();
void info();
float average(float []);

// Main Function
int main()
{
	Student *st = NULL;    // main pointer to maintain and keep records
	Student *tmp = NULL;   // temporary pointer to handle traversing and etc 

	info();   // calling info function
	while(true)   // iterating infinitly
	{
		switch(menu()) // calling menu function and using switch-case to handle selection
		{
			case 5:
				return 0;  // exiting with 0 status code if user selects 5
			case 1:
				system(CLEAR);  // clearing output screen
				cout<<"------------------------------------"<<endl;
				cout<<"-      Add New Student Details     -"<<endl;
				cout<<"------------------------------------"<<endl<<endl;
				tmp = new Student;  // allocating memory to temporary pointer
				// getting values for student
				cout<<"enter roll number : ";
				cin>>tmp->rollno;
				cin.ignore();   // ignoring input stream buffer
				cout<<"enter name : ";
				cin.getline(tmp->name, 30);
				cout<<"enter email : ";
			        cin.getline(tmp->email, 30);
				cout<<"enter phone number : ";
				cin>>tmp->phoneNumber;
				cin.ignore();   // ignoring input stream buffer
				cout<<"enter marks of 5 subjects \n";
				for(int i = 0; i < TOTAL_SUBJECTS; i++)
					cin>>tmp->marks[i];
				cin.ignore();  // ignoring input stream buffer
				tmp->average = average(tmp->marks);
				cout<<"calculated average : "<<tmp->average;

				// now adding data to stack
				if (st == NULL)       
				{
					st = new Student;
					tmp->next = NULL;
					st = tmp;
				}
				else
				{
					tmp->next = st;
					st = tmp;
				}
				delete tmp;    // deallocating memory to temporary pointer
				break;
			case 2:
				system(CLEAR);  // clearing output screen
				break;
			case 3:
				system(CLEAR);   // clearing output screen
				cout<<"------------------------------------"<<endl;
				cout<<"-    Listing All Student Details   -"<<endl;
				cout<<"------------------------------------"<<endl<<endl;
				if(st == NULL)
				{
					cout<<"[!] No student has been added yet";
				}
				else
				{
					tmp = new Student;
					tmp = st;
					while(tmp!=NULL)
					{
						cout<<tmp->name<<endl;
						tmp = tmp->next;
					}
					delete tmp;
				}
				break;
			case 4:
				system(CLEAR);   // clearing output screen
				break;
			default:
				cout<<"[!] Wrong Selection";	
		}
		pause();
	}
}

// defining info
void info()
{
	system(CLEAR);  // clearing output screen
	cout<<"------------------------------------"<<endl;
	cout<<"-    Student Information Manager   -"<<endl;
	cout<<"------------------------------------"<<endl<<endl;
	cout<<"Coded By : "<<CODER<<endl;
	cout<<"Submitted TO : "<<SUBMITTED_TO<<endl;
	cout<<"Institution : "<<INSTITUTION<<endl;
	pause();
}

// defining pause
void pause()
{
	cout<<"\n\n[!] Press Enter To Continue . . .";
	cin.get();
}

// defining average
float average(float marks[])
{
	float sum = 0;  // initializing sum
	float len = TOTAL_SUBJECTS;  // getting the length of array of marks

	for(int i = 0; i < len; i++) sum += marks[i];  // adding all the marks

	return (sum / len);   // dividing by total subjects
}

// defining menu
int menu()
{
	int opt;
	system(CLEAR);    // clearing output screen
	cout<<"------------------------------------"<<endl;
	cout<<"-              MENU                -"<<endl;
	cout<<"------------------------------------"<<endl<<endl;
	cout<<"1. Add New"<<endl;
	cout<<"2. Delete Existing"<<endl;
	cout<<"3. List All"<<endl;
	cout<<"4. Search"<<endl;
	cout<<"5. Exit"<<endl;
	cin>>opt;
	cin.ignore();  // ignoring input stream buffer
	return opt;
}
