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
  bool _isEmpty {true}; 
  char const *_snackName;
 
  public:
  double _price {0};
  // init
  Snack() = default; //default init
  Snack(char const *snackName, double price = 0); // init with added snack name
  ~Snack();
   // public methods
  friend std::ostream &operator<<(std::ostream &output, const Snack &m );
};