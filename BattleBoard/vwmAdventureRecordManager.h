//=============================================================================
//D View model class to manage the collection of adventure records
//
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries

// system includes

// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs
class modAdventureRecordManager;

//=============================================================================
class vwmAdventureRecordManager {
public:

  vwmAdventureRecordManager(
    modAdventureRecordManager* model_ar_manager
  );
  // Constructor

  vwmAdventureRecordManager(const vwmAdventureRecordManager&) = delete;
  // Deleted copy constructor.

  vwmAdventureRecordManager& operator=(const vwmAdventureRecordManager&) = delete;
  // Deleted assignment operator.

  ~vwmAdventureRecordManager() = default;
  // Default Destructor

protected:

  // functions
  // variables

private:

  // friends
  // functions
  // variables
  modAdventureRecordManager* m_model_ar_manager;
};
