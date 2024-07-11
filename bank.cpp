#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <fstream>
using namespace std;

class bank
{
private:
    int pin;
    float balance;
    string id, pass, name, fname, address, phone;

public:
    void menu();
    void bank_management();
    void new_user();
    void already_user();
    void deposit();
    void withdraw();
    void transfer();
    void payment();
    void search();
    void edit();
    void del();
    void show_records();
    void show_payments();
    void user_balance();
};

void bank::menu()
{
p:
    system("cls");
    int choice;
    char ch;
    string pin, pass, email;
    cout << "\n\n\t\t\tControl Panel";
    cout << "\n\n 1. Bank Management";
    cout << "\n 2. Exit";
    cout << "\n\n Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        system("cls");
        cout << "\n\n\t\t\tBank Management";
        cout << "\n\n\t\t\tLogin Account";
        cout << "\n\n E-mail: ";
        cin >> email;
        cout << "\n\n PIN Number: ";
        for (int i = 1; i <= 4; i++)
        {
            ch = getch();
            pin += ch;
            cout << "*";
        }
        cout << "\n\n Password: ";
        for (int i = 1; i <= 8; i++)
        {
            ch = getch();
            pass += ch;
            cout << "*";
        }
        if (email == "ds15@gmail.com" && pin == "5134" && pass == "5134@dsv")
        {
            bank_management();
        }
        else
        {
            cout << "\n\n Invalid E-mail or PIN or Password, Try again...";
        }
        break;

    case 2:
        exit(0);

    default:
        cout << "\n\n Invalid choice, Please try again...";
    }
    getch();
    goto p;
}

void bank::bank_management()
{
p:
    system("cls");
    int choice;
    cout << "\n\n\t\t\tBank Management System";
    cout << "\n\n 1.  New User";
    cout << "\n 2.  Already User";
    cout << "\n 3.  Deposit";
    cout << "\n 4.  Withdraw";
    cout << "\n 5.  Transfer";
    cout << "\n 6.  Bill Payment Portal";
    cout << "\n 7.  Search User Record";
    cout << "\n 8.  Edit User Record";
    cout << "\n 9.  Delete User Record";
    cout << "\n 10. Show all User Records";
    cout << "\n 11. Show all Bill Payment Records";
    cout << "\n 12. Exit";
    cout << "\n\n Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        new_user();
        break;

    case 2:
        already_user();
        break;

    case 3:
        deposit();
        break;

    case 4:
        withdraw();
        break;

    case 5:
        transfer();
        break;

    case 6:
        payment();
        break;

    case 7:
        search();
        break;

    case 8:
        edit();
        break;

    case 9:
        del();
        break;

    case 10:
        show_records();
        break;

    case 11:
        show_payments();
        break;

    case 12:
        exit(0);

    default:
        cout << "Invalid choice, Please try again...";
    }
    getch();
    goto p;
}

void bank::new_user()
{
p:
    system("cls");
    fstream file;
    int p;
    float b;
    string n, f, pa, a, ph, i;
    cout << "\n\n\t\t\tAdd new user";
    cout << "\n\n User ID: ";
    cin >> id;
    cout << "\n\n Name: ";
    cin >> name;
    cout << "\n\n Father Name: ";
    cin >> fname;
    cout << "\n\n Address: ";
    cin >> address;
    cout << "\n\n PIN number (4 digit): ";
    cin >> pin;
    cout << "\n\n Password: ";
    cin >> pass;
    cout << "\n\n Phone No.: ";
    cin >> phone;
    cout << "\n\n Current Balance: ";
    cin >> balance;
    file.open("bank.txt", ios::in);
    if (!file)
    {
        file.open("bank.txt", ios::app | ios::out);
        file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
        file.close();
    }
    else
    {
        file >> i >> n >> f >> a >> p >> pa >> ph >> b;
        while (!file.eof())
        {
            if (i == id)
            {
                cout << "\n\n User ID Already Exists...";
                getch();
                goto p;
            }
            file >> i >> n >> f >> a >> p >> pa >> ph >> b;
        }
        file.close();
        file.open("bank.txt", ios::app | ios::out);
        file << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
        file.close();
    }
    cout << "\n\n New User Account created successfully...";
}

