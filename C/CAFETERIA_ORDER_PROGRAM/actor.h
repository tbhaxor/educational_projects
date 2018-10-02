#if !defined(ACTOR)
#define ACTOR

#include "cafeteria.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/**
 * Function to print order details
 * 
 * */
void printOrder(int i)
{
    printf("Invoice: %d\n", c[i].order.invoice);
    printf("Customer Name: %s\tPhone Number: %ld\n", c[i].customer.name, c[i].customer.pno);
    printf("Order: %s\n", c[i].order.item);
    printf("Quantity: %d\t\t", c[i].order.quantity);
    printf("Price: %.2f\n", c[i].order.price);
    if (c[i].order.isPaid)
    {
        printf("Status: Paid");
    }
    else
    {
        printf("Status: Not Paid");
    }
}

/**
 * Clear output screen
 * 
 * */
void clear()
{
    if (system("clear") != 0)
        system("cls");
}

/**
 * Clears input Buffer
 * 
 * */
void flush()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

/**
 * Prints menu and returns user selection
 * 
 * */
int menu()
{
    clear();
    printf("==================================\n");
    printf("==             MENU             ==\n");
    printf("==================================\n\n");
    printf("1. Add new order");
    printf("\n2. Delete order");
    printf("\n3. Show all order");
    printf("\n4. Search order");
    printf("\n5. Quit");
    printf("\n> ");
    int opt;
    scanf("%d", &opt);
    flush();
    return opt;
}

/**
 * Prints banner and info of coder
 * 
 * */
void info()
{
    clear();
    printf("==================================\n");
    printf("== CAFETERIA MANAGEMENT PROGRAM ==\n");
    printf("==================================\n\n");
    printf("Coded By: %s\nSubmitted To: %s\nInstitution: %s\n\nPress any key to continue", NAME, SUBMITTED_TO, INSTITUTION);
    getchar();
    clear();
}

/**
 * Add new order
 * 
 * */
void addNew()
{
    ++top;
    srand(time(NULL));
    printf("==================================\n");
    printf("==            ADD NEW           ==\n");
    printf("==================================\n\n");
    if (top > MAX_SIZE)
    {
        printf("Buffer Overflow");
        return;
    }
    c[top].order.invoice = (rand() % 99999999 + 1);
    printf("enter name: ");
    fgets(c[top].customer.name, 30, stdin);
    c[top].customer.name[strcspn(c[top].customer.name, "\r\n")] = 0;
    printf("enter phone number: ");
    scanf("%ld", &c[top].customer.pno);
    flush();
    printf("invoice: %d\n", c[top].order.invoice);
    printf("enter item name: ");
    fgets(c[top].order.item, 30, stdin);
    c[top].order.item[strcspn(c[top].order.item, "\r\n")] = 0;
    printf("price (per item): ");
    float p;
    scanf("%f", &p);
    flush();
    printf("quantity: ");
    scanf("%d", &c[top].order.quantity);
    flush();
    c[top].order.price = p * c[top].order.quantity;
    printf("price: %.2f", c[top].order.price);
    printf("\npaid (1:yes, 0:now): ");
    scanf("%d", &c[top].order.isPaid);
    flush();
}

/**
 * Deleting existing order
 * 
 * */
void deleteOld()
{
    printf("==================================\n");
    printf("==         DELETE  ORDER         ==\n");
    printf("==================================\n\n");
    if (top == -1)
    {
        return;
    }
    int iv;
    printf("enter invoice number: \n");
    scanf("%d", &iv);
    flush();
    int found = 0;
    for (int i = 0; i <= top; i++)
    {
        if (c[i].order.invoice == iv)
        {
            if (i == top)
                found = 1;
            else
            {
                for (int j = i + 1; j <= top; j++)
                {
                    c[j - 1] = c[j];
                }
            }
            found = 1;
        }
    }
    if (!found)
    {
        printf("Not Found");
    }
    else
    {
        printf("Deleted");
        --top;
    }
}

/**
 * Searching order
 * */
void search()
{
    printf("==================================\n");
    printf("==         SEARCH ORDER         ==\n");
    printf("==================================\n\n");
    if (top == -1)
    {
        return;
    }
    int iv;
    printf("enter invoice number: \n");
    scanf("%d", &iv);
    flush();
    int found = 0;
    for (int i = 0; i <= top; i++)
    {
        if (c[i].order.invoice == iv)
        {
            printOrder(i);
            found = 1;
        }
    }
    if (!found)
    {
        printf("Not Found");
    }
}

/**
 * SHOWING all orders
 * 
 * 
 * */
void showall()
{
    printf("==================================\n");
    printf("==      SHOWING ALL ORDERS      ==\n");
    printf("==================================\n\n");
    for (int i = 0; i < top + 1; i++)
    {
        printOrder(i);
        printf("\n------------------------------------------------------\n");
    }
}

#endif // ACTOR
