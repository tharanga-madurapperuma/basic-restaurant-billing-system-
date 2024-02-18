#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// MAP
/*
dashboard
    shop_name_and_details
    take_action
        1.menu
            read_menu_text_file
            print_menu
        2.buy_items
            print_menu
            choose_item
            enter_quentity
            check_for_other_items
            enter_quentity
            confirmation
            bill_print
        3.check_old_bills
            read_old_bills_text_file
            print_old_bills
        4.clear_old_bills
            fprintf with blank
        5.corders
*/

// GLOBAL VARIABLES
int user_action;

struct customer
{
    char name[100];
    int number_of_items;
    float sub_total;
    float net_amount;
    int month;
    int date;
    char time[20];
} customer[100];

struct item
{
    int item_number;
    char item_name[50];
    float item_price;
    float item_total;
    float item_quantity;
} items[100];

// FUNCTION PROTOTYPES
void dashboard();
void take_action();
void print_menu();
void buy_items();
void check_old_bills();
void exit_system();
void bill_print();
void clean_old_bills();
void owner_details();
void main_menu();

// ########################################################
//  MAIN FUNCTION
void main()
{
    system("cls");
    dashboard();
    // printf(' ');

    printf("\n\n\n\n\tEnter Your chioce(Number Only):\t\t");
    scanf("%d", &user_action);

    if (user_action == 1 || user_action == 2 || user_action == 3 || user_action == 4 || user_action == 5)
    {
        take_action();
    }
    else
    {
        printf("\n!!..You entered out of range charactor..!!!");
        main_menu();
    }
}
// ########################################################
//  PRINT RESTUARANT WELCOMR DASHBOARD
void dashboard()
{
    // HEADER
    printf("\033[036m\n\n\n\t\t\t\t\tWELCOME\n");
    printf("\t\t\t\t-----------------------\n");
    printf("\t\t\t\t   T S T RESTUARANT\n");
    printf("\t\t\t    -------------------------------\n");
    printf("\t\t\t\t- FOOD FEEL LIKE HOME -\n\n\n");

    // OPTIONS
    printf("\n\n\tTake an option");
    printf("\n\t\t1. Item Menu");
    usleep(300000);
    printf("\n\t\t2. Enter a New Bill");
    usleep(300000);
    printf("\n\t\t3. Old Bills");
    usleep(300000);
    printf("\n\t\t4. Clear Old Bills");
    usleep(300000);
    printf("\n\t\t5. Software Owner Details\033[0m");
    usleep(300000);

    // FOOTER
    printf("\033[92m\n\n\n\n\n\n\t\t\t%c\t    %cThranga Sandun\t\t%c", 177, 184, 177);
    usleep(300000);
    printf("\n\t\t\t%c\tFaculty of Science | UOK\t%c\033[0m", 177, 177);
    usleep(300000);
}

//*****************************************************
// WHAT HAPPENS AFTER USER ENTER A NUMBER
void take_action()
{
    switch (user_action)
    {
    case 1:
        system("cls");
        print_menu();
        break;
    case 2:
        system("cls");
        buy_items();
        break;
    case 3:
        system("cls");
        check_old_bills();
        break;
    case 4:
        system("cls");
        clean_old_bills();
        break;
    case 5:
        system("cls");
        owner_details();
        break;
    }
}

//*****************************************************
// USER ENTER NUMBER 1: THIS IS HAPPENING
void print_menu()
{
    char buffer[255];

    FILE *pf = fopen("menu.txt", "r");

    printf("\033[35m\n\tThis is the MENU\n");
    while (fgets(buffer, 255, pf) != NULL)
    {
        printf("\t\t%s", buffer);
    }
    printf("\033[0m");
    fclose(pf);

    main_menu();
    printf("\n\n\n\n\n\n");
}

