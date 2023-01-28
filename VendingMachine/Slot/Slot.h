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
    Snack** _snacks {nullptr}; // dinamic snack array
    int _size; // array size
    short int _currentPoint; // Pointer to the first free space in the array
  
    

    //init
    public:
    Slot() = default;
    Slot(const int size);
    ~Slot();

    // public Methods
    public:
    int getFreeSpace() const; // Returns the number of free cells
    void addSnack(Snack *newSnack); // Added new snack to slot cell
    void deleteSnack(); // Removes the last added snow from the slot
    void icreasePriceByPercent(int percent); // increase price all snack from slot at pecent
    friend std::ostream &operator<<(std::ostream &output, const Slot &m);
};