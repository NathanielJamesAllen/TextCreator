#include <iostream>
#include <fstream>
#include <string>
//  Finally, write a similar program to input Employee name, hours worked and pay rate and calculate gross pay, with the data being placed on the screen and in a data file as it is here.
using namespace std;

void input_inventory_record(string&, double&, double&, double&);
void print_inventory_record(string, double, double, double);
void write_inventory_record(ofstream&, string, double, double, double);

int main()

{
    ofstream outfile;
    string employee_name;
    double hours, payrate, gross_value;
    string keep_on_going;

    keep_on_going = "Y";

    outfile.open("paystub.txt");

    while (keep_on_going == "Y") {
        input_inventory_record(employee_name, hours, payrate, gross_value);
        print_inventory_record(employee_name, hours, payrate, gross_value);
        write_inventory_record(outfile, employee_name, hours, payrate, gross_value);
        cout << "Do you want to keep going?  (Y/N) ";
        cin >> keep_on_going;
        cin.ignore(256, '\n');
    }

    outfile.close();

    return 0;

}

void input_inventory_record(string& ename, double& ehours, double& epayrate, double& egrosspay) {

    cout << "Enter the Employee's Name: ";
    getline(cin, ename);
    cout << "Enter the hours worked   : ";
    cin >> ehours;
    cout << "Enter the pay rate       : ";
    cin >> epayrate;
    egrosspay = ehours * epayrate;
    cin.ignore(256, '\n');

}

void print_inventory_record(string ename, double ehours, double epayrate, double egrosspay) {

    cout << ename << " " << ehours << " " << epayrate << " " << egrosspay << endl;
}

void write_inventory_record(ofstream& ofile, string ename, double ehours, double epayrate, double egrosspay) {

    ofile << ename << endl;
    ofile << ehours << endl;
    ofile << epayrate << endl;
    ofile << egrosspay << endl;
}
