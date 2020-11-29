//
//  main.cpp
//  Bank Account Information
//  Created by cesarsa2 on 3/2/18.
//  Copyright © 2018 cesarsa2. All rights reserved.
//
#include <iostream>
#include "Customer.hpp"
#include "CustomerList.hpp"
#include <iomanip>
#include <string>
using namespace std;

void print(Customer customer)
{
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "|------First-Name--------| " << customer.getFirstName() << endl;
    cout << "|-------Last-Name--------| " << customer.getLastName() << endl;
    cout << "|-----------ID-----------| " << customer.getId() << endl;
    cout << "|----Checking-Balance----| $ " << customer.getCheckingBalance() << endl;
    cout << "|----Savings-Balance-----| $ " << customer.getSavingsBalance() << endl;
    cout << endl;
}

void printAllCustomer(CustomerList list)
{
    for(Customer c: list.getCustomers())
        print(c);
}

string prompt(CustomerList list)    //returns the type of search you will be performing (either search by first/last name, or ID number)
{
    char searchChoice;
    bool acceptedSearchChoice;
    string wordInsert;
    cout << "|How would you like to search?" << endl;
    cout << "|First Name, Last Name, ID" << endl;
    cout << "Enter F, L, or I" << endl;
    cout << "Enter Q to quit." << endl;
    
    do
    {
        acceptedSearchChoice = true;
        cin >> searchChoice;
        switch (toupper(searchChoice))
        {
            case 'F':
                wordInsert = "First Name";
                break;
            case 'L':
                wordInsert = "Last Name";
                break;
            case 'I':
                wordInsert = "ID";
                break;
            case 'Q':
                exit(0);
            default:
                cout << "That is not an option, try again." << endl;
                acceptedSearchChoice = false;
    
                break;
        }
    } while(acceptedSearchChoice==false || searchChoice == 'Q');
    cout << endl;
    return wordInsert;
}

void printSpecificCustomer(string &data, string &wordInsert, CustomerList list) //prints the customers that you searched for
{
    int counter = 0;
    for(Customer c: list.getCustomers())
    {
        if(wordInsert == "Last Name" && data==c.getLastName())
        {
            print(c);
            counter++;
        }
        if(wordInsert == "First Name" && data==c.getFirstName())
        {
            print(c);
            counter++;
        }
        if(wordInsert == "ID" && data==c.getId())
        {
            print(c);
            counter++;
        }
    }
    cout << "Your search yielded " << counter << " results." << endl;
}

string dataNotFound(string &data, string &wordInsert, CustomerList &list)    //shows up if a search is invalid
{
    string response;
    cout << data << " is not a customer " << wordInsert << " we have on record." << endl;
    cout << endl;
    cout << "Press any key other key to Try again or" << endl;
    cout << "Enter 0 to exit program." << endl;
    cout << "Enter 1 to search by another method." << endl;
    cout << endl;
    cin >> response;
    return response;
}

string uppercaseData(string &data, string &wordInsert)  //converts any character entry into upper case
{
    if(wordInsert!="ID")
        for(int i = 0; i < data.length(); i++)
            data[i] = toupper(data[i]);
    return data;
}

void searchByData(CustomerList list)
{
    string wordInsert = prompt(list);
    string data;
    bool found;;
    do //or name is false
    {
        found = true;
        cout << "Enter the Customer's " << wordInsert << " that you are searching for: ";
        cin >> data;
        uppercaseData(data, wordInsert);
        cout << endl;
        if(list.checkCustomerName(wordInsert, data, list)==false)
        {
            string response = dataNotFound(data, wordInsert, list);
            if(response=="0")
                exit(0);
            if(response=="1")
                searchByData(list);
            found = false;
        }
        
    } while(found == false);
    printSpecificCustomer(data, wordInsert, list);
}

void mainMenu(CustomerList list)
{
    char choice;
    
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "\t\tBank Teller Information Center" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "\t\tHow would you like to search?" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Choices:\t" << "(Enter an individual letter command)" << endl;
    cout << "P\t|\t\tPrint all Customers" << endl;
    cout << "S\t|\t\tSearch by Customer Information" << endl;
    cout << "Q\t|\t\tQuit Program" << endl;
    cout << "------------------------------------------------" << endl;
    bool accepted;
    do
    {
        accepted = true;
        cout << "Enter a Choice: ";
        cin >> choice;
        switch(toupper(choice))
        {
            case 'P':
                printAllCustomer(list);
                break;
            case 'S':
                searchByData(list);
                break;
            case 'Q':
                exit(0);
            default:
                cout << "That is not an option. Please Try again." << endl;
                accepted = false;
                break;
        }
    } while(accepted==false);
}

int main()
{
    CustomerList list("/Users/cesarsanchez 1/Desktop/red.txt");
    char choice;
    do{
        mainMenu(list);
        cout << "Do you want to perform another search?" << endl;
        cout << "Enter any key or press Q to end program." << endl;
        cin >> choice;
        choice = toupper(choice);
        cout << endl;
    } while(choice!= 'Q');
    return 0;
}
