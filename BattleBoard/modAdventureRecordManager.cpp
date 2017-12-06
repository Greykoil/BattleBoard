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
void modAdventureRecordManager::set_view(vieAdventureRecordWindow* view)
//
//D
//
//-----------------------------------------------------------------------------
{
  assert(view != nullptr);
  m_view = view;
}

//=============================================================================
modAdventureRecord* modAdventureRecordManager::add_new_adventure()
//
//D Create a new adventure and add it to the list and return ptr to it
//
//-----------------------------------------------------------------------------
{
  m_adventures.push_back(std::make_unique<modAdventureRecord>());
  return m_adventures[m_adventures.size() - 1].get();
}

//=============================================================================
int modAdventureRecordManager::get_total_points() const
//
//D Get the total number of points available
//
//-----------------------------------------------------------------------------
{
  int total = 0;
  for (auto& record : m_adventures) {
    total += record->get_points();
  }
  return total;
}
