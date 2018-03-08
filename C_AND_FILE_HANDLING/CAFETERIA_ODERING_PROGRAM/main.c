#include <stdio.h>
#include <stdlib.h>
#include "config.h"
#include <stdbool.h>

// function prototyping
void create_order();
void delete_order();
void list_all();
void search_order();
void clrscr();
void menu();
void info();
void pause();
void clear_input_buffer();

// customer details 
struct Customer {
    char name[30];
    long pno;
    int invoice;
};

// Order Datatype to be stored
struct Order {
    char item[30];
    float price;
    int quantity;
    int invoice;
};

// Main function
int main() {
    int opt;
    info();
    while(1) {
        menu();  // printing menu
        scanf("%d", &opt);  // getting user input for option
        clear_input_buffer();  // flushing input buffer
        switch(opt) {
        case 1:  // case to create order
            create_order(); // this call will create an order and store in a db
            break;
        case 2:  // case to delete existing order
            delete_order(); // this call will delete an order
            break;
        case 3:  // case to display all the details
            list_all(); // this call will display all the details
            break;
        case 4:  // case to search order from the db
            break;
        case 5:
            return 0;  // exit program on user selection = 5 i.e Exit
        default:
            printf("[x] Wrong input");
        }
        pause(); // pausing the output screen
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
    printf("\n[!] Press enter key to continue ...");
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

// function clear_input_buffer definition clear input buffer
void clear_input_buffer() {
    while ((getchar()) != '\n');
}

// function create_order to create an order
void create_order() {
    clrscr(); // clearing screen
    printf("------------------------------------------------\n");
    printf("-              Creating New Order              -\n");
    printf("------------------------------------------------\n\n");
    FILE *customer, *order;                // defined two FILE class pointer
    customer = fopen(MAIN_FILE_C, "ab"); // creating the output file stream in append binary for customer
    order = fopen(MAIN_FILE_O, "ab"); // creating the output file stream in append binary for order
    struct Customer c;  // object of Customer type
    struct Order o;   // object of Order type
    int inv_number = 0;
    printf("enter order number : ");
    scanf("%d", &inv_number);
    clear_input_buffer();    // clearing input buffer
    c.invoice = inv_number;  // storing invoice number in customer as a unique key
    o.invoice = inv_number;  // storing invoice number in order as a unique key
    
    // getting values for Customer and  Order
    printf("enter item name : ");
    gets(o.item); // getting item name
    printf("enter item price : ");
    scanf("%f", &o.price);  // getting price per peice
    clear_input_buffer(); // clearing input buffer
    printf("enter item quantity : ");
    scanf("%d", &o.quantity);  // getting number of items purchased
    clear_input_buffer();  // clearing input buffer
    printf("enter customer name : ");
    gets(c.name);   // getting customer name
    printf("enter customer number : ");
    scanf("%ld", &c.pno);  // getting customer phone number
    clear_input_buffer(); // clearing input buffer

    // writing data to files
    fwrite(&c, sizeof(struct Customer), 1, customer);
    fwrite(&o, sizeof(struct Order), 1, order);
    fclose(customer); // closing output file stream for customer
    fclose(order);  // closing output file stream for order
}

// function list_all to print all the details
void list_all() {
    clrscr(); // clearing screen
    printf("------------------------------------------------\n");
    printf("-            Displaying All Details            -\n");
    printf("------------------------------------------------\n\n");
    FILE *customer, *order; // defined two FILE class pointer
    customer = fopen(MAIN_FILE_C, "r"); // creating the input file stream for customer
    order = fopen(MAIN_FILE_O, "r");    // creating the input file stream  for order
    struct Customer c;  // object of Customer type
    struct Order o;     // object of Order type
    while (fread(&c, sizeof(struct Customer), 1, customer) && fread(&o, sizeof(struct Order), 1, order)){
        printf("Order Number : %d\n", c.invoice);
        printf("Customer Name : %s\t\tCustomer Phone Number : %ld\n", c.name, c.pno);
        printf("Item Name : %s\n", o.item);
        printf("Item Quantity : %d\t\tTotal Cost : %.2f\n", o.quantity, o.quantity * o.price);
        printf("----------------------------------------------\n");
    }
    fclose(customer); // closing input file stream for customer
    fclose(order);      // closing  input file stream for order
    
}

// function delete_order definition to delete existing details
void delete_order() {
    clrscr(); // clearing screen
    printf("------------------------------------------------\n");
    printf("-                 Delete Order                 -\n");
    printf("------------------------------------------------\n\n");
    int i; // variable for storing invoice number
    bool found = false; // setting found to false, order not found
    struct Customer c;  // object of Customer type
    struct Order o;     // object of Order type
    printf("enter order number : ");
    scanf("%d", &i); // getting order number from user
    clear_input_buffer(); // clearing input buffer
    FILE *customer, *order, *to, *tc; // defined two FILE class pointer
    customer = fopen(MAIN_FILE_C, "r"); // creating the input file stream for customer
    order = fopen(MAIN_FILE_O, "r");    // creating the input file stream  for order
    tc = fopen(TEMP_FILE_c, "w"); // creating the output file stream in append binary for customer temp
    to = fopen(TEMP_FILE_o, "w");    // creating the output file stream in append binary for order temp
    while (fread(&c, sizeof(struct Customer), 1, customer) && fread(&o, sizeof(struct Order), 1, order)){
       if(c.invoice == i && o.invoice == i){
           found = true;
       }
       else {
           fwrite(&c, sizeof(struct Customer), 1, tc);
           fwrite(&o, sizeof(struct Order), 1, to);
       }
    }
    fclose(customer); // closing input file stream for customer
    fclose(order);    // closing  input file stream for order
    fclose(tc); // closing output file stream for customer
    fclose(to);    // closing  output file stream for order
    remove(MAIN_FILE_C); // deleting old db file for customer
    remove(MAIN_FILE_O); // deleting old db file for order
    rename(TEMP_FILE_c, MAIN_FILE_C); // renaming temp file to main file for customers
    rename(TEMP_FILE_o, MAIN_FILE_O); // renaming temp file to main file for orders
}