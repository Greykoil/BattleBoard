//=============================================================================
//D View model interface for an adventure record
//
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries

// system includes

// class predeclarations to avoid header file inclusion
// types: classes, enums, typedefs
class modAdventureRecord;
class vieAdventureRecord;

//=============================================================================
class vwmAdventureRecord {
public:

  vwmAdventureRecord(
    modAdventureRecord* model_adventure_record
  );
  // Constructor

  vwmAdventureRecord(const vwmAdventureRecord&) = delete;
  // Deleted copy constructor.

  vwmAdventureRecord& operator=(const vwmAdventureRecord&) = delete;
  // Deleted assignment operator.

  ~vwmAdventureRecord() = default;
  // Default Destructor

protected:

  // functions
  // variables

private:

  // friends
  // functions
  // variables
  modAdventureRecord* m_model_adventure_record;

  vieAdventureRecord* m_view_adventure_record;
};
