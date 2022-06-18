#include<stdlib.h>
#include<windows.h>
#include <string>
#include<iomanip>
#include <cstring>
#include <conio.h>
#include <iostream>

using namespace std;

typedef struct node
{

    float data;
    string foodname;
    int quantity;
    float price;
    struct node* next;

}node;
typedef struct head
{
    node* start;
}head;
void insertend(head* t, float data, string foodname, int quantity, float price)
{

    node* p, * q;
    p = new node();
    p->data = data;
    p->quantity = quantity;
    p->price = price;
    p->foodname=foodname;
    p->next = NULL;
    if (t->start == NULL)
    {
        t->start = p;
    }
    else
    {
        q = t->start;
        while (q->next != NULL)
        {
            q = q->next;
        }
        q->next = p;
    }
}
void ccolor(int clr)
{

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, clr);

}
void foodlist(head* t)
{

    cout<<("\n\t"); ccolor(240);
    cout<<("_______________________________________________________"); ccolor(26);
    cout<<("\n\t"); ccolor(240);
    cout<<("  Food Code          Name                Price         "); ccolor(26);
    cout<<("\n\t"); ccolor(240);
    cout<<("-------------------------------------------------------"); ccolor(26);
    node* p;
    p = t->start;
    while (p != NULL)
    {
        cout<<("\n\t");
int lenOfSpace=29-(p->foodname.length());
//printf("%f            %s            %*d",p->data,p->foodname,lenOfSpace,p->price);
		cout<<p->data<<"            "<<p->foodname<<std::setw(lenOfSpace)<<p->price;
//        cout<<("\t\t",p->data , "|",p->foodname,"|", p->price); //  ", p->data, p->foodname, p->price);
        ccolor(26);
        cout<<("\n\t");
        cout<<("-------------------------------------------------------");
        p = p->next;
    }
}
void foodlist1(head* t)
{
    cout<<("\n\t"); ccolor(240);
    cout<<("___________________________________________________________________");ccolor(26);
    cout<<("\n\t"); ccolor(240);
    cout<<("  Food Code       Name                       Quantity      Price   "); ccolor(26);
    cout<<("\n\t"); ccolor(240);
    cout<<("-------------------------------------------------------------------"); ccolor(26);
int lenOfSpace=0;
    node* p;
    p = t->start;
    while (p != NULL)
    {
lenOfSpace=32-(p->foodname.length());
        cout<<("\n\t");
		cout<<p->data<<"            "<<p->foodname<<std::setw(lenOfSpace)<<p->quantity<<setw(16)<<p->price;

//        cout << (p->data, "|", p->foodname, "|", p->quantity, "|", p->price);// ", p->data, p->foodname, p->quantity, );
        cout<<("\n\t");
        cout<<("------------------------------------------------------------------");
        p = p->next;
    }
}
float getbill(head* t)
{
    node* p;
     float b = 0;
    p = t->start;
    while (p != NULL)
    {
        b = b + p->price;
        p = p->next;
    }
    return b;
}
void order(head* t, head* l, float fc, int qty)
{
    node* p;
    p = t->start;
    while (p->data != fc)
    {
        p = p->next;
    }
    insertend(l, fc, p->foodname, qty, (p->price * qty));
    return;
}
void cls()
{
    system("cls");
}

