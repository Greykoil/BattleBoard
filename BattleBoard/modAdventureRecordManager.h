//=============================================================================
//D <One line description>
//
// <Full description.>
//
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries
#include "modAdventureRecord.h"
#include "vieAdventureRecordWindow.h"
// system includes
#include <memory>
#include <vector>
// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs

//=============================================================================
class modAdventureRecordManager {
public:

  modAdventureRecordManager();
  // Constructor

  void set_view(vieAdventureRecordWindow* view);
  // set m_view_model

  modAdventureRecord* add_new_adventure();
  // Add a new adventure to the list and return ptr to it

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
};
