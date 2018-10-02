#ifndef CAFETERIA
#define CAFETERIA

#include "config.h"

// schema for customer
struct Customer
{
    char name[30];
    long pno;
};

// schema for order placed
struct Order
{
    char item[30];
    float price;
    int quantity;
    int invoice;
    int isPaid;
};

// schema for Cafeteria
struct Cafeteria
{
    struct Order order;
    struct Customer customer;
} c[MAX_SIZE];
int top = -1; // top
#endif