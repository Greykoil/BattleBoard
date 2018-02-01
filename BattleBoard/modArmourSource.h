//=============================================================================
//D A class to track any given source of armour the character has
//
//-----------------------------------------------------------------------------
#pragma once

// includes from our libraries

// system includes
#include <string>
// class predeclarations to avoid header file inclusion


// types: classes, enums, typedefs

//=============================================================================
class modArmourSource
{
public:
  modArmourSource();
  // Constructor

  void set_name(std::string name);

  int get_physical() const;
  void set_physical(int value);

  int get_power() const;
  void set_power(int value);

  int get_magic() const;
  void set_magic(int value);

  int get_evil() const;
  void set_evil(int value);

  int get_undead() const;
  void set_undead(int value);

  int get_dex() const;
  void set_dex(int value);

  modArmourSource(const modArmourSource&) = delete;
  // Deleted copy constructor.

  modArmourSource& operator=(const modArmourSource&) = delete;
  // Deleted assignment operator.

  virtual ~modArmourSource() = default;
  // Destructor

private:

  std::string m_name;

  int m_physical;
  int m_power;
  int m_magic;
  int m_evil;
  int m_undead;
  int m_dexterity;


};

