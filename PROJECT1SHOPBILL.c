#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <wctype.h>
#define pass 1702

struct details
{
    char name[100];
    int phonenumber;
} pname, phone;
char burger[100];
int bill[3];
void exitfunction()
{
    printf("Want to try again then run the program again.\n");
    printf("Till then Thank you\n");
    getch();
    system("cls");

    int wholeprice = 0;
    wholeprice = bill[0] + bill[1] + bill[2];
    printf("%d\n", wholeprice);
    system("cls");
    finalbill(wholeprice);
}
int finalbill(int wholeprice)
{
    printf("---------------------------------------\n");
    printf("PURCHASER NAME -> %s\n", pname.name);
    printf("---------------------------------------\n");
    printf("PHONE NUMBER -> %d\n", phone.phonenumber);
    printf("---------------------------------------\n");
    printf("YOUR BILL(WITHOUT GST) IS =        %d\n", wholeprice);
    float gstprice;
    gstprice = ((wholeprice) / 100) * 18;
    float totalprice = gstprice + wholeprice;
    printf("---------------------------------------\n");
    printf("AMOUNT TO BE PAID IS ->            %f\n", totalprice);
    printf("---------------------------------------\n");
    time_t t;
    time(&t);
    printf("THE BILL WAS GENERATED AT - %s", ctime(&t));
    printf("---------------------------------------\n");
}

int employeelogin()
{
    char empname[100];
    char c;
    scanf("%s", empname);
    int password;
    scanf("%d", &password);
    if (password == pass)
    {
        printf("\t\t\tlogin successful\n");
        printf("\t\t\tthe %s logged in for billing process", empname);
        return 1;
    }
    else
    {
        printf("\t\t\tTry again later\n");
        return 0;
    }
}
int checkburger(int burgord, int quantity)
{
    int pburgersum = 0;
    if (burgord == 1)
    {
        pburgersum = pburgersum + 50 * quantity;
    }
    else if (burgord == 2)
    {
        pburgersum = pburgersum + 75 * quantity;
    }
    else if (burgord == 3)
    {
        pburgersum = pburgersum + 100 * quantity;
    }
    else if (burgord == 4)
    {
        pburgersum = pburgersum + 125 * quantity;
    }
    else if (burgord == 5)
    {
        pburgersum = pburgersum + 150 * quantity;
    }
    return pburgersum;
}
int burgersum(int n)
{
    printf("\t\t\t~~~~~~~~~PLEASE PLACE YOUR ORDER OF BURGERS AND QUANTITY OF A BURGER~~~~~~~~~~~\n");
    int totalsum = 0;
    for (int i = 0; i < n; i++)
    {
        int burgord, quantity;
        scanf("%d%d", &burgord, &quantity);
        totalsum = totalsum + checkburger(burgord, quantity);
    }
    return totalsum;
}
int burgers()
{
    printf("\t\t\t->NAME                          PRICE\n");
    printf("\t\t\t------------------------------------\n");
    printf("\t\t\t1.BURGER 1                      50Rs\n");
    printf("\t\t\t2.BURGER 2                      75Rs\n");
    printf("\t\t\t3.BURGER 3                     100Rs\n");
    printf("\t\t\t4.BURGER 4                     125Rs\n");
    printf("\t\t\t5.BURGER 5                     150Rs\n");
    printf("\t\t\t------------------------------------\n");
    printf("\n\t\t\tEnter the total number of types burger required\n");
    int n;
    scanf("%d", &n);
    int burger_sum = burgersum(n);
    printf("%d\n", burger_sum);
    printf("\t\t\t---YOUR ORDER OF THE BURGERS IS %d :\n", burger_sum);
    bill[0] = bill[0] + burger_sum;
    printf("\t\t\t---FEEL FREE TO ORDER MORE---\n");
    printf("\t\t\tPress 1 for main menu and to exit 9 to exit \n");
    int t;
    scanf("%d", &t);
    if (t == 1)
    {
        itemnames();
    }
    else if (t == 9)
    {
        exitfunction();
    }

    return burger_sum;
}

