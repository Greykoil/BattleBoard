#pragma once

#include <assert.h>
#include <string>
enum CHARACTER_RACE {
  HUMAN,
  HALF_ORC,
  ELF
};

enum CHARACTER_CLASS {
  WARRIOR,
  SCOUT,
  ACOLYTE,
  MAGE,
};

enum CHARACTER_ALIGNMENT {
  GOOD,
  NEUTRAL,
  EVIL
};
enum CHARACTER_GUILD {
  SENTINEL,
  REAVER,
  BARBARIAN,
  PALADIN,
  SKIRMISHER, 
  MONK,
  ASSASSIN, 
  ARCHER,
  BLACK_SCHOOL, 
  BLUE_SCHOOL,
  BROWN_SCHOOL,
  GREEN_SCHOOL,
  YELLOW_SCHOOL,
  GREY_SCHOOL,
  RED_SCHOOL,
  WHITE_SCHOOL,
  HOSPITALLER,
  HUMACTI,
  MICHELINE,
  WHITE_PATH,
  DRUID,
  GAUNTLET,
  GREY_PATH,
  WARDEN,
  BRETHREN,
  DARK_PATH,
  REAPER,
  SEER,
  OTHER
};

class EnumConverter {
public:
  static std::string guild_to_string(CHARACTER_GUILD guild);

  static CHARACTER_GUILD string_to_guild(std::string guild);

};
