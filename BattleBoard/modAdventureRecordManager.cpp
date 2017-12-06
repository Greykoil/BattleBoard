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
//-----------------------------------------------------------------------------
  : m_view(nullptr)
{

}

//=============================================================================
tinyxml2::XMLElement * modAdventureRecordManager::convert_to_xml(
  tinyxml2::XMLDocument* parent
) const
//
//D Convert the list of adventures into an xml element
//
//-----------------------------------------------------------------------------
{
  tinyxml2::XMLElement* element = parent->NewElement("Adventure_List");
  for (auto& adventure : m_adventures) {
    tinyxml2::XMLElement* child_element = adventure->convert_to_xml(parent);
    element->InsertEndChild(child_element);
  }
  return element;
}

//=============================================================================
void modAdventureRecordManager::load_from_xml(tinyxml2::XMLElement* element)
//
//D Load the details of the xml element into a list of adventures
//
//-----------------------------------------------------------------------------
{
  tinyxml2::XMLElement* child_element = element->FirstChildElement("Adventure");
  while (child_element != nullptr) {
    auto record = std::make_unique<modAdventureRecord>();
    record->load_from_xml(child_element);
    child_element = child_element->NextSiblingElement("Adventure");
    m_adventures.push_back(std::move(record));
  }

  assert(m_view != nullptr);
  m_view->update_after_load();
}

//=============================================================================
void modAdventureRecordManager::set_view(vieAdventureRecordWindow* view)
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
int modAdventureRecordManager::num_adventures() const
//
//-----------------------------------------------------------------------------
{
  return m_adventures.size();
}

//=============================================================================
modAdventureRecord* modAdventureRecordManager::adventure(int n)
//
//-----------------------------------------------------------------------------
{
  assert(n >= 0);
  assert(n < m_adventures.size());
  return m_adventures[n].get();
}

//=============================================================================
int modAdventureRecordManager::get_total_points() const
//
//D Get the total number of points available
//
//-----------------------------------------------------------------------------
{
  int total = 0;
  for (const std::unique_ptr<modAdventureRecord>& record : m_adventures) {
    total += record->get_points();
  }
  return total;
}
