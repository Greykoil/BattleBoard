//=============================================================================
//D A character ability. 
//
//-----------------------------------------------------------------------------
#pragma once

// includes from our libraries

// system includes
#include <string>
// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs

enum ABILITY_FREQUENCY {
  PER_SECTIONAL,
  PER_DAY,
  PER_EVENT,
  ONCE_EVER
};

//=============================================================================
class modAbility
{
public:
  modAbility();
  // Constructor

  std::string get_name() const;
  void set_name(std::string value);

  ABILITY_FREQUENCY get_frequency() const;
  void set_frequency(ABILITY_FREQUENCY value);

  int get_uses() const;
  void set_uses(int value);

  modAbility(const modAbility&) = delete;
  // Deleted copy constructor.

  modAbility& operator=(const modAbility&) = delete;
  // Deleted assignment operator.

  virtual ~modAbility() = default;
  // Destructor

private:

  std::string m_name;

  ABILITY_FREQUENCY m_frequency;
  
  int m_uses;

};

