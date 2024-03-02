#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define total_customer_number 3

struct customer
{
    char name[30];//to hold the name of the customer
    double cash;//to hold the cash of the customer
    int  id;//to hold the id of the customer
    char type[7];//to hold the type of the account if it is debit or credit
    bool taken;//this variable if for knowing if this variable is taken or not
};

void create_a_new_customer(struct customer (*ptr)[total_customer_number]);// we sent addresses so we will receive  in pointers
void edit_a_customer_data(struct customer (*ptr)[total_customer_number]);
void print_a_customer_data(struct customer (*ptr)[total_customer_number]);
void delete_a_customer_data(struct customer (*ptr)[total_customer_number]);
void cash_transfer(struct customer (*ptr)[total_customer_number]);
void exit_function(int *ptr);




int main()
{
struct customer c[total_customer_number];

bool exit;
exit=1;
while(exit)
{
    int choice=0;

   struct customer customer[total_customer_number];
   printf("\n\nplease choose a choice :\n");
   printf("1- create a new customer <please enter 1>\n2-edit a customer data <please enter 2>\n");
   printf("3- delete a customer data <please enter 3>\n4- print a customer data <please enter 4>\n");
   printf("5- cash transfer <please enter 5>\n6- exit the program <please enter 6>\n ");
   printf("\nyour choice is : ");
   fflush(stdin);
   scanf ("%d",&choice);
   printf("\n");
   switch (choice)
   {
    case 1:
     create_a_new_customer(&c[total_customer_number]);
    break;

    case 2:
      edit_a_customer_data(&c[total_customer_number]);
    break;

    case 3:
    delete_a_customer_data(&c[total_customer_number]);
    break;

    case 4:
     print_a_customer_data(&c[total_customer_number]);
    break;

    case 5:
     cash_transfer(&c[total_customer_number]);
    break;

    case 6:
     exit_function(&exit);
      return 0;
      break;

    default:
    printf ("you entered a wrong number \n");


   }

}
    return 0;
}





void create_a_new_customer( struct customer (*ptr)[total_customer_number])
{

bool for_counter;
for_counter=0;
struct customer temporary;
for (int i=0;i<=(total_customer_number-1);i++)
{
 if ((ptr[i]->taken)==0)
 {
    fflush(stdin);
    int temp1=0;
    char debit_or_credit[7];
    printf("please enter the following information :\n");
    printf("name : ");
    gets(temporary.name);
    printf("id : ");
    scanf("%i",&temp1);
    if (temp1>0)
   {
    temporary.id=temp1;
    temp1=0;
    }
    positive_cash_in_creat:
    printf("input cash : ");
    double temp2=0;
    fflush(stdin);
    scanf("%lf",&temp2);
    if (temp2>0)
    {
    temporary.cash=temp2;
    temp2=0;
    }
    else
    {
        printf("you entered a negative cash and that is forbidden");
        goto positive_cash_in_creat;
    }

    true_type_in_creat://the label is for enter a true type of the account
    printf("type (debit or credit) : ");
    fflush(stdin);
    gets(debit_or_credit);
    if ((!(strcmp(debit_or_credit,"debit")))||(!(strcmp(debit_or_credit,"credit"))))
        {

            strcpy(temporary.type,debit_or_credit);

        }
    else
        {
            printf("you entered a wrong input please re input ");
            goto true_type_in_creat;
        }
    temporary.taken=1;
    for_counter++;
    *ptr[i]=temporary;
    break ;
 }
}

if (for_counter==0)
{
    printf("you have reached the max number of customer :\n");
}
}



void print_a_customer_data(struct customer (*ptr)[total_customer_number])
{
  struct customer temporary;
  int temp_id;
  bool for_counter;
  for_counter=0;
 printf("please enter the customer id :\n");
 scanf("%i",&temp_id);
 fflush(stdin);
 for (int i=0;i<(total_customer_number);i++)
 {

     if (temp_id==(ptr[i]->id))
     {
         temporary=*ptr[i];
         printf("*****************************\n");
         printf ("name : %s",temporary.name);
         printf ("\nid   : %i",temporary.id);
         printf ("\ncash : %0.2f LE",temporary.cash);
         printf ("\ntype : %s",temporary.type);
         printf("\n*******************************");
         for_counter=1;
     }
 }
 if (for_counter==0)
 {
     printf("no match for this id :\n ");
 }
}


