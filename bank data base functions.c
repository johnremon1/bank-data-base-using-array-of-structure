



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
    int temp=0;
    char debit_or_credit[7];
    printf("please enter the following information :\n");
    printf("name : ");
    gets(temporary.name);
    printf("\nid : ");
    scanf("%i",&temp);
    if (temp>0)
   {
    temporary.id=temp;
    temp=0;
    }
    positive_cash_in_creat:
    printf("\ninput cash : ");
    fflush(stdin);
    scanf("%i",&temp);
    if (temp>0)
    {
    temporary.cash=temp;
    temp=0;
    }
    else
    {
        printf("you entered a negative cash and that is forbidden");
        goto positive_cash_in_creat;
    }

    true_type_in_creat://the label is for enter a true type of the account
    printf("\ntype (debit or credit) : ");
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

