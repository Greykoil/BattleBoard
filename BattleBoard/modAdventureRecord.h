//=============================================================================
//D The model for the adventure record where all the logic happens.
//
// 
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries

// system includes

// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs
class vieAdventureRecordWidget;

namespace ADVENTURERECORD {
  enum LENGTH {
    ADVENTURE_WEEKEND,
    SPECIAL,
    HEROQUEST,
    OTHER
  };
  enum TYPE {
    MONSTERED,
    REFFED,
    PLAYED,
    UNKNOWN
  };
}
//=============================================================================
class modAdventureRecord {
public:

  modAdventureRecord(
    ADVENTURERECORD::LENGTH length = ADVENTURERECORD::LENGTH::OTHER,
    ADVENTURERECORD::TYPE type = ADVENTURERECORD::TYPE::UNKNOWN
  );
  // Constructor

  void set_view(vieAdventureRecordWidget* view);
  // Set m_view

  void set_type(ADVENTURERECORD::TYPE type);
  // Set m_type

  void set_length(ADVENTURERECORD::LENGTH length);
  // set m_length

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
  // variables

private:

  // friends
  // functions
  // variables
  ADVENTURERECORD::LENGTH m_length;
  ADVENTURERECORD::TYPE m_type;

  int m_points;

  vieAdventureRecordWidget* m_view;
};
