//
//  Customer.hpp
//  Created by cesarsa2 on 3/2/18.
//  Copyright © 2018 cesarsa2. All rights reserved.
//

#ifndef Customer_hpp
#define Customer_hpp

#include <sstream>
#include <string>

class Customer
{
public:
    Customer(std::string studentInformation);
    std::string getFirstName();
    std::string getLastName();
    std::string getName();
    std::string getId();
    float getCheckingBalance();
    float getSavingsBalance();
    
private:
    std::string firstName;
    std::string lastName;
    std::string id;
    double checking;
    double savings;
    
};


#endif
