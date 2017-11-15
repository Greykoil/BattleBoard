//=============================================================================
//D View model interface for an adventure record
//
//-----------------------------------------------------------------------------
// Class Header include
#include "vwmAdventureRecord.h"
//includes from our libraries

// system includes
#include <assert.h>

//=============================================================================
vwmAdventureRecord::vwmAdventureRecord(
  modAdventureRecord* model_adventure_record
)
//
// Constructor
//
//-----------------------------------------------------------------------------
  : m_model_adventure_record(model_adventure_record)
{
  assert(model_adventure_record != nullptr);
}

