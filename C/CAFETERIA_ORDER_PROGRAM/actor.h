#if !defined(ACTOR)
#define ACTOR

#include "cafeteria.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
void clear()
{
    if (system("clear") != 0)
        system("cls");
}

void flush()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

int menu()
{
    clear();
    printf("==================================\n");
    printf("==             MENU             ==\n");
    printf("==================================\n\n");
    printf("1. Add new order");
    printf("\n2. Delete order");
    printf("\n3. Edit order");
    printf("\n4. Show all order");
    printf("\n5. Search order");
    printf("\n6. Quit");
    printf("\n> ");
    int opt;
    scanf("%d", &opt);
    flush();
    return opt;
}

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

void addNew()
{
    ++top;
    if (top > MAX_SIZE)
    {
        printf("Buffer Overflow");
        exit(1);
    }
    srand(time(NULL));
    printf("==================================\n");
    printf("==            ADD NEW           ==\n");
    printf("==================================\n\n");
    c[top].order.invoice = (rand() % 99999999 + 1);
    printf("enter name: ");
    fgets(c[top].customer.name, 30, stdin);
    printf("enter phone number: ");
    scanf("%ld", &c[top].customer.pno);
    flush();
    printf("invoice: %d\n", c[top].order.invoice);
    printf("enter item name: ");
    fgets(c[top].order.item, 30, stdin);
    strtok(c[top].order.item, '\n');
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

void deleteOld()
{
}

void search()
{
}

void modify()
{
}

void showall()
{
    printf("==================================\n");
    printf("==      SHOWING ALL ORDERS      ==\n");
    printf("==================================\n\n");
    printf("%s", c[0].order.item);
    printf("%s", c[0].customer.name);
    return;
    for (int i = 0; i < top + 1; i++)
    {
        printf("Invoice: %d\n", c[i].order.invoice);
        printf("Customer Name: %sPhone Number: %ld\n", c[i].customer.name, c[i].customer.pno);
        printf("Order: %s", c[i].order.item);
        printf("Quantity: %d\n", c[i].order.quantity);
        printf("Price: %f\n", c[i].order.price);
        if (c[i].order.isPaid)
        {
            printf("Status: Paid");
        }
        else
        {
            printf("Status: Not Paid");
        }
        printf("\n------------------------------------------------------\n");
    }
}
#endif // ACTOR
