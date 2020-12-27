//
//  Customer.cpp
//  Created by cesarsa2 on 3/2/20.
//  Copyright © 2018 cesarsa2. All rights reserved.
//
#include "Customer.hpp"
#include <sstream>
using namespace std;

Customer::Customer(string customerInformation)
{
    stringstream customerStream(customerInformation);
    customerStream >> firstName;
    customerStream >> lastName;
    customerStream >> id;
    customerStream >> checking;
    customerStream >> savings;
}
 
string Customer::getFirstName()
{
    return firstName;
}

string Customer::getLastName()
{
    return lastName;
}

string Customer::getName()
{
    return firstName + " " + lastName;
}

string Customer::getId()
{
    return id;
}

float Customer::getCheckingBalance()
{
    return checking;
}

float Customer::getSavingsBalance()
{
    return savings;
}

