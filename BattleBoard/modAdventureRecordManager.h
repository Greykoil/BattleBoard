//=============================================================================
//D The container class for the list of adventures the character has stored
//
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries
#include "modAdventureRecord.h"
#include "vieAdventureRecordWindow.h"
#include "modState.h"
// system includes
#include <memory>
#include <vector>
// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs

//=============================================================================
class modAdventureRecordManager : public modState {
public:

  modAdventureRecordManager();
  // Constructor

  virtual tinyxml2::XMLElement* convert_to_xml(
    tinyxml2::XMLDocument* parent
  ) const override;
  // Convert the state into an xml element

  virtual void load_from_xml(tinyxml2::XMLElement* element) override;
  // Load the state from an xml element

  void set_view(vieAdventureRecordWindow* view);
  // set m_view_model

  modAdventureRecord* add_new_adventure();
  // Add a new adventure to the list and return ptr to it

  int num_adventures() const;
  // Return the number of adventures 

  modAdventureRecord* adventure(int n);
  // Return raw ptr to the nth adventure

  int get_total_points() const;
  // Get the total number of points from all records
  
  modAdventureRecordManager(const modAdventureRecordManager&) = delete;
  // Deleted copy constructor.

  modAdventureRecordManager& operator=(const modAdventureRecordManager&) = delete;
  // Deleted assignment operator.

  ~modAdventureRecordManager() = default;
  // Destructor

protected:

  // functions
  // variables

private:

  // friends
  // functions
  // variables

  std::vector<std::unique_ptr<modAdventureRecord>> m_adventures;
  // The list of adventures

  vieAdventureRecordWindow* m_view;
  // The gui page that displays the list of adventures
};
