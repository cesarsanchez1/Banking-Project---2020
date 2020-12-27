//
//  CustomerList.hpp
//
//  Created by cesarsa2 on 3/2/20.
//  Copyright © 2018 cesarsa2. All rights reserved.
//
#ifndef CustomerList_hpp
#define CustomerList_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>  //allows for file stream
#include <algorithm>
#include <exception>
#include "Customer.hpp"

class CustomerList
{
public:
    CustomerList(std::string filePath);
    std::vector<Customer> getCustomers();
    bool checkCustomerName(std::string wordInsert, std::string name, CustomerList List);
    
private:
     std::vector<Customer> customers;
};

#endif /* StudentList_hpp */