int pizza()
{
    printf("->NAME                          PRICE\n");
    printf("\t\t\t------------------------------------\n");
    printf("\t\t\t1.PIZZA 1                      50Rs\n");
    printf("\t\t\t2.PIZZA 2                      75Rs\n");
    printf("\t\t\t3.PIZZA 3                     100Rs\n");
    printf("\t\t\t4.PIZZA 4                     125Rs\n");
    printf("\t\t\t5.PIZZA 5                     150Rs\n");
    printf("\t\t\t------------------------------------\n");
    printf("\n\t\t\tEnter the total number of types PIZZA required\n");
    int pizzchoice;
    scanf("%d", &pizzchoice);
    int pizzasum = pizzaorder(pizzchoice);
    printf("%d\n", pizzasum);
    printf("\t\t\t---YOUR ORDER OF THE PIZZA IS %d :", pizzasum);
    bill[1] = bill[1] + pizzasum;
    printf("\t\t\t---FEEL FREE TO ORDER MORE---\n");
    printf("\t\t\tPress 1 for main menu and to exit 9 to exit \n");
    int t;
    scanf("%d", &t);
    if (t == 1)
    {
        itemnames();
    }
    else if (t == 9)
    {
        exitfunction();
    }
    return pizzasum;
}
int pizzaorder(int pizzchoice)
{
    printf("\t\t\t~~~~~~~~~PLEASE PLACE YOUR ORDER OF BURGERS AND QUANTITY OF A BURGER~~~~~~~~~~~\n");
    int totalpizzasum = 0;
    for (int i = 0; i < pizzchoice; i++)
    {
        int pizord, pquantity;
        scanf("%d%d", &pizord, &pquantity);
        totalpizzasum = totalpizzasum + checkpizza(pizord, pquantity);
    }
    return totalpizzasum;
}
int checkpizza(int pizord, int pquantity)
{
    int pizzasum = 0;
    if (pizord == 1)
    {
        pizzasum = pizzasum + 50 * pquantity;
    }
    else if (pizord == 2)
    {
        pizzasum = pizzasum + 75 * pquantity;
    }
    else if (pizord == 3)
    {
        pizzasum = pizzasum + 100 * pquantity;
    }
    else if (pizord == 4)
    {
        pizzasum = pizzasum + 125 * pquantity;
    }
    else if (pizord == 5)
    {
        pizzasum = pizzasum + 150 * pquantity;
    }
    return pizzasum;
}
int drinks()
{
    printf("\t\t\t->NAME                          PRICE\n");
    printf("\t\t\t------------------------------------\n");
    printf("\t\t\t1.DRINK 1                      50Rs\n");
    printf("\t\t\t2.DRINK 2                      75Rs\n");
    printf("\t\t\t3.DRINK 3                     100Rs\n");
    printf("\t\t\t4.DRINK 4                     125Rs\n");
    printf("\t\t\t5.DRINK 5                     150Rs\n");
    printf("\t\t\t------------------------------------\n");
    printf("\n\t\t\tEnter the total number of types DRINKS required\n");
    int drinkchoice;
    scanf("%d", &drinkchoice);
    int drinksum = drinkorder(drinkchoice);
    printf("%d\n", drinksum);
    printf("\t\t\t---YOUR ORDER OF THE DRINKS %d :\n", drinksum);
    bill[2] = bill[2] + drinksum;
    printf("\t\t\t---FEEL FREE TO ORDER MORE---\n");
    printf("\t\t\tPress 1 for main menu and to exit 9 to exit \n");
    int t;
    scanf("%d", &t);
    if (t == 1)
    {
        itemnames();
    }
    else if (t == 9)
    {
        exitfunction();
    }

    return drinksum;
}

int drinkorder(int drinkchoice)
{
    printf("\t\t\t~~~~~~~~~PLEASE PLACE YOUR ORDER OF BURGERS AND QUANTITY OF A BURGER~~~~~~~~~~~\n");
    int totaldrinksum = 0;
    for (int i = 0; i < drinkchoice; i++)
    {
        int drord, dquantity;
        scanf("%d%d", &drord, &dquantity);
        totaldrinksum = totaldrinksum + checkdrink(drord, dquantity);
    }
    return totaldrinksum;
}
int checkdrink(int drod, int dquantity)
{
    int drinksum = 0;
    if (drod == 1)
    {
        drinksum = drinksum + 50 * dquantity;
    }
    else if (drod == 2)
    {
        drinksum = drinksum + 75 * dquantity;
    }
    else if (drod == 3)
    {
        drinksum = drinksum + 100 * dquantity;
    }
    else if (drod == 4)
    {
        drinksum = drinksum + 125 * dquantity;
    }
    else if (drod == 5)
    {
        drinksum = drinksum + 150 * dquantity;
    }
    return drinksum;
}

void itemnames()
{
    printf("\t\t\t<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>\n");
    printf("\t\t\t------1.BURGERS----------\n");
    printf("\t\t\t------2.PAN PIZZA--------\n");
    printf("\t\t\t------3.SOFT DRINKS------\n");
    printf("\t\t\t<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>\n");
    printf("\n");
    printf("\t\t\t------Enter your choice-----\n");
    int choice;
    scanf("%d", &choice);
    getch();
    system("cls");
    if (choice == 1)
    {
        burgers();
    }
    else if (choice == 2)
    {
        pizza();
    }
    else if (choice == 3)
    {
        drinks();
    }
    else
    {
        printf("\t\t\tPlease provide the choice from given items only\n");
        itemnames();
    }
}

int main()
{
    printf("\t\t\t########////THE FOOD SHOP////########\n");
    printf("\t\t\t-------------ESTD-2021--------------\n");
    getch();
    system("cls");
    printf("\t\t\t******EMPLOYEE LOG-IN******\n");
    printf("\t\t\tName and Password of the employee-");
    int z;
    z = employeelogin();
    if (z == 1)
    {
        goto cont;
    }
    else if (z == 0)
    {
        goto end;
    }
cont:
    getch();
    system("cls");
    printf("\t\t\tPurchaser Name- ");
    scanf("%s", pname.name);
    printf("\n");
phoneagain:
    printf("\t\t\tenter the phone number ");
    scanf("%d", &phone.phonenumber);
    int count = 0;
    while (phone.phonenumber != 0)
    {
        phone.phonenumber = phone.phonenumber / 10;
        count++;
    }
    if (count == 10)
    {
    }
    else
    {
        printf("\t\t\tEnter the valid phone number \n");
        goto phoneagain;
    }

    printf("\n");
    getch();
    system("cls");
    printf("\t\t\t%s PLEASE PLACE YOUR ORDER\n", pname.name);
    printf("\t\t\tpress enter for the available items\n");
    getch();
    system("cls");
    printf("\t\t\tLOADING AVAILABLE ITEMS..\n");
    system("cls");
    printf("\t\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
    itemnames();
    // int sumtotal=0;
    // sumtotal+=burgers() + pizza() +drinks();
    // printf("%d\n",sumtotal);

    printf("\t\t\tXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");

end:
    return 0;
}