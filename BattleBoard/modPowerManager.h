//=============================================================================
//D Helper class to look after the players power and power related skills
//
//-----------------------------------------------------------------------------
#pragma once

// includes from our libraries

// system includes

// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs
class modSkill;

//=============================================================================
class modPowerManager
{
public:
  modPowerManager();
  // Constructor

  void set_power_picks(modSkill* skill);
  
  int total_power() const;

  modPowerManager(const modPowerManager&) = delete;
  // Deleted copy constructor.

  modPowerManager& operator=(const modPowerManager&) = delete;
  // Deleted assignment operator.

  virtual ~modPowerManager() = default;
  // Destructor

private:

  modSkill* m_power_picks;
};

