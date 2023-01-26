//
//  Slot.h
//  C++Lesson5
//
//  Created by Ivan Konishchev on 21.01.2023.
//

#pragma once
#include "../Snack/Snack.h"

struct Slot
{
    private:
    Snack *_snack; // dinamic snack array
    int _size; // array size
    short int _currentPoint; 
  
    

    //init
    public:
    Slot();
    Slot(const int size);
    ~Slot();

    // public Methods
    public:
    int getFreeSpace() const;
    void addSnack(Snack *newSnack);
    void deleteSnack();
    void icreasePriceByPercent(int percent);
    friend std::ostream &operator<<(std::ostream &output, const Slot &m);
};