#include <iostream>
#include <fstream>
using namespace std;

class POS {
protected:
    string name;
    int code;

public:
    POS(string name = "unknown", int code = 00000) {
        this->name = name;
        this->code = code;
    }

    void setvalues() {
        cout << "Enter name: \n";
        cin >> name;
        cout << "Enter code: \n";
        cin >> code;
    }

    string getname() {
        return name;
    }

    int getcode() {
        return code;
    }

    void display() {
        ofstream f1;
        f1.open("POS.txt", ios::app);
        f1 << "Name: " << name << endl;
        f1 << "Code: " << code << endl;
        f1.close();
    }
};

class Product : public POS {
protected:
    double price;
    int stock;

public:
    Product(double price = 0, int stock = 0) {
        this->price = price;
        this->stock = stock;
    }

    void setval2() {
        cout << "Please Add Product Details:\n\n";
        setvalues();
        cout << "Enter Price:\n";
        cin >> price;
        cout << "Enter Stock:\n";
        cin >> stock;
    }

    double getprice() {
        return price;
    }

    void displayP() {
        ofstream file;
        file.open("Product.txt", ios::app);
        file << "PRODUCT:\n";
        file << "------------------\n";
        file << "Name: " << name << endl;
        file << "Code: " << code << endl;
        file << "Stock: " << stock << endl;
        file << "Price: " << price << endl;
        file << "------------------\n";
        file.close();
    }
};

class Supplier : public POS {
public:
    void setval3() {
        cout << "Please enter supplier credentials\n";
        setvalues();
    }

    void displayS() {
        ofstream f1;
        f1.open("Supplier.txt", ios::app);
        f1 << "SUPPLIER:\n";
        f1 << "Name: " << name << endl;
        f1 << "Code: " << code << endl;
        f1.close();
    }
};

class Employee : public POS {
public:
    void createEmp() {
        cout << "Please enter Employee credentials\n";
        setvalues();
    }

    void displayE() {
        ofstream f1;
        f1.open("Employee.txt", ios::app);
        f1 << "EMPLOYEE DATA:\n";
        display();
        f1.close();
    }
};

int main() {
    int num, num1, num2;
    int cmmnd;

    system("cls");

P0:
    system("cls");
    cout << "<Point Of Sale Application>\n\n";
    cout << "Sections:\n\n";
    cout << "Press 1 for Admin Section.\n";
    cout << "Press 2 for Customer Section.\n\n";
    cout << "Press any other key to terminate the program\n";
    cin >> cmmnd;

    switch (cmmnd) {
    case 1: {
    P1:
        system("cls");
        cout << "<Admin Section>\n\n";
        cout << "Which Sub-Section do you want to access?\n\n";
        cout << "1. Products Section\n";
        cout << "2. Supplier Section\n";
        cout << "3. Employee Section\n";
        cout << "0. Exit Program\n";
        int cmmnd2;
        cin >> cmmnd2;

        switch (cmmnd2) {
        case 1: {
        P2:
            system("cls");
            cout << "<Products Section>\n\n";
            cout << "1. Create new product.\n";
            cout << "2. Go back to Admin Section.\n";
            cout << "3. Go back to Main Screen.\n";
            int cmmnd3;
            cin >> cmmnd3;

            switch (cmmnd3) {
            case 1: {
                system("cls");
                cout << "<Create Product>\n\n";
                cout << "How many products do you want to add?\n";
                cin >> num;
                Product a[num];

                for (int i = 0; i < num; i++) {
                    a[i].setval2();
                    system("cls");
                    a[i].displayP();
                }
                cout << "Added Successfully\n\n";
                goto P1;
            }
            case 2:
                goto P1;
            case 3:
                goto P0;
            }
        }
        case 2: {
        S2:
            system("cls");
            cout << "<Add Supplier>\n\n";
            cout << "How many Suppliers?\n";
            cin >> num1;
            Supplier b[num1];

            for (int j = 0; j < num1; j++) {
                b[j].setval3();
                system("cls");
                b[j].displayS();
            }
            cout << "Added Successfully\n\n";
            goto P1;
        }
        case 3:
            goto P0;
        }
    }
    case 2: {
        system("cls");
        cout << "<Customer Section>\n\n";
        break;
    }
    default:
        return 0;
    }
}
