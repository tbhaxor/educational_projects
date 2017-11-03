// including standard header file an liberar
#include <iostream>
using namespace std;


// including local header files and liberaries
#include "config.h"
using namespace Config;
#include "bank.h"

int main()
{
  // info();
  Bank *account = NULL;
  while(true)
  {
    switch (menu())
    {
      case 1:
        cout<<"lol";
        break;

      case 2:
        cout<<"lolwa";
        break;

      case 6:
        return 0;
      default:
        cout<<"[!] Info - Option not valid";
    }
    pause();
  }
}
