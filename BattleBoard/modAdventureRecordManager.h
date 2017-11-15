//=============================================================================
//D <One line description>
//
// <Full description.>
//
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries

// system includes

// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs
class vwmAdventureRecordManager;

//=============================================================================
class modAdventureRecordManager {
public:

  modAdventureRecordManager();
  // Constructor

  void set_view_model(vwmAdventureRecordManager* view_model);
  // set m_view_model

  modAdventureRecordManager(const modAdventureRecordManager&) = delete;
  // Deleted copy constructor.

  modAdventureRecordManager& operator=(const modAdventureRecordManager&) = delete;
  // Deleted assignment operator.

  ~modAdventureRecordManager();
  // Destructor

protected:

  // functions
  // variables

private:

  // friends
  // functions
  // variables

  vwmAdventureRecordManager* m_view_model;
};
