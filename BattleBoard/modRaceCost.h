//=============================================================================
//D Class to hold and return information about cost for a skill for a 
//  specific race
//
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries
#include "modCharacterDetailsEnum.h"
// system includes

// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs

//=============================================================================
class modRaceCost {
public:

  modRaceCost(
    int warrior_cost, 
    int scout_cost, 
    int acoltye_cost, 
    int mage_cost
  );
  // Constructor

  int cost_for_class(CHARACTER_CLASS character_class) const;
  // Return the correct cost for the given class

  modRaceCost(const modRaceCost&) = delete;
  // Deleted copy constructor.

  modRaceCost& operator=(const modRaceCost&) = delete;
  // Deleted assignment operator.

  ~modRaceCost() = default;
  // Default Destructor

protected:

  // functions
  // variables

private:

  // friends
  // functions
  // variables
  int m_warrior_cost;
  int m_scout_cost;
  int m_acolyte_cost;
  int m_mage_cost;

};
