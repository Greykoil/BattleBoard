//=============================================================================
//D <One line description>
//
// <Full description.>
//
//-----------------------------------------------------------------------------
// Class Header include
#include "vwmAdventureRecordManager.h"
//includes from our libraries

// system includes
#include <assert.h>

//=============================================================================
vwmAdventureRecordManager::vwmAdventureRecordManager(
  modAdventureRecordManager* model_ar_manager
)
//
// Constructor
//
//-----------------------------------------------------------------------------
  : m_model_ar_manager(model_ar_manager)
{
  assert(model_ar_manager != nullptr);
}

