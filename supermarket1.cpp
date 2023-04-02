#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>

using namespace std;
string discday = "sunday";
int discrate = 10;

void mainmenu();
void adminmenu();
void adminlogo();
void adminfunction();
void changeloginsetting();
void newitems();
void viewstock();
void viewemployee();
void addemployee();
void viewpassword();
void assignrack();
void changeprice();
void updateprice(string itemname, string presentrack, int presentitemprice);
void changeemployee();
void updateemployee(string presentname, int presentsalary, string presentshift, int presentphone);
void employeemenu();
void printemployeelogo();
void adddiscount();
void viewemplPL();
void mainlogo();
void mainpic();
void newemployeePL();

void employeefunctions();
void viewstockasemployee();
void changeemployeePU();
void updateemployeePU(string fileusername, string filepassword);
void latestbuyer();

void buyermenu();
void buyerlogo();
void buyeritem();
void shoppingmenu(string buyername, string shopingday);

main()
{
    
    mainlogo();
    Sleep(1000);
    mainpic();
    Sleep(3000);

    mainmenu();
}
void mainmenu()
{
    system("cls");
    string choice;

    cout << "**********************************************************************************" << endl;
    cout << "*                           SUPER MARKET SYSTEM                                  *" << endl;
    cout << "**********************************************************************************" << endl;
    cout << endl;
    cout << endl;
    cout << " (a) -----------------ADMINISTRATOR---------------------" << endl;
    cout << endl;
    cout << " (b) -----------------BUYER---------------------" << endl;
    cout << endl;
    cout << " (c) -----------------EMPLOYEE---------------------" << endl;
    cout << endl;
    cout << "ENTER YOUR LOGIN STTATUS" << endl;
    cout << "Press 'a' , 'b' & 'c'" << endl;
a:
    cout << "YOUR CHOICE : ";
    cin >> choice;
    if (choice == "a")
    {

        adminmenu();
    }
    if (choice == "b")
    {
        buyermenu();
    }
    if (choice == "c")
    {
        employeemenu();
    }
    if (choice != "a" && choice != "b" && choice != "c")
    {
        cout << "__________________________________YOUR CHOICE IS NOT CORRECT______________________________ " << endl;
        goto a;
    }
}
void adminmenu()
{
    bool result = false;
    string username;
    string password;
    string filepass;
    string filename;
    fstream file;
    adminlogo();
    cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Login menue" << endl
         << endl;
    cout << "HINT: USERNAME IS IN ALPHABAT & PASSWAORD IS NUMBERS" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "---------------USERNAME:    ";
    cin >> username;
    cout << endl;
    cout << "---------------PASSWORD:    ";
    cin >> password;
    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    file.open("adminpassword.txt", ios::in);
    while (!file.eof())
    {
        file >> filename;
        file >> filepass;
        if (username == filename && password == filepass)
            result = true;
    }
    file.close();
    if (result == true)
    {
        adminfunction();
    }
    else
        cout << "YOUR PASSWORD & USERNAME IS INCORRECT" << endl;
    Sleep(1000);
    mainmenu();
}

