//
//  Snack.cpp
//  C++Lesson5
//
//  Created by Ivan Konishchev on 21.01.2023.
//

#include "Snack.h"

Snack::Snack(char const *snackName, double price) : _isEmpty(false), _snackName(snackName), _price(price)
{
}
Snack::~Snack()
{
    std::cout << "delete Snack ...\n";
}

// Overloading the output operator to the console
std::ostream &operator<<(std::ostream &output, const Snack &m)
{
    if (m._isEmpty)
    {
        output << "Empty cell" << std::endl;
    }
    else
    {
        output << "Snack name: " << m._snackName << " , price: " << m._price;
    }
    return output;
}
