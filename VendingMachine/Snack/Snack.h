//
//  Slot.cpp
//  C++Lesson5
//
//  Created by Ivan Konishchev on 21.01.2023.
//

#pragma once

//#include "SnackType.h"
#include <string>
struct Snack
{
   private:
   char const *snackName;

   public:
   // init
   Snack() = default; //default init
   Snack(char const *snackName); // init with added snack name
   ~Snack(); // deinit
   
   // public methods
  std::string getSnackName() const;
  friend std::ostream &operator<<(std::ostream &output, const Snack &m );
};