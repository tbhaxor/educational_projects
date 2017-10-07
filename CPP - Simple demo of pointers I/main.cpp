#include <iostream>
#include <cstdlib> // for clearing screen
using namespace std;
struct Student
{
	int roll_no;
	string name,address,dob;
	Student *next;	
};
void info()
{
	cout<<"\n\t\t\t------- Coder Info -------\n\n"<<endl;
	cout<<"Coded By : <enter name here>"<<endl;
	cout<<"Submitted To : <enter name here>"<<endl;
	cout<<"Institution Name : <enter name here>"<<endl;
	cout<<"\n\n[!] Press Any Key ...";
	cin.get();
}
void menu()
{
	system("cls");
	cout<<"\n\t\t\t\t----- Menu -----\n\n";
	cout<<"\n\n1. Add New";
	cout<<"\n\n2. Delete By ROLL NUMBER";
	cout<<"\n\n3. Modify By ROLL NUMBER";
	cout<<"\n\n4. List All";
	cout<<"\n\n5. Quit\n\n->";
}
int main() 
{
	info();
	int opt;
	Student *student=NULL,*temp=NULL;
	while(true)
	{
		menu();
		cin>>opt;
		cin.ignore(1);
		if (opt==5) break;   // will quit if opt = 5
		switch(opt)
		{
			case 1:
				system("cls");
				cout<<"-- New Entry Addition Portal --\n\n";
				if(student==NULL)
				{
					temp=new Student();
					cout<<"\n\nenter roll number : ";
					cin>>temp->roll_no;
					cin.ignore(1);
					cout<<"\n\nenter name : ";
					getline(cin,temp->name);
					cout<<"\n\nenter dob (DD/MM/YYY) : ";
					getline(cin,temp->dob);
					cout<<"\n\nenter address : ";
					getline(cin,temp->address);
					temp->next=NULL;
					student = temp;
					delete(temp);
				}
				else
				{
					temp
				}
				break;
		}		
	}
	return 0;
}
