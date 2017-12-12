//=============================================================================
//D Class to hold and return information about cost for a skill for a 
//  specific race
//
//-----------------------------------------------------------------------------
// Class Header include
#include "modRaceCost.h"
// Includes from our libraries

// system includes
#include <assert.h>

//=============================================================================
modRaceCost::modRaceCost(
  int warrior_cost,
  int scout_cost,
  int acoltye_cost,
  int mage_cost
)
//
//-----------------------------------------------------------------------------
  : m_acolyte_cost(acoltye_cost),
    m_warrior_cost(warrior_cost),
    m_mage_cost(mage_cost),
    m_scout_cost(scout_cost)
{

}

//=============================================================================
int modRaceCost::cost_for_class(CHARACTER_CLASS character_class) const
//
//-----------------------------------------------------------------------------
{
  int points = 0;
  switch (character_class)
  {
  case WARRIOR:
    points = m_warrior_cost;
    break;
  case SCOUT:
    points = m_scout_cost;
    break;
  case ACOLYTE:
    points = m_acolyte_cost;
    break;
  case MAGE:
    points = m_mage_cost;
    break;
  default:
    // Unknown enum
    assert(1 == 0);
    break;
  }
  return points;
}

