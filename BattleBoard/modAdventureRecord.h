//=============================================================================
//D The details for a specific adventure record
//
// 
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries
#include "modState.h"
// system includes

// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs
class vieAdventureRecordWidget;

  enum ADVENTURE_RECORD_LENGTH {
    ADVENTURE_WEEKEND,
    SPECIAL,
    HEROQUEST,
    OTHER_LENGTH
  };
  enum ADVENTURE_RECORD_TYPE {
    MONSTERED,
    REFFED,
    PLAYED,
    OTHER_TYPE
  };

//=============================================================================
class modAdventureRecord : public modState {
public:

  modAdventureRecord(
    ADVENTURE_RECORD_LENGTH length = ADVENTURE_RECORD_LENGTH::OTHER_LENGTH,
    ADVENTURE_RECORD_TYPE type = ADVENTURE_RECORD_TYPE::OTHER_TYPE
  );
  // Constructor

  virtual tinyxml2::XMLElement* convert_to_xml(
    tinyxml2::XMLDocument* parent
  ) const override;
  // Convert the state into an xml element

  virtual void load_from_xml(tinyxml2::XMLElement* element) override;
  // Load the state from an xml element

  void set_view(vieAdventureRecordWidget* view);
  // Set m_view

  void set_type(ADVENTURE_RECORD_TYPE type);
  // Set m_type

  ADVENTURE_RECORD_TYPE get_type() const;
  // Get m_type

  void set_length(ADVENTURE_RECORD_LENGTH length);
  // set m_length

  ADVENTURE_RECORD_LENGTH get_length() const;
  // Get m_length

  int get_points() const;
  // get m_points

  void set_points(int points);
  // set m_points

  modAdventureRecord(const modAdventureRecord&) = delete;
  // Deleted copy constructor.

  modAdventureRecord& operator=(const modAdventureRecord&) = delete;
  // Deleted assignment operator.

  ~modAdventureRecord() = default;
  // Destructor

protected:

  // functions
  void update_points();
  // Update the number of points for the length/type combo

  // variables

private:

  // friends
  // functions
  // variables
  
  ADVENTURE_RECORD_LENGTH m_length;
  
  ADVENTURE_RECORD_TYPE m_type;

  int m_points;
  // The points gained for the event

  vieAdventureRecordWidget* m_view;
  // The gui element that will display the event details
};