//*****************************************************
// USER ENTER NUMBER 2: THIS IS HAPPENING
void buy_items()
{
    // FIRSTLY PRINT THE MENU
    char buffer[255];
    char more_items;
    char more_customers;
    int item_count;
    int i;
    int c = 0;

    do
    {
        system("cls");

        FILE *pf = fopen("menu.txt", "r");

        printf("\n\t\033[35mChoose Items from below menu\n");
        while (fgets(buffer, 255, pf) != NULL)
        {
            printf("\t\t%s", buffer);
        }
        printf("\033[0m");
        fclose(pf);

        printf("\n\n\n\tEnter customer name:\t");
        scanf("%s", &customer[c].name);
        printf("\tEnter the month:\t");
        scanf("%d", &customer[c].month);
        printf("\tEnter the date:\t\t");
        scanf("%d", &customer[c].date);
        printf("\tEnter the time:\t\t");
        scanf("%s", &customer[c].time);
        printf("\n\n");

        // ENTER ITEMS
        item_count = 0;
        do
        {
            printf("\n\n\tEnter Item Number: \t");
            scanf("%d", &items[item_count].item_number);
            printf("\tEnter the quantity:\t");
            scanf("%f", &items[item_count].item_quantity);
            printf("\n\tMore Items( Y/N ):\t");
            scanf(" %c", &more_items);
            more_items = toupper(more_items);
            item_count++;
            customer[c].number_of_items = item_count;
        } while (more_items == 'Y');

        printf("\n\n\n\t\t%c   Bill Printing", 177);
        for (i = 0; i < 5; i++)
        {
            printf(" .");
            usleep(350000);
        }
        system("cls");

        bill_print(c);
        printf("\033[1m   Do you have another customer(Y/N):\t");
        scanf(" %c", &more_customers);
        more_customers = toupper(more_customers);
        c++;
    } while (more_customers == 'Y');
    printf("\033[33m");
    printf("\n\n\n\t\t\t----- THANK YOU ----\n\n\n\033[0m");

    main_menu();
    printf("\n\n\n\n\n\n");
}

// PRINT THE BILL
void bill_print(int c)
{
    int i;

    // HEADER
    printf("\n\n\n\n\n\n\t\t\t-  T S T RESTUARANT -\n");
    printf("\t\t     ---------------------------\n");
    printf("\t\t\t   11/2 Sector - 50");
    printf("\n\t\t\t     Fransis Lane");
    printf("\n\t\t\t  525898 - Main Road");
    printf("\n\t\t\t       Kelaniya\n");
    printf("\t\t---------------------------------------\n");
    printf("\t\t  Hotline : 035 5689254 / 076 8956752\n\n\n");
    printf("\t%s", customer[c].name);
    printf("\n\n\t%d/%d", customer[c].date, customer[c].month);
    printf("\t\t\t\t\t\t%s\n", customer[c].time);
    printf("\t");
    for (i = 0; i < 56; i++)
    {
        printf("%c", 205);
    }

    printf("\n\n");

    // MIDDLE PART
    char buffer1[50];
    char buffer2[50];
    int line_number;
    char save;

    for (i = 0; i < customer[c].number_of_items; i++)
    {
        FILE *menu_f = fopen("menu.txt", "r");
        FILE *price_f = fopen("price.txt", "r");

        line_number = 1;
        while (fgets(buffer1, 50, menu_f) != NULL && fgets(buffer2, 50, price_f) != NULL)
        {
            if (items[i].item_number == line_number)
            {
                printf("\n\t%s", buffer1);
                printf("\t\t%s", buffer2);

                strcpy(items[i].item_name, buffer1);

                int j;
                int k = 0;
                char price[10];

                for (j = 4; j < 9; j++)
                {
                    price[k] = buffer2[j];
                    k++;
                }

                items[i].item_price = atof(price);

                items[i].item_total = items[i].item_price * items[i].item_quantity;

                printf("\t\t\tx  %.1f\t\t\t\t  %2.2f", items[i].item_quantity, items[i].item_total);
                printf("\n\t--------------------------------------------------------");
                line_number++;
            }
            else
            {
                line_number++;
            }
        }
        fclose(price_f);
        fclose(menu_f);
    }

    // FOOTER
    printf("\n\t--------------------------------------------------------");
    for (i = 0; i < customer[c].number_of_items; i++)
    {
        customer[c].net_amount = customer[c].net_amount + items[i].item_total;
    }
    printf("\n\n\tTotal Qty:\t\t\t\t\t       %d", customer[c].number_of_items);
    printf("\n\tSub Total:\t\t\t\t\t  %.2f", customer[c].net_amount);
    printf("\n\tCGST@2.5\t\t\t\t\t   %.2f", customer[c].net_amount * (2.5 / 100));
    printf("\n\tSGST@2.5\t\t\t\t\t   %.2f", customer[c].net_amount * (2.5 / 100));
    printf("\n\n\n\tNET TOTAL:\t\t\t\t\t  %.2f\n\n\n", customer[c].net_amount + (customer[c].net_amount * (2.5 / 100)) + (customer[c].net_amount * (2.5 / 100)));

    printf("\t");
    for (i = 0; i < 28; i++)
    {
        printf("%c ", 4);
    }
    printf("\n\t");
    for (i = 0; i < 28; i++)
    {
        printf("%c ", 4);
    }
    printf("\n\n\n");
    printf("\033[36m");
    printf("\n\n\n\n   \033[1mDo you want to save bill(Y/N):\t\033[0m");
    scanf(" %c", &save);
    save = toupper(save);

    // SAVE FILE
    if (save == 'Y')
    {
        FILE *save_bill = fopen("bills.txt", "a+");
        fprintf(save_bill, "Customer Name:\t%s\n", customer[c].name);
        fprintf(save_bill, "Billing Date:\t%d / %d\n", customer[c].date, customer[c].month);
        fprintf(save_bill, "Billing Time:\t%s\n\n", customer[c].time);
        fprintf(save_bill, "Bought Items:-\n");
        for (i = 0; i < customer[c].number_of_items; i++)
        {
            fprintf(save_bill, "Item No. %d:\t%s\t\t\t%.2f\n", i + 1, items[i].item_name, items[i].item_total);
        }
        fprintf(save_bill, "\nTotal:\t%.2f", customer[c].net_amount);
        fprintf(save_bill, "\n-------------------------------------------------------------------\n\n");

        fclose(save_bill);
        printf("\033[92m");
        printf("\n   Successfully Saved....!\n\n\033[0m");
    }
}

