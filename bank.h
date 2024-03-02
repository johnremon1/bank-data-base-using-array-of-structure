#define total_customer_number 2

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
void take_or_add_money(struct customer (*ptr)[total_customer_number]);
void cash_transfer(struct customer (*ptr)[total_customer_number]);
void exit_function();



