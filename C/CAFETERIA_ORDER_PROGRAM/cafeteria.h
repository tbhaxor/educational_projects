#ifndef CAFETERIA
#define CAFETERIA

#include "config.h"

struct Customer
{
    char name[30];
    long pno;
};

struct Order
{
    char item[30];
    float price;
    int quantity;
    int invoice;
    int isPaid;
};

struct Cafeteria
{
    struct Order order;
    struct Customer customer;
} c[MAX_SIZE];
int top = -1;
#endif