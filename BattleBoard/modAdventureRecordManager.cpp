//=============================================================================
//D <One line description>
//
// <Full description.>
//
//-----------------------------------------------------------------------------
// includes from our libraries
#include "modAdventureRecordManager.h"

// system includes
#include <assert.h>

//=============================================================================
modAdventureRecordManager::modAdventureRecordManager()
//
// <Full Description>
//
//-----------------------------------------------------------------------------
{

}

//=============================================================================
void modAdventureRecordManager::set_view_model(vwmAdventureRecordManager * view_model)
//
//D
//
//-----------------------------------------------------------------------------
{
  assert(view_model != nullptr);
  m_view_model = view_model;
}

//=============================================================================
modAdventureRecordManager::~modAdventureRecordManager()
//
// <Full Description>
//
//-----------------------------------------------------------------------------
{

}

