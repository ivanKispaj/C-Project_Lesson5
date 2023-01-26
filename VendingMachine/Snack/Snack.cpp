//
//  Snack.cpp
//  C++Lesson5
//
//  Created by Ivan Konishchev on 21.01.2023.
//

#include "Snack.h"

// init
Snack::Snack()
{
    this->isEmpty = true;
}

Snack::Snack(char const *snackName, double price)
{
    this->isEmpty = false;
    this->price = price;
    this->snackName = snackName;
}


// Overloading the output operator to the console
std::ostream &operator<<(std::ostream &output, const Snack &m ) 
{
    if (m.isEmpty) {
        output << "Empty cell"  << std::endl;
    } else {
        output << "Snack name: " << m.snackName << " , price: " << m.price << std::endl;       

    }
       return output;
}