void bank::already_user()
{
    system("cls");
    fstream file;
    string t_id;
    int found = 0;
    cout << "\n\n Already User: ";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "Error in opening file...";
    }
    else
    {
        cout << "\n\n New User ID: ";
        cin >> t_id;
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (t_id == id)
            {
                system("cls");
                cout << "\n\n Already User: ";
                cout << "\n\n User ID: " << id << "\tPIN: " << pin << "\tPassword: " << pass;
                found++;
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        if (found == 0)
        {
            cout << "\n\n User ID cannot be found";
        }
    }
}

void bank::deposit()
{
    fstream file, file1;
    string t_id;
    int found = 0;
    float dep;
    system("cls");
    cout << "\n\n\t\tDeposit Amount: ";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\nError opening file...";
    }
    else
    {
        cout << "\n\nUser ID: ";
        cin >> t_id;
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (t_id == id)
            {
                cout << "\n\n Amount for deposit: ";
                cin >> dep;
                balance += dep;
                file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                found++;
                cout << "\n\n Your Amount " << dep << " Successfully deposited...\n Remaining Balance: " << balance;
            }
            else
            {
                file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            }

            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == 0)
        {
            cout << "\n\n User ID cannot be found";
        }
    }
}

void bank::withdraw()
{
    fstream file, file1;
    string t_id;
    int found = 0;
    float with;
    system("cls");
    cout << "\n\n\t\tWithdraw Amount: ";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\nError opening file...";
    }
    else
    {
        cout << "\n\nUser ID: ";
        cin >> t_id;
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (t_id == id)
            {
                cout << "\n\n Amount for withdraw: ";
                cin >> with;
                if (with <= balance)
                {
                    balance -= with;
                    file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                    cout << "\n\n Your Amount " << with << " Successfully withdrawn...\n Remaining Balance: " << balance;
                }
                else
                {
                    file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                    cout << "\n\nYour current balance: " << balance << " is too less to withdraw";
                }
                found++;
            }
            else
            {
                file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            }

            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == 0)
        {
            cout << "\n\n User ID cannot be found";
        }
    }
}

void bank::transfer()
{
    fstream file, file1;
    string s_id, r_id;
    float amount;
    int found = 0;
    system("cls");
    cout << "\n\nAmount Transfer Option: ";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\nError opening file...";
    }
    else
    {
        cout << "\n\nSender User ID for Transaction: ";
        cin >> s_id;
        cout << "\n\nReciever User ID for Transaction: ";
        cin >> r_id;
        cout << "\n\nEnter Transfer Amount: ";
        cin >> amount;
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (s_id == id && amount <= balance)
            {
                found++;
            }
            else if (r_id == id)
            {
                found++;
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        if (found == 2)
        {
            file.open("bank.txt", ios::in);
            file1.open("bank1.txt", ios::app | ios::out);
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
            while (!file.eof())
            {
                if (s_id == id)
                {
                    balance -= amount;
                    file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                }
                else if (r_id == id)
                {
                    balance += amount;
                    file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                }
                else
                {
                    file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                }
                file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
            }
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt", "bank.txt");
            cout << "\n\nTransaction Successfull...";
        }
        else
        {
            cout << "\n\nError, Insufficient Balance or Transaction User ID's not found...";
        }
    }
}

void bank::payment()
{
    system("cls");
    fstream file, file1;
    int found = 0;
    float amount;
    string t_id, b_name;
    SYSTEMTIME x;
    cout << "\n\nBill Payment Portal: ";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\nError opening file, try again...";
    }
    else
    {
        cout << "\n\nUser ID: ";
        cin >> t_id;
        cout << "\n\nBill Name: ";
        cin >> b_name;
        cout << "\n\nEnter Bill Amount: ";
        cin >> amount;
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (t_id == id && amount <= balance)
            {
                balance -= amount;
                file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
                found++;
            }
            else
            {
                file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == 1)
        {
            GetSystemTime(&x);
            file.open("bill.txt", ios::app | ios::out);
            file << t_id << " " << b_name << " " << amount << " " << x.wHour << ":" << x.wMinute << ":" << x.wSecond << " " << x.wDay << "/" << x.wMonth << "/" << x.wYear << "\n";
            file.close();
            cout << "\n\n " << b_name << " Bill Payment Successfull...";
        }
        else
        {
            cout << "\n\nError, Insufficient Balance or Transaction User ID's not found...";
        }
    }
}

