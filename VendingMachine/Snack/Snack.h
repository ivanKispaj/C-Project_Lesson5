//
//  Snack.h
//  C++Lesson5
//
//  Created by Ivan Konishchev on 21.01.2023.
//

#pragma once
#include <iostream>

struct Snack
{
  private:
  char const *snackName;
  bool isEmpty;
  public:
  double price;
  // init
  Snack(); //default init
  Snack(char const *snackName, double price = 0); // init with added snack name
  
   // public methods
  friend std::ostream &operator<<(std::ostream &output, const Snack &m );
};