void edit_a_customer_data(struct customer (*ptr)[total_customer_number])
{
    int temp_id;
    bool for_counter;
    for_counter=0;
    printf("please enter the id of the customer you want to edit : \n");

    scanf("%i",&temp_id);

    for (int i=0;i<=(total_customer_number-1);i++)
    {
       if (ptr[i]->id==temp_id)
       {
          double temp_for_cash=0;
          fflush(stdin);
          printf("please enter the new information :\n");
          printf("name : ");
          gets(ptr[i]->name);
          fflush(stdin);
    positive_cash_in_creat:
    printf("input cash : ");
    double temp2=0;
    fflush(stdin);
    scanf("%lf",&temp2);
    if (temp2>0)
    {
    ptr[i]->cash=temp2;
    }
    else
    {
        printf("you entered a negative cash and that is forbidden");
        goto positive_cash_in_creat;
    }
    char debit_or_credit[7];//this for testing if the user insert a right spelling
    true_type_in_creat://the label is for enter a true type of the account
    printf("type (debit or credit) : ");
    fflush(stdin);
    gets(debit_or_credit);
    if ((!(strcmp(debit_or_credit,"debit")))||(!(strcmp(debit_or_credit,"credit"))))
        {

            strcpy(ptr[i]->type,debit_or_credit);

        }
    else
        {
            printf("you entered a wrong input please re input ");
            goto true_type_in_creat;
        }
        ptr[i]->taken=1;
           for_counter=1;
       }

if (for_counter==0)
{
    printf("no match for id \n");
}
    }
}

void delete_a_customer_data(struct customer (*ptr)[total_customer_number])
{
    struct customer temporary;
    bool for_counter;
    for_counter=0;
    printf("please enter the id of the customer you want to delete : \n");
    scanf("%i",&temporary.id);
    for(int i=0;i<=(total_customer_number-1);i++)
    {
        if (temporary.id==ptr[i]->id)
        {
            strcpy(temporary.name,ptr[i]->name);
            strcpy(ptr[i]->name,"empty customer");
            ptr[i]->id=0;
            ptr[i]->cash=0;
            strcpy(ptr[i]->type,"empty ");
            ptr[i]->taken=0;
            printf("the customer %s with id %i has been deleted",temporary.name,temporary.id);

            for_counter=1;
        }
    }
if (for_counter==0)
{
    printf("\nnno match for id\n");
}

}

void cash_transfer(struct customer (*ptr)[total_customer_number])
{
    int sender_id;
    int receiver_id;
    int sender_number=500;
    int receiver_number=500;
    double amount_of_cash=0;
    wrong_id://this label is for re input the ids
    printf ("please enter the id of the sender : \n");
    fflush(stdin);
    scanf("%i",&sender_id);
    printf("please enter the id of the receiver : \n");
    fflush(stdin);
    scanf("%i",&receiver_id);
    printf("please enter the amount of cash the the sender will send to the receiver : \n");
    fflush(stdin);
    scanf("%lf",&amount_of_cash);
    bool for_counter_sender;
    bool for_counter_receiver;
    for_counter_sender=0;
    for_counter_receiver=0;
    for (int i=0;i<=(total_customer_number-1);i++)
    {

        if (sender_id==ptr[i]->id)
        {
            sender_number=i;
            for_counter_sender=1;
            break ;
        }
    }
     for (int i=0;i<=(total_customer_number-1);i++)
     {
        if (receiver_id==ptr[i]->id)
        {
            receiver_number=i;
            for_counter_receiver=1;
            break ;
        }
     }

    if ((for_counter_receiver==1)&&(for_counter_sender==1))
    {
        if ((ptr[sender_number]->cash)>amount_of_cash)
        {
            ptr[sender_number]->cash=ptr[sender_number]->cash-amount_of_cash;
            ptr[receiver_number]->cash=ptr[receiver_number]->cash+amount_of_cash;
        }

    }
    if (for_counter_receiver==0)
    {
        printf("you entered a wrong receiver id please re enter the two ids :\n");
        goto wrong_id;
    }
    if (for_counter_sender==0)
    {
        printf("you entered a wrong sender id please re enter the two ids :\n");
        goto wrong_id;
    }

}

void exit_function(int *ptr)
{

  *ptr=0;
}







