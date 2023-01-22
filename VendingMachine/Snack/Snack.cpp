//
//  Snack.cpp
//  C++Lesson5
//
//  Created by Ivan Konishchev on 21.01.2023.
//

#include "Snack.h"
#include <string>
#include <iostream>

// init
Snack::Snack(char const *snackName, double price)
{
    this->price = price;
    this->snackName = snackName;
}

// deinit
Snack::~Snack()
{
    if (this->snackName) {

       std::cout << "Delite snack on to destructor Snack:  " << this->snackName << std::endl;
    } else {
        std::cout << "Delite snack on to destructor Snack: ...\n";
    }

}

// returтs snack name
std::string Snack::getSnackName() const
{
    return this->snackName;
}

// Overloading the output operator to the console
std::ostream &operator<<(std::ostream &output, const Snack &m ) 
{
       output << "Snack name: " << m.snackName << " , price: " << m.price << std::endl;       
       return output;
}

