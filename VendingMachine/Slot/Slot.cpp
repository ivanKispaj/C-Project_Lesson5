//
//  Slot.cpp
//  C++Lesson5
//
//  Created by Ivan Konishchev on 21.01.2023.
//

#include "Slot.h"
#include "../Snack/Snack.h"
#include <iostream>

Slot::Slot(int size)
{
    this->size = size;
    this->freeSpace = size;
    snack = new Snack[size];
}


int Slot::getFreeSpace() const 
{
    return freeSpace;
}

void Slot::addSnack(Snack snack)
{
    if (this->freeSpace > 0) {
        if ((snack.getSnackName()) != Empty) {
            this->snack[this->freeSpace - 1] = snack;
            this->freeSpace--;  
        } 
    
    } else {
        std::cout << "Все слоты заняты\n";
    }
    
}

SnackType Slot::getSnake() const
{
    if (freeSpace == size) {
        return Empty;
    } else {
        return this->snack[this->freeSpace].getSnackName();
    }
}

void Slot::printSlot() 
{
    for(int i = this->size ; i > 0; i--)
    {
        std::cout << i << std::endl;
        //SnackType type = this->snack[i].getSnackName();
        switch (this->snack[i - 1].getSnackName())
        {
        case Snikers:
        std::cout << "Snikers\n";
            break;
        case Bounty:
        std::cout << "Bounty\n";
            break;
        case Empty:
        std::cout << "Empty slot\n";
            break;
        case Twix:
        std::cout << "Twix\n";
            break;
        default:
            break;
        }
    }
}
