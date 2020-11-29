//
//  CustomerList.cpp
//  Created by cesarsa2 on 3/2/18.
//  Copyright © 2018 cesarsa2. All rights reserved.
//
#include "CustomerList.hpp"

using namespace std;

CustomerList::CustomerList(string filePath)
{
    ifstream customerFile(filePath);
    string lineContents;
    while(!customerFile.eof())
    {
        getline(customerFile, lineContents);
        Customer c(lineContents);
        customers.push_back(c);
    }
    customerFile.close();
}

vector<Customer> CustomerList::getCustomers()
{
    vector<Customer> toReturn;
    for(Customer c: customers)
        toReturn.push_back(c);
    return toReturn;
}


bool CustomerList::checkCustomerName(string wordInsert, string data, CustomerList list)
{
    for(Customer c: list.getCustomers())
    {
        if(wordInsert == "Last Name" && data==c.getLastName())
            return true;
        if(wordInsert == "First Name" && data==c.getFirstName())
            return true;
        if(wordInsert == "ID" && data==c.getId())
            return true;
    }
    return false;
}


