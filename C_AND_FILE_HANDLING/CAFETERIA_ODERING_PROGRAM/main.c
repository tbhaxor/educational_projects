#include <stdio.h>
#include <stdlib.h>
#include "config.h"

// function prototyping
int get_invoice_number();
void create_order();
void delete_order(int);
void list_all();
void search_order(int);
void clrscr();
void menu();
void info();
void pause();

// customer details 
struct Customer {
    char name[30];
    int pno;
    int invoice;
};

// Order Datatype to be stored
struct Order {
    char item[30];
    float price;
    int quantity;
    int invoice;
};

int main() {
    int opt;
    info();
    while(1) {
        menu();  // printing menu
        scanf("%d", &opt);  // getting user input for option 
        switch(opt) {
        case 1:  // case to create order
            break;
        case 2:  // case to delete existing order
            break;
        case 3:  // case to display all the details
            break; 
        case 4:  // case to search order from the db
            break;
        case 5:
            return 0;  // exit program on user selection = 5 i.e Exit
        default:

        }
        pause() // pausing the output screen
    }
}

// function info definition for printing coder details
void info() {
    clrscr();  // clearing screen
    printf("------------------------------------------------\n");
    printf("-         Cafeteria Management Program         -\n");
    printf("------------------------------------------------\n\n");

    // printing details from config.h
    printf("Coded By : %s\n", CODER);
    printf("Submitted To : %s\n", SUBMITTED_TO);
    printf("Institution : %s\n", INSTITUTION);
    pause();  // pausing screen output
}

// function pause definition for pausing the output screen
void pause() {
    printf("[!] Press any key to continue ...");
    getchar();  // wait until enter is pressed
}

// function clrscr definition for clear output screen
void clrscr() {
    system(CLEAR);  // running system command to clear the screen
}

// function menu to display available functions
void menu() {
    clrscr(); // clearing screen
    printf("------------------------------------------------\n");
    printf("-                     MENU                     -\n");
    printf("------------------------------------------------\n\n");
    printf("1. Create New Order\n");
    printf("2. Delete Existing Order\n");
    printf("3. Display All Orders\n");
    printf("4. Search Order\n");
    printf("5. Exit\n");
    printf("> ");
}