//*****************************************************
// USER ENTER NUMBER 3: THIS IS HAPPENING
void check_old_bills()
{
    FILE *old_bill = fopen("bills.txt", "r");
    char buffer[50];

    printf("\033[92m\n\n\t\t ------- OLD BILLS -------\n\n\n\n\n\033[0m");
    while (fgets(buffer, 50, old_bill) != NULL)
    {
        printf("%s", buffer);
    }
    fclose(old_bill);

    printf("\n\n\n\n");
    main_menu();
    printf("\n\n\n\n\n\n");
}

//*****************************************************
// USER ENTER NUMBER 4: THIS IS HAPPENING
void clean_old_bills()
{
    FILE *old_bill = fopen("bills.txt", "w");
    char buffer[50];

    printf("\033[92m\n\n\n\n\n\n\t\t\t-------- ALL DATA CLEARED -------\n\n\n\n\n\033[0m");
    fprintf(old_bill, " \n\n");
    fclose(old_bill);

    main_menu();
    printf("\n\n\n\n\n\n");
}

//*****************************************************
// USER ENTER NUMBER 5: THIS IS HAPPENING
void owner_details()
{
    int i;
    printf("\033[36m\n\n\n\n\n\n\t");
    for (i = 0; i < 30; i++)
    {
        printf("%c ", 220);
    }
    printf("\033[0m");
    printf("\n\n\n\n\n\n");
    printf("\n\t\t\t\tYondec Studios");
    printf("\n\t\t    EC/2020/019 | MADURAPPERUMA M.T.S.K.");
    printf("\n\t\t\t\tYondec Studios");
    printf("\033[36m\n\n\n\n\n\n\t");
    for (i = 0; i < 30; i++)
    {
        printf("%c ", 220);
    }

    printf("\n\n\n\033[0m");
    main_menu();
    printf("\n\n\n\n\n\n");
}

void main_menu()
{
    char menu;
    printf("\033[1m\n\nMAIN MENU(M)....\t\033[0m");
    scanf(" %c", &menu);
    menu = toupper(menu);
    if (menu == 'M')
    {
        main();
    }
    else
    {
        printf("\033[1m");
        printf("\033[31m\nYOU ENTERED WRONG CHARACTOR !!!!!\033[0m\n\n\n\n\n");
        exit(0);
    }
}