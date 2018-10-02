#include <stdio.h>
#include "actor.h"

int main()
{
    info(); // calling info function to show coder details
    while (1)
    {
        switch (menu())
        {
        case 1:
            clear();  // clearing output screen
            addNew(); // calling function to add new order
            break;
        case 2:
            clear();     // clearing output screen
            deleteOld(); // calling function to delete order
            break;
        case 3:
            clear();   // clearing output screen
            showall(); // calling function to show all order
            break;
        case 4:
            clear();  // clearing output screen
            search(); // calling function to search an order
            break;
        case 5:
            return 0; // exiting of option selected 6
        default:
            printf("Invalid Input");
        }

        // pausing with message
        printf("\n\nPress any key to continue");
        getchar();
    }
}