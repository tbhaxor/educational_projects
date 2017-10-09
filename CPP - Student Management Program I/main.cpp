#include <iostream>
#include <cstdlib>
using namespace std;
struct Student
{
	string rollno,name,address;
	Student *next;
};
void intro()
{
	system("cls");
	cout<<"\n\t\t\t######################################";
	cout<<"\n\t\t\t##                                  ##";
	cout<<"\n\t\t\t## Project - Pointer Demo of Stacks ##";
	cout<<"\n\t\t\t##                                  ##";
	cout<<"\n\t\t\t######################################\n\n\n";
	cout<<"\nCoded By - Gurkirat";
	cout<<"\nCollege Name - ABCD";
	cout<<"\n\n";
	system("pause");
}
void menu()
{
	system("cls");
	cout<<"\n\t\t\t######################################";
	cout<<"\n\t\t\t##                                  ##";
	cout<<"\n\t\t\t##              Menu                ##";
	cout<<"\n\t\t\t##                                  ##";
	cout<<"\n\t\t\t######################################\n\n\n";
	cout<<"\n1. Add New";
	cout<<"\n2. Delete";
	cout<<"\n3. Modify";
	cout<<"\n4. List All";
	cout<<"\n5. Quit";
	cout<<"\n-> ";
}
int main() 
{
	int opt;
	intro();
	Student *temp=NULL,*start=NULL;
	while(true)
	{
		menu();
		cin>>opt;
		cin.ignore(1);
		switch(opt)
		{
			case 5:
				return 0;
				break;
			case 1:
			
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			
		}		
	}	
	return 0;
}