int main()
{
    head x, s, m, d, o;
    x.start = s.start = m.start = d.start = o.start = NULL;
    float fcode;
    int qty, lo = 0;
    ccolor(26);
    insertend(&s, 1.1, "Samosa", 1, 50);
    insertend(&s, 1.2, "Grilled Cheese Sandwich", 1, 100);
    insertend(&s, 1.3, "Nachos", 1, 150);
    insertend(&s, 1.4, "Chicken Burger", 1, 150);
    insertend(&s, 1.5, "BBQ Chicken Roll", 1, 250);
    insertend(&m, 2.1, "Pav Bhaji", 1, 200);
    insertend(&m, 2.2, "Punjabi Thali", 1, 350);
    insertend(&m, 2.3, "Mexican Sizzler", 1, 250);
    insertend(&m, 2.4, "Peri Peri Chicken Pizza", 1, 250);
    insertend(&m, 2.5, "Margherita Pizza", 1, 200);
    insertend(&m, 2.6, "Veg Pulao", 1, 250);
    insertend(&m, 2.7, "Chicken Handi Biryani", 1, 350);
    insertend(&d, 3.1, "Chocolate Overload Waffle", 1, 150);
    insertend(&d, 3.2, "Cinnamon Waffle", 1, 150);
    insertend(&d, 3.3, "Chocolate Cake", 1, 250);
    insertend(&d, 3.4, "Red Velevet Cake", 1, 350);
    insertend(&d, 3.5, "Strawberry Mouse", 1, 100);
    insertend(&d, 3.6, "Orea Freakshake", 1, 150);
    insertend(&d, 3.7, "Fruit Milkshake", 1, 80);
    //login
    char uid[20], pwd[20], uid1[20], pwd1[20], c = ' ', k = ' ';
    int i = 0, ch;
    while (1)
    {
        cls();
    mainscr: cout<<("\n\nEnter Choice: 1. Login 2.New User 3.Exit\n");
        cin>> ch;
        if (ch == 3)
            break;
        //register new user
        if (ch == 2)
        {
            
            cout<<(" \n\n                  ENTER USERNAME: ");
            cin>>uid1;
            cout<<(" \n\n                  ENTER PASSWORD: ");
            while (i < 20)
            {
                pwd1[i] = _getch();
                c = pwd1[i];
                if (c == '\r') break;
                else cout<<("*");
                i++;
            }
            pwd1[i] = '\0';


            cout<<("\n\n            Registered Successfully!\n");
            Sleep(2000);
        }
        else
        {
            cout<<("\n  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  ");
            cout<<(" \n\n                  ENTER USERNAME: ");
            cin>>(uid);
            cout<<(" \n\n                  ENTER PASSWORD: ");
            c = ' '; 
		i = 0;
            while (i < 20)
            {
                pwd[i] = _getch();
                c = pwd[i];
                if (c == '\r') break;
                else cout<<("*");
                i++;
            }
            pwd[i] = '\0';


            //USERMENU
            if (strcmp(uid, uid1) == 0 && strcmp(pwd, pwd1) == 0)
            {
                cout<<("\n\n            LOGIN SUCCESFULL!");
                Sleep(2000);
                cls();
                int i = 0, ch;
            mainmenu: cout<<("Enter choice: 1.View Menu 2.View Previous Order 3.Log Out\n");
                cin>>(ch);
                if (ch == 2)
                {
                    if (o.start == NULL)
                    {
                        cout<<("Previous Order does not exist!\n");
                        Sleep(2000);
                        cls();
                        goto mainmenu;
                    }
                    else
                    {
                        cls();
                        foodlist1(&o);
                        cout<<("\nPress 0 to continue.\n");
                        cin>>(ch);
                        if (ch == 0)
                        {
                            goto mainmenu;
                        }
                    }

                }
                else if (ch == 1)
                {
                order: cout<<("Enter Choice:\n");
                    cout<<("1.Snacks\n2.Main Course\n3.Dessert\n");
                    cin>>(ch);
                    while (1) {
                        switch (ch)
                        {
                        case 1: foodlist(&s);
                            cout<<("\n");
                            cout<<("Enter Food Code:\n");
                            cin>>(fcode);
                            cout<<("Enter Quantity of Food:\n");
                            cin>>(qty);
                            order(&s, &o, fcode, qty);
                            foodlist1(&o);
                            break;
                        case 2: foodlist(&m);
                            cout<<("\n");
                            cout<<("Enter Food Code:\n");
                            cin>>(fcode);
                            cout<<("Enter Quantity of Food:\n");
                            cin>>(qty);
                            order(&m, &o, fcode, qty);
                            foodlist1(&o);
                            break;
                        case 3: foodlist(&d);
                            cout<<("\n");
                            cout<<("Enter Food Code:\n");
                            cin>>(fcode);
                            cout<<("Enter Quantity of Food:\n");
                            cin>>(qty);
                            order(&d, &o, fcode, qty);
                            foodlist1(&o);
                            break;
                        default: cout<<("Invalid Choice.\n");
                        }
                    afterorder: cout<<("\n\n");
                        cout<<("\n\t\tEnter Choice: \n\t\t1.Hungry For More? \n\t\t2.View Order \n\t\t3.Confirm Order?\n");
                        cin>>(ch);
                        if (ch == 1)
                        {
                            cls();
                            goto order;
                        }
                        else if (ch == 2)
                        {
                            cls();
                            cout<<("Current Order:\n");
                            foodlist1(&o);
                            goto afterorder;
                        }
                        //billing
                        else if (ch == 3)
                        {
                            cls();
                            foodlist1(&o);
                            cout<<("\nTotal amount to pay: %0.2f\n", getbill(&o));
                            cout<<("\nEnjoy Your Meal!\n");
                            cout<<("\nPress 0 to continue.\n");
                            cin>>(ch);
                            if (ch == 0)
                            {
                                cls();
                                goto mainmenu;
                            }
                        }
                    }
                }
                else if (ch == 3)
                {
                    cls();
                    goto mainscr;
                }
                else
                    cout<<("\nInvalid Choice.\n");
            }
            //admin
            else if (strcmp(uid, "admin") == 0 && strcmp(pwd, "admin123") == 0)
            {
                cout<<("\n\n            WELCOME ADMIN");
                Sleep(3000);
                cls();
                int adch;
            admin:  cout<<("\n\n            Enter Choice:\n");
                cout<<("            1. View Menu\n");
                cout<<("            2. Update Menu\n");
                cout<<("            3. View Recent Order\n");
                cout<<("            4. Log Out\n");
                cin>>(adch);
                cls();
                if (adch == 4)
                    goto mainscr;
                switch (adch)
                {
                case 1:cls();
                    cout<<("\nSNACKS:\n");
                    foodlist(&s);
                    Sleep(3000);
                    cout<<("\nMAIN COURSE:\n");
                    foodlist(&m);
                    Sleep(3000);
                    cout<<("\nDESSERT:\n");
                    foodlist(&d);
                    cout<<("\nPress 0 to continue.\n");
                    cin>>(ch);
                    if (ch == 0)
                    {
                    }
                    break;
                case 3: //Sleep(3000);
                    cls();
                    cout<<("Recent Order:\n");
                    foodlist1(&o);
                    cout<<("\nPress 0 to continue.\n");
                    cin>>(ch);
                    if (ch == 0)
                    {
                        goto admin;
                    }

                    break;
                case 2:
                    cls();
                    float fcu, pu;
                    char fnameu[50];
                    cout<<("UPDATE MENU\n");
                    cout<<("What do you want to update?\n");
                    cout<<("Enter Choice:\n");
                    cout<<("1.Snacks\n2.Main Course\n3.Dessert\n");
                    cin>>(ch);
                    switch (ch)
                    {
                    case 1: cout<<("\nEnter Food Code:\n");
                        cin>>(fcu);
                        cout<<("\nEnter Food name:\n");
                        cin>>(fnameu);
                        cout<<("\nEnter price:\n");
                        cin>>(pu);
                        insertend(&s, fcu, fnameu, 1, pu);
                        cout<<("\nMENU UPDATED\n");
                        foodlist(&s);
                        break;
                    case 2: cout<<("\nEnter Food Code:\n");
                        cin>>(fcu);
                        cout<<("\nEnter Food name:\n");
                        cin>>(fnameu);
                        cout<<("\nEnter price:\n");
                        cin>>(pu);
                        insertend(&m, fcu, fnameu, 1, pu);
                        cout<<("\nMENU UPDATED\n");
                        foodlist(&m);
                        break;
                    case 3: cout<<("\nEnter Food Code:\n");
                        cin>>(fcu);
                        cout<<("\nEnter Food name:\n");
                        cin>>(fnameu);
                        cout<<("\nEnter price:\n");
                        cin>>(pu);
                        insertend(&d, fcu, fnameu, 1, pu);
                        cout<<("\nMENU UPDATED\n");
                        foodlist(&d);
                        break;

                    }
                    goto admin;
                    break;

                default:cout<<("\nInvalid Choice\n");
                }
            }
            else
            {
                cout<<("\n\n        INCORRECT USERNAME OR PASSWORD");
                Sleep(2000);
            }
        }
    }

    return 0;
}
