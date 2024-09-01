#include <stdio.h>
#include <string.h>

struct account{
int acc_no;
char acc_type;
int name[80];
float balance;
};
void main()
{
    struct account old_customer , new_customer;
    old_customer.acc_no=12345;
    new_customer.acc_no=2367;
    old_customer.acc_type='S';
    new_customer.acc_type='L';

    strcpy(old_customer.name,"Eshita Das");
    strcpy(new_customer.name,"Ritu Banerjee");

    old_customer.balance=2500.56;
    new_customer.balance=6789.23;
    

}