void adminlogo()
{
    system("cls");
    cout << "**********************************************************************************" << endl;
    cout << "*                          ADMINISTRATOR MENUE                                   *" << endl;
    cout << "**********************************************************************************" << endl;
    cout << endl;
    cout << endl;
}
void adminfunction()
{
    system("cls");
    adminlogo();
    string choice;
    char choice1;
    cout << "1--------------change login setting (change password & name)" << endl;
    cout << "2--------------Add new items" << endl;
    cout << "3--------------see total employee" << endl;
    cout << "4--------------change product price" << endl;
    cout << "5--------------Add discount" << endl;
    cout << "6--------------Assign a racks (Position) of differnt items" << endl;
    cout << "7--------------Add Employee" << endl;
    cout << "8--------------Change employee details" << endl;
    cout << "9--------------View total products (stocks)" << endl;
    cout << "10-------------View their login password and username" << endl;
    cout << "11-------------See employee login password and username" << endl;
    cout << "12-------------Add employee login password and username" << endl;
    cout << "13-------------Exit" << endl;
    cout << "___________________________ACCORDING TO YOUR WORKS PLEASE SELECT_______________________________" << endl
         << endl;
    cout << "ENTER YOUR CHOICE: ";
    cin >> choice;
    if (choice == "1")
    {
        changeloginsetting();
    }
    else if (choice == "2")
    {
        newitems();
    }
    else if (choice == "4")
    {
        changeprice();
    }
    else if (choice == "6")
    {
        assignrack();
    }
    else if (choice == "7")
    {
        addemployee();
    }
    else if (choice == "8")
    {
        changeemployee();
    }
    else if (choice == "5")
    {
        adddiscount();
    }
    else if (choice == "9")
    {
        viewstock();
    }
    else if (choice == "3")
    {
        viewemployee();
    }
    else if (choice == "10")
    {
        viewpassword();
    }
    else if (choice == "11")
    {
        viewemplPL();
    }
    else if (choice == "12")
    {
        newemployeePL();
    }
    else if (choice == "13")
    {
        mainmenu();
    }

    else
    {
        cout << "your choice is incorrect " << endl
             << endl;
        cout << "-------------Press any key  to go to main menu: " << endl
             << endl;
        cin >> choice1;
        mainmenu();
    }
}
void adddiscount()
{
    system("cls");
    adminlogo();
    char key;
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<ADD DISCOUNT" << endl
         << endl;
    cout << "Enter day of discount: ";
    cin >> discday;
    cout << "Enter discount in percentage (%):  ";
    cin >> discrate;
    cout << "************************************************************************************************" << endl;
    cout << endl
         << "______________________________SUCCESSFULLY DISCOUNT ADDED" << endl;
    cout << "you offered " << discrate << "% discount on " << discday << endl;
    cout << "-------------Press any key  to go to main menu: " << endl
         << endl;
    key = getch();
    adminfunction();
}
void changeloginsetting()
{
    bool result = false;
    fstream file;
    string username;
    string password;
    string newusername;

    string line1;
    string line2;
    system("cls");
    adminlogo();
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<LOGIN SETTING" << endl
         << endl;
    cout << "Enter your previous username: ";
    cin >> username;
    cout << "Enter your previous password: ";
    cin >> password;
    file.open("adminpassword.txt", ios::in);
    while (!file.eof())
    {
        file >> line1;
        file >> line2;
        if (username == line1 && password == line2)
            result = true;
    }
    file.close();
    if (result == true)
    {
        cout << "Enter your new username: ";
        cin >> username;
        cout << "Enter your new  password: ";
        cin >> password;

        file.open("adminpassword.txt", ios::out);
        file << endl
             << username << endl;
        file << password;
        file.close();
        Sleep(1000);
        cout << "Password and username is successfully changed " << endl
             << endl;
        Sleep(500);
        adminfunction();
    }
    else
    {
        cout << "--------------ERROR---------------" << endl;
        cout << "you previous username and password is incorrect so you are unable to change their password and username" << endl
             << endl;
        Sleep(500);
        adminfunction();
    }
}
void newitems()
{
    fstream file;
    string itemname;
    int itemprice;
    string itemrack;
    char key;
    system("cls");
    adminlogo();
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<ADD ITEMS " << endl
         << endl;
f:
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Enter the name of item: ";
    cin >> itemname;
    cout << endl;
    cout << "Enter the price of item: ";
    cin >> itemprice;
    cout << "Enter the rack of product(position): ";
    cin >> itemrack;
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;

    file.open("stock.txt", ios::app);
    file << endl
         << itemname << endl;
    file << itemprice << endl;
    file << itemrack;
    file.close();
    cout << "_____________ITEMS SUCCESSFULLY ADDED" << endl;
    cout << "Enter 'n' to add more items  and press any other key to go to main menu: ";
    cin >> key;
    if (key == 'n')
        goto f;
    else
        adminfunction();
}
void viewstock()
{
    char key;
    fstream file;
    string itemname;
    int itemprice;
    string itemrack;
    system("cls");
    adminlogo();
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<TOTAL STOCK IN SUPERMARKET" << endl
         << endl;
    file.open("stock.txt", ios::in);
    while (!file.eof())
    {
        file >> itemname;
        file >> itemprice;
        file >> itemrack;
        cout << itemname << "\t\t\t\t\t\t\t\t" << itemprice << "\t\t\t\t\t\t\t\t" << itemrack;
        cout << endl
             << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    file.close();

    cout << "Press any key to go to main menu: ";
    cin >> key;
    adminfunction();
}
void viewemployee()
{
    fstream file;
    string employeename;
    string employeeshift;
    int employeesalary;
    int employeephone;
    char key;
    system("cls");
    adminlogo();

    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<TOTAL EMPLOYEE WORKING IN SUPERMARKET" << endl
         << endl;
    file.open("employee.txt", ios::in);
    while (!file.eof())
    {
        file >> employeename;
        file >> employeesalary;
        file >> employeeshift;
        file >> employeephone;

        cout << employeename << "\t\t\t\t" << employeesalary << "\t\t\t\t" << employeeshift << "\t\t\t\t" << employeephone;
        cout << endl
             << "------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    file.close();
    cout << "Press any key to go to main menu: ";
    cin >> key;
    adminfunction();
}
void addemployee()
{
    fstream file;
    string employeename;
    string employeeshift;
    int employeesalary;
    int employeephone;
    char key;
    system("cls");
    adminlogo();
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<ADD EMPLOYEE " << endl
         << endl;
f:
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Enter the name of new Employee: ";
    cin >> employeename;
    cout << endl;
    cout << "Enter the Salary of new Employee: ";
    cin >> employeesalary;
    cout << "Enter the Shift of new Employee: ";
    cin >> employeeshift;
    cout << "Enter the Phone number of new Employee: ";
    cin >> employeephone;

    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;

    file.open("employee.txt", ios::app);
    file << endl
         << employeename << endl;
    file << employeesalary << endl;
    file << employeeshift << endl;
    file << employeephone;
    file.close();
    cout << "_______________________NEW EMPLOYEE SUCCESSFULLY ADDED" << endl;
    cout << "Enter 'n' to add more employee  and press any other key to go to main menu: ";
    cin >> key;
    if (key == 'n')
        goto f;
    else
        adminfunction();
}
void viewpassword()
{
    string username;
    string password;
    char key;
    system("cls");
    adminlogo();

    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<PERSONAL & SECRET DETAILS" << endl
         << endl;
    fstream file;
    file.open("adminpassword.txt", ios::in);
    while (!file.eof())
    {
        file >> username;
        file >> password;
    }
    file.close();

    cout << "****************USERNAME****************" << endl;
    cout << "*" << username << "*" << endl;
    cout << "****************************************" << endl;
    cout << "****************PASSWORD****************" << endl;
    cout << "*" << password << "*" << endl;
    cout << "****************************************" << endl
         << endl;
    cout << "___________________________________DONOT SHARE WITH OTHERS" << endl;
    cout
        << "Press any key to go to main menu: ";
    cin >> key;
    adminfunction();
}
void assignrack()
{
    fstream file;
    string presentitem;
    int presentitemprice;
    string presentrack;
    char key;
    int flag = 0;
    string itemname;
    string newrack;
    system("cls");
    adminlogo();
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<ASSIGN NEW RACK " << endl
         << endl;
    cout << "Enter the product name whose rack you want to change:  ";
    cin >> itemname;
    file.open("stock.txt", ios::in);
    while (!file.eof())
    {
        file >> presentitem;
        if (presentitem == itemname)
        {
            file >> presentitemprice;
            file >> presentrack;
            cout << "ITEM PRICE: " << presentitemprice << endl;
            cout << "ITEM RACK : " << presentrack;
            cout << endl
                 << endl;
            cout << "----------------------------------------------------------------------------------" << endl;
            cout << "Enter the  new rack : ";
            cin >> newrack;
            presentrack = newrack;

            flag = 1;
        }
    }
    file.close();
    if (flag == 1)
    {
        cout << "________________RACK CHANGED SUCCESSFULLY " << endl;
        cout << "Press any key to go to main menu: ";
        cin >> key;
        adminfunction();
    }
    if (flag == 0)
    {
        cout << "________________PRODUCT NOT FOUND IN STOCK " << endl;
        cout << "Press any key to go to main menu: ";
        cin >> key;
        adminfunction();
    }
}
void changeprice()
{
    fstream file;
    string presentitem;
    int presentitemprice;
    string presentrack;
    int flag = 0;
    string itemname;
    char key;
    int newprice;
    system("cls");
    adminlogo();
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<CHANGE PRICE " << endl
         << endl;
    cout << "Enter the product name whose price you want to change:  ";
    cin >> itemname;
    file.open("stock.txt", ios::in);
    while (!file.eof())
    {
        file >> presentitem;
        if (presentitem == itemname)
        {

            file >> presentitemprice;
            file >> presentrack;
            cout << "ITEM NAME: " << itemname << endl;
            cout << "------------------------------PREVIOU ITEM PRICE: " << presentitemprice << endl;
            cout << "ITEM RACK : " << presentrack;
            cout << endl
                 << endl;
            cout << "----------------------------------------------------------------------------------" << endl;

            flag = 1;
        }
    }
    file.close();
    if (flag == 1)
    {
        updateprice(itemname, presentrack, presentitemprice);
    }
    if (flag == 0)
    {
        cout << "________________PRODUCT NOT FOUND IN STOCK " << endl;
        cout << "Press any key to go to main menu: ";
        cin >> key;
        adminfunction();
    }
}
void changeemployee()
{
    fstream file;
    string presentname;
    int presentsalary;
    string presentshift;
    int presentphone;
    char key;
    int flag = 0;
    string employeename;
    string newname;
    string newshift;
    int newphone;
    int newsalary;
    system("cls");
    adminlogo();
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<CHANGE EMPLOYEE DETAIL " << endl
         << endl;
    cout << "Enter the name of employee whose detail you want to change:  ";
    cin >> employeename;
    file.open("employee.txt", ios::in);
    while (!file.eof())
    {
        file >> presentname;
        if (presentname == employeename)
        {
            file >> presentsalary;
            file >> presentshift;
            file >> presentphone;
            updateemployee(presentname, presentsalary, presentshift, presentphone);

            flag = 1;
        }
    }
    file.close();
    if (flag == 0)
    {
        cout << "________________EMPLOYEE NOT FOUND " << endl;
        cout << "Press any key to go to main menu: ";
        cin >> key;
        adminfunction();
    }
}
void employeemenu()
{
    fstream file;
    string employeename;
    string employeepassword;
    string fileemployee;
    string filepassword;
    int flag = 0;
    system("cls");
    printemployeelogo();
    char choice;
    cout << "HINT: USERNAME IS IN ALPHABAT & PASSWAORD IS NUMBERS" << endl
         << endl;
    cout << "EACH EMPLOYEE HAS THEIR OWN PASSWORD " << endl
         << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "---------------YOUR NAME:    ";
    cin >> employeename;
    cout << "---------------PASSWORD :    ";
    cin >> employeepassword;
    cout << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    file.open("employeelogin.txt", ios::in);
    while (!file.eof())
    {
        file >> fileemployee;
        file >> filepassword;
        if (employeename == fileemployee && filepassword == employeepassword)
        {
            flag = 1;
        }
    }
    file.close();
    if (flag == 1)
    {
        employeefunctions();
    }
    if (flag == 0)
    {
        cout << "____________________PASSWORD & USERNAME IS INCORRECT";
        cout << "Press any key to go to main menu: ";
        cin >> choice;
        mainmenu();
    }
}
void printemployeelogo()
{
    system("cls");
    cout << "**********************************************************************************" << endl;
    cout << "*                          Employee MENUE                                        *" << endl;
    cout << "**********************************************************************************" << endl;
    cout << endl;
    cout << endl;
}
void employeefunctions()
{
    system("cls");
    printemployeelogo();
    int choice;
    char choice1;
    cout << "1--------------change login setting (change password & name)" << endl;
    cout << "2---------------see total products(stock)" << endl;
    cout << "3---------------see latest buyer record" << endl;
    cout << "4---------------Exit" << endl;

    cout << "___________________________ACCORDING TO YOUR WORKS PLEASE SELECT_______________________________" << endl
         << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    if (choice == 1)
    {
        changeemployeePU();
    }
    if (choice == 2)
    {
        viewstockasemployee();
    }
    if (choice == 3)
    {
        latestbuyer();
    }
    if (choice == 4)
    {
        mainmenu();
    }
    if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
    {

        cout << "your choice is incorrect " << endl
             << endl;
        cout << "-------------Press any key  to go to main menu: " << endl
             << endl;
        choice1 = getch();
        mainmenu();
    }
}
void viewstockasemployee()
{
    char key;
    fstream file;
    string itemname;
    int itemprice;
    string itemrack;
    system("cls");
    printemployeelogo();
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<TOTAL STOCK IN SUPERMARKET" << endl
         << endl;
    file.open("stock.txt", ios::in);
    while (!file.eof())
    {
        file >> itemname;
        file >> itemprice;
        file >> itemrack;
        cout << itemname << "\t\t\t\t\t\t\t\t" << itemprice << "\t\t\t\t\t\t\t\t" << itemrack << endl;
        cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }

    file.close();

    cout << "Press any key to go to main menu: ";
    cin >> key;
    employeefunctions();
}
void buyerlogo()
{
    system("cls");
    cout << "**********************************************************************************" << endl;
    cout << "*                          BUYER MENUE                                           *" << endl;
    cout << "**********************************************************************************" << endl;
    cout << endl;
    cout << endl;
}

void buyermenu()
{
    string buyername;
    string shopingday;
    char startchoice;

    buyerlogo();

    cout << "ENTER YOUR NAME PLEASE: ";
    cin >> buyername;
    cout << "ENTER THE DAY OF SHOPING: ";
    cin >> shopingday;
    cout << endl;
    cout << endl;

    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "Press 'S' for start calculate your bill" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
l:
    cout << "YOUR CHOICE: ";
    cin >> startchoice;
    if (startchoice == 's' || startchoice == 'S')
    {
        shoppingmenu(buyername, shopingday);
    }
    else
    {
        cout << "_____________________________OOPS! PLEASE PRESS 'S' ________________________________ " << endl;
        goto l;
    }
}
void shoppingmenu(string buyername, string shopingday)
{
    fstream file;
    int flag = 0;
    int total = 0;
    int sum;
    int initialtotal;
    int itemcount = 1;
    int quantity;
    string checkitem;
    int presentprice;
    string itemname;
    string rack;
    float discamount;
    float disc;
    char key;

    int index = 0;
    char receiptchoice = 'n';
    buyerlogo();
    cout << "--------------------------BUYER NAME  : " << buyername << endl;
    cout << "--------------------------SHOPPING DAY: " << shopingday << endl
         << endl
         << endl;
    buyeritem();
    cout << "************************************************************************************************************" << endl;
    cout << "************************************************************************************************************" << endl;
    cout << "                                                GET PRODUCTS                                                " << endl;
    cout << endl;

    while (!(receiptchoice == 'r' || receiptchoice == 'R'))
    {
        cout << "Enter the   item: ";
        cin >> itemname;
        cout << "Enter the  item quantity: ";
        cin >> quantity;
        file.open("stock.txt", ios::in);
        while (!file.eof())
        {
            file >> checkitem;
            file >> presentprice;
            file >> rack;
            if (itemname == checkitem)
            {
                cout << "________PRICE: " << presentprice << endl;

                sum = quantity * presentprice;
                cout << "________full PRICE: " << sum << endl
                     << endl;
                flag = 1;
            }
        }
        file.close();
        if (flag == 1)
        {

            total = total + sum;
            index++;
            cout << "__________TO GET RECEIPT PLEASE! PRESS 'R' and any other key to get more items:  ";

            cin >> receiptchoice;
            
        }
        if (flag == 0)
        {
            cout << "____________OOPS! ITEM STOCK IS FINISHED " << endl
                 << endl;
            cout << "__________TO GET RECEIPT PLEASE! PRESS 'R' and any other key to get more items ";

            cin >> receiptchoice;
        }
        flag=0;
    }

    if (shopingday == discday)
    {
        disc = (total * discrate) / 100;
        discamount = total - disc;
        cout << "------------ACTUAL AMOUNT:  " << total << endl;
        cout << "------------DISCOUNT     :  " << disc << endl;
        cout << "------------FINAL AMOUNT :  " << discamount << endl;
        cout << " --------------------HAPPY SHOPPING-------------------- " << endl
             << endl;
        file.open("buyer.txt", ios::out);
        {
            file << endl
                 << buyername << endl;
            file << total << endl;
            file << discamount;
        }
        file.close();
        cout << "Press any key to go to main menu: ";
        cin >> key;
        mainmenu();
    }
    else
    {
        cout << "------------FINAL AMOUNT :  " << total << endl;
        cout << " --------------------HAPPY SHOPPING-------------------- " << endl
             << endl;
        file.open("buyer.txt", ios::out);
        {
            file << endl
                 << buyername << endl;
            file << total << endl;
            file << total;
        }
        file.close();
        cout << "Press any key to go to main menu: ";
        cin >> key;
        mainmenu();
    }
}
void buyeritem()
{

    fstream file;
    string itemname;
    int itemprice;

    string rack;
    cout << endl
         << endl
         << "\t\t\t---------PRODUCTS AVALIABLES--------- " << endl
         << endl;
    file.open("stock.txt", ios::in);
    while (!file.eof())
    {
        file >> itemname;
        file >> itemprice;
        file >> rack;
        cout << "ITEM: " << itemname << "\t\t\t\t\t\t\t\t\t"
             << "PRICE: " << itemprice << "  " << endl;
    }
    file.close();
}
void latestbuyer()
{
    fstream file;
    string buyername;
    string actualamount;
    string finalamount;
    char key;
    printemployeelogo();
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<LATEST BUYER RECORD" << endl
         << endl;
    file.open("buyer.txt", ios::in);
    while (!file.eof())
    {
        file >> buyername;
        file >> actualamount;
        file >> finalamount;
    }
    cout << "---------------BUYER NAME   : " << buyername << endl;
    cout << "---------------ACTUAL AMOUNT: " << actualamount << endl;
    cout << "---------------FINAL AMOUNT : " << finalamount << endl;
    file.close();

    cout << "Press any key to go to main menu: ";
    cin >> key;
    employeefunctions();
}
void viewemplPL()
{
    fstream file;
    string username;
    string password;
    char key;
    adminlogo();
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<EMPLOYEE PASSWORD AND THIER USERNAME" << endl
         << endl;
    file.open("employeelogin.txt", ios::in);
    while (!file.eof())
    {
        file >> username;
        file >> password;
        cout << "USERNAME: " << username << endl;
        cout << "PASSWORD: " << password << endl;
        cout << "----------------------------------------------------------------------------------" << endl;
    }
    file.close();
    cout << "Press any key to go to main menu: ";
    cin >> key;
    adminfunction();
}

void mainlogo()
{
    system("cls");
    cout << " _____  _    _ ____  _      _______   __   _____ _    _ _____  ______ _____   _____ _______ ____  _____  ______ " << endl;
    cout << "|  __ \\| |  | |  _ \\| |    |_   _\\ \\ / /  / ____| |  | |  __ \\|  ____|  __ \\ / ____|__   __/ __ \\|  __ \\|  ____|" << endl;
    cout << "| |__) | |  | | |_) | |      | |  \\ V /  | (___ | |  | | |__) | |__  | |__) | (___    | | | |  | | |__) | |__   " << endl;
    cout << "|  ___/| |  | |  _ <| |      | |   > <    \\___ \\| |  | |  ___/|  __| |  _  / \\___ \\   | | | |  | |  _  /|  __|  " << endl;
    cout << "| |    | |__| | |_) | |____ _| |_ / . \\   ____) | |__| | |    | |____| | \\ \\ ____) |  | | | |__| | | \\ \\| |____ " << endl;
    cout << "|_|     \\____/|____/|______|_____/_/ \\_\\ |_____/ \\____/|_|    |______|_|  \\_\\_____/   |_|  \\____/|_|  \\_\\______|" << endl;
}

void mainpic()
{
    cout << endl
         << endl
         << endl
         << endl
         << endl;
    cout << "      ,i \\                                                              PLEASE WAIT A FEW MINUTES            " << endl;
    cout << "    ,' 8b \\                                     THIS SYSYTEM IS MADE BY                " << endl;
    cout << "  ,:o   8b \\                                          MUHAMMAD ZUBAIR           " << endl;
    cout << " :  Y8. d8  \\                                                    " << endl;
    cout << "-+._ 8: d8. i:                        " << endl;
    cout << "    `:8 `8i `8  " << endl;
    cout << "      `._Y8  8:  ___    " << endl;
    cout << "         `'---Yjdp  O8m._  " << endl;
    cout << "              ,:: _,o9   `m._  " << endl;
    cout << "              | o8P    _.8d8P:-._ " << endl;
    cout << "              :8P   _oodP4   ,dP:`-._ " << endl;
    cout << "               `: dd8P'   ,odP'  do8'`. " << endl;
    cout << "                 `-:   ,o8PP ,o8P: ,8P`. " << endl;
    cout << "                   `._dPP   ddP'  ,8P' ,.. " << endl;
    cout << "                      :`._ PP:  ,8P: _d8:L..__ " << endl;
    cout << "                          `:-._88:  .PP,7 ,8.--.._ " << endl;
    cout << "                               :::---- | d8. :8O-O. " << endl;
    cout << "                                          l d8  d8  dP/ " << endl;
    cout << "                                           \\::J88 -Po" << endl;
    cout << "                                            \\ ,8F  87 " << endl;
    cout << "                                             :.88  ,: " << endl;
}
void newemployeePL()
{
    fstream file;
    string username;
    string password;
    char key;
    system("cls");
    adminlogo();
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<ADD EMPLOYEE PASSWORD & PASSWORD " << endl
         << endl;
f:
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Enter the username: ";
    cin >> username;
    cout << endl;
    cout << "Enter the password: ";
    cin >> password;
    cout << "--------------------------------------------------------------------------------------------------------------------" << endl;

    file.open("employeelogin.txt", ios::app);
    file << endl
         << username << endl;
    file << password;
    file.close();
    cout << "_____________NEW EMPLOYEE PASSWORD & USERNAME SUCCESSFULLY ADDED" << endl;
    cout << "Enter 'n' to add more items  and press any other key to go to main menu: ";
    cin >> key;
    if (key == 'n')
        goto f;
    else
        adminfunction();
}
void updateprice(string itemname, string presentrack, int presentitemprice)
{
    fstream file;
    string itemname1[10000];
    string itemrack[10000];
    int itemprice[10000];
    int index = 0;
    int x;
    char key;
    int newprice;
    cout << endl
         << "Enter the new price: ";
    cin >> newprice;

    file.open("stock.txt", ios::in);
    while (!file.eof())
    {
        file >> itemname1[index];
        file >> itemprice[index];
        file >> itemrack[index];
        index++;
    }
    file.close();

    for (x = 0; x < index; x++)
    {
        if (itemname1[x] == itemname)
        {
            itemprice[x] = newprice;
        }
    }
    file.open("stock.txt", ios::out);
    {
        file << " ";
    }
    file.close();
    file.open("stock.txt", ios::app);
    {
        for (int y = 0; y < index; y++)
        {
            file << endl
                 << itemname1[y] << endl;
            file << itemprice[y] << endl;
            file << itemrack[y];
        }
    }
    file.close();
    cout << endl
         << "________________PRODUCT PRICE CHANGED SUCCESSFULLY " << endl;
    cout << "Press any key to go to main menu: ";
    cin >> key;
    adminfunction();
}
void updateemployee(string presentname, int presentsalary, string presentshift, int presentphone)
{
    fstream file;
    string name[10000];
    string shift[10000];
    int salary[10000];
    int phone[10000];
    int index = 0;
    int x;
    char key;
    int newsalary;
    string newshift;
    cout << "NAME OF EMPLOYEE: " << presentname << endl;
    cout << "SALARY OF EMPLOYEE: " << presentsalary << endl;
    cout << "SHIFT OF EMPLOYEE: " << presentshift << endl;
    cout << "PHONE OF EMPLOYEE: " << presentphone << endl;
    cout << "CHANGE SALARY : ";
    cin >> newsalary;
    cout << "CHANGE SHIFT: ";
    cin >> newshift;

    file.open("employee.txt", ios::in);
    while (!file.eof())
    {
        file >> name[index];
        file >> salary[index];
        file >> shift[index];
        file >> phone[index];
        index++;
    }
    file.close();

    for (x = 0; x < index; x++)
    {
        if (name[x] == presentname)
        {
            salary[x] = newsalary;
            shift[x] = newshift;
        }
    }
    file.open("employee.txt", ios::out);
    {
        file << " ";
    }
    file.close();
    file.open("employee.txt", ios::app);
    {
        for (int y = 0; y < index; y++)
        {
            file << endl
                 << name[y] << endl;
            file << salary[y] << endl;
            file << shift[y] << endl;
            file << phone[y];
        }
    }
    file.close();
    cout << endl
         << "________________EMPLOYEE DETAIL CHANGED SUCCESSFULLY " << endl;
    cout << "Press any key to go to main menu: ";
    cin >> key;
    adminfunction();
}
void changeemployeePU()
{
    char key;
    fstream file;
    int flag = 0;
    string username;
    string password;
    string fileusername;
    string filepassword;
    system("cls");
    printemployeelogo();
    cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<CHANGE YOUR PASSWORD " << endl
         << endl;
    cout << "ENTER YOUR USERNAME: ";
    cin >> username;
    cout << "ENTER YOUR PASSWORD: ";
    cin >> password;
    file.open("employeelogin.txt", ios::in);
    while (!file.eof())
    {
        file >> fileusername;
        file >> filepassword;

        if (username == fileusername && password == filepassword)
        {
            updateemployeePU(fileusername, filepassword);
            flag = 1;
        }
    }
    file.close();
    if (flag == 0)
    {
        cout << "______________________EMPLOYEE NOT FOUND!" << endl;
        cout << "Enter any key to go to the main menu: ";
        cin >> key;
        employeefunctions();
    }
}
void updateemployeePU(string fileusername, string filepassword)
{
    fstream file;
    string name[10000];
    string password[10000];
    int index = 0;
    int x;
    char key;
    string newusername;
    string newpassword;
    cout << endl
         << "Enter the new username: ";
    cin >> newusername;
    cout << "Enter the new password: ";
    cin >> newpassword;
    file.open("employeelogin.txt", ios::in);
    while (!file.eof())
    {
        file >> name[index];
        file >> password[index];
        index++;
    }
    file.close();

    for (x = 0; x < index; x++)
    {
        if (name[x] == fileusername)
        {
            name[x] = newusername;
            password[x] = newpassword;
        }
    }
    file.open("employeelogin.txt", ios::out);
    {
        file << " ";
    }
    file.close();
    file.open("employeelogin.txt", ios::app);
    {
        for (int y = 0; y < index; y++)
        {
            file << endl
                 << name[y] << endl;
            file << password[y];
        }
    }
    file.close();
    cout << endl
         << "________________PASSWORD AND USERNAME CHANGED SUCCESSFULLY " << endl;
    cout << "Press any key to go to main menu: ";
    cin >> key;
    employeefunctions();
}