void bank::search()
{
    system("cls");
    fstream file;
    string t_id;
    int found = 0;
    cout << "\n\nSearch User Record: ";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\nError opening file...";
    }
    else
    {
        cout << "\n\nEnter User ID: ";
        cin >> t_id;
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (t_id == id)
            {
                system("cls");
                cout << "\n\nUser Record Found...";
                cout << "\n\nUser ID: " << id;
                cout << "\nName: " << name;
                cout << "\nAddress: " << address;
                cout << "\nPhone: " << phone;
                cout << "\nBallance: " << balance;
                found++;
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        if (found == 0)
        {
            cout << "\n\nUser not found, try again with correct credentials...";
        }
    }
}

void bank::edit()
{
    system("cls");
    fstream file, file1;
    string t_id, n, f, a, p, ph;
    int found = 0, pi;
    cout << "\n\nEdit User Record: ";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\nError opening file...";
    }
    else
    {
        cout << "\n\nEnter User ID: ";
        cin >> t_id;
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (t_id == id)
            {
                cout << "\n\nEnter New Details of the user...";
                cout << "\n\n Name: ";
                cin >> n;
                cout << "\n\n Father Name: ";
                cin >> f;
                cout << "\n\n Address: ";
                cin >> a;
                cout << "\n\n PIN number (4 digit): ";
                cin >> pi;
                cout << "\n\n Password: ";
                cin >> p;
                cout << "\n\n Phone No.: ";
                cin >> ph;
                file1 << " " << id << " " << n << " " << f << " " << a << " " << pi << " " << p << " " << ph << " " << balance << "\n";
                cout << "\n\nUser record updated successfully...";
                found++;
            }
            else
            {
                file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == 0)
        {
            cout << "\n\nUser not found, try again with correct credentials...";
        }
    }
}

void bank::del()
{
    system("cls");
    fstream file, file1;
    string t_id;
    int found = 0;
    cout << "\n\nEdit User Record: ";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\nError opening file...";
    }
    else
    {
        cout << "\n\nEnter User ID: ";
        cin >> t_id;
        file1.open("bank1.txt", ios::app | ios::out);
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            if (t_id == id)
            {
                cout << "\n\nUser record deleted successfully...";
                found++;
            }
            else
            {
                file1 << " " << id << " " << name << " " << fname << " " << address << " " << pin << " " << pass << " " << phone << " " << balance << "\n";
            }
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if (found == 0)
        {
            cout << "\n\nUser not found, try again with correct credentials...";
        }
    }
}

void bank::show_records()
{
    system("cls");
    fstream file;
    int found = 0;
    cout << "\n\nAll User's Record Details...";
    file.open("bank.txt", ios::in);
    if (!file)
    {
        cout << "\n\nError opening file...";
    }
    else
    {
        file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
        while (!file.eof())
        {
            cout << "\n\n\nUser ID: " << id;
            cout << "\nName: " << name;
            cout << "\nFather Name: " << fname;
            cout << "\nAddress: " << address;
            cout << "\nPin: " << pin;
            cout << "\nPassword: " << pass;
            cout << "\nPhone No.: " << phone;
            cout << "\nCurrent Balance: " << balance;
            cout << "\n\n<===============================================>";
            file >> id >> name >> fname >> address >> pin >> pass >> phone >> balance;
            found++;
        }
        file.close();
        if (found == 0)
        {
            cout << "\n\nDatabase is empty...";
        }
    }
}

void bank::show_payments()
{
    system("cls");
    fstream file;
    int found = 0;
    float amount;
    string c_date, c_time;
    cout << "\n\nAll Bill Payment's Record Details...";
    file.open("bill.txt", ios::in);
    if (!file)
    {
        cout << "\n\nError opening file...";
    }
    else
    {
        file >> id >> name >> amount >> c_time >> c_date;
        while (!file.eof())
        {
            cout << "\n\n\nUser ID: " << id;
            cout << "\nBill Name: " << name;
            cout << "\nBill Amount: " << amount;
            cout << "\nDate: " << c_date;
            cout << "\nTime: " << c_time;
            cout << "\n\n<===============================================>";
            file >> id >> name >> amount >> c_time >> c_date;
            found++;
        }
        file.close();
        if (found == 0)
        {
            cout << "\n\nDatabase is empty...";
        }
    }
}

void bank::user_balance()
{
}

main()
{
    bank obj;
    obj.menu();
}