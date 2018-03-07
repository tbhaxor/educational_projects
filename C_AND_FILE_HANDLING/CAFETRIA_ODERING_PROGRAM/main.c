#include <stdio.h>
#include <stdlib.h>
#include "config.h"

// function prototyping
int get_invoice_number();
void create_invoice();
void delete_invoice(int);
void list_all();
void search_invoice(int);
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
    return 0;
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

void pause() {
    printf("[!] Press any key to continue ...");
    getchar();  // wait until enter is pressed
}

void clrscr() {
    system(CLEAR);  // running system command to clear the screen
}