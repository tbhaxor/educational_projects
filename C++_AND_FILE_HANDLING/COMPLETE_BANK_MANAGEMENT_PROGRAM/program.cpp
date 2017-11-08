// including header files and liberaries
#include <iostream>
#include "config.h"
#include "actions.h"
using namespace std;
using namespace Actions;

// prototyping
void info();
void pause();
void clrscr();
int menu();

// main function
int main()
{
  // invoking info function
  // info();
  // infinite loop which will be breaked if user selects 9
  while(true)
  {
    // switching menu selections from switch - case
    switch(menu())
    {
      case 1:
        // invoking add_new function
        add_new();
      break;
      case 2:
        // invoking del_ete function
        del_ete();
      break;
      case 3:
        // invoking modify function
        modify();
      break;
      case 4:
        // invoking create_trans function
        create_trans();
      break;
      case 5:
        // invoking show_trans function
        show_trans();
      break;
      case 6:
        // invoking show_all function
        show_all();
      break;
      case 7:
        // invoking search function
        search();
      break;
      case 8:
        // part_trans add_new function
        part_trans();
      break;
      case 9:
        // exiting the program
        return 0;
      break;
      default:
        cout<<"[!] Wrong Input Selection";
    }
    pause();
  }
}

// function definition of pause - holds the output until enter key is not pressed
void pause()
{
  cout<<"\n\n[!] Press Enter To Continue . . . ";
  cin.get();
}

// function definition of clrscr - clears the output screen
void clrscr()
{
  system(CLEAR);
}

// function definition of info - displays the coder name and etc
void info()
{
  clrscr();
  cout<<"\t\t\t __________________________________________________ "<<endl;
  cout<<"\t\t\t|                                                  |"<<endl;
  cout<<"\t\t\t|            Bank Management Program               |"<<endl;
  cout<<"\t\t\t|__________________________________________________|"<<endl<<endl<<endl;
  cout<<"Coded By : "<<CODER<<endl;
  cout<<"Submitted To : "<<SUBMITTED_TO<<endl;
  cout<<"Institution : "<<INSTITUTION<<endl;
  pause();
}

// function definition of menu - displays the menu and returns the selection
int menu()
{
  int opt;
  clrscr();
  cout<<"\t\t\t __________________________________________________ "<<endl;
  cout<<"\t\t\t|                                                  |"<<endl;
  cout<<"\t\t\t|                       Menu                       |"<<endl;
  cout<<"\t\t\t|__________________________________________________|"<<endl<<endl<<endl;
  cout<<"1. Add New Account"<<endl;
  cout<<"2. Delete Account"<<endl;
  cout<<"3. Modify Account"<<endl;
  cout<<"4. Create New Transaction"<<endl;
  cout<<"5. View All Transactions"<<endl;
  cout<<"6. View All Account Holder's details"<<endl;
  cout<<"7. Search Account"<<endl;
  cout<<"8. Get Transaction (for particular account)"<<endl;
  cout<<"9. Quit"<<endl;
  cout<<"> ";
  cin>>opt;
  cin.ignore();  // clearing input stream buffer
  return opt;
}
