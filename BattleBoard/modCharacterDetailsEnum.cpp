#include "modCharacterDetailsEnum.h"


//=============================================================================
std::string EnumConverter::guild_to_string(CHARACTER_GUILD guild)
//
//-----------------------------------------------------------------------------
{
  std::string guild_string = "";
  switch (guild)
  {
  case SENTINEL:
    guild_string = "Sentinel";
    break;
  case REAVER:
    guild_string = "Reaver";
    break;
  case BARBARIAN:
    guild_string = "Barbarian";
    break;
  case PALADIN:
    guild_string = "Paladin";
    break;
  case SKIRMISHER:
    guild_string = "Skirmisher";
    break;
  case MONK:
    guild_string = "Monk";
    break;
  case ASSASSIN:
    guild_string = "Assassin";
    break;
  case ARCHER:
    guild_string = "Archer";
    break;
  case BLACK_SCHOOL:
    guild_string = "Black School";
    break;
  case BLUE_SCHOOL:
    guild_string = "Blue School";
    break;
  case BROWN_SCHOOL:
    guild_string = "Brown School";
    break;
  case GREEN_SCHOOL:
    guild_string = "Green School";
    break;
  case YELLOW_SCHOOL:
    guild_string = "Yellow School";
    break;
  case GREY_SCHOOL:
    guild_string = "Grey School";
    break;
  case RED_SCHOOL:
    guild_string = "Red School";
    break;
  case WHITE_SCHOOL:
    guild_string = "White School";
    break;
  case HOSPITALLER:
    guild_string = "Hospitaller";
    break;
  case HUMACTI:
    guild_string = "Humacti";
    break;
  case MICHELINE:
    guild_string = "Micheline";
    break;
  case WHITE_PATH:
    guild_string = "White Path";
    break;
  case DRUID:
    guild_string = "Driud";
    break;
  case GAUNTLET:
    guild_string = "Guantlet";
    break;
  case GREY_PATH:
    guild_string = "Grey Path";
    break;
  case WARDEN:
    guild_string = "Warden";
    break;
  case BRETHREN:
    guild_string = "Brethren";
    break;
  case DARK_PATH:
    guild_string = "Dark Path";
    break;
  case REAPER:
    guild_string = "Reaper";
    break;
  case SEER:
    guild_string = "Seer";
    break;
  case OTHER:
    break;
  default:
    break;
  }
  return guild_string;
}

//=============================================================================
CHARACTER_GUILD EnumConverter::string_to_guild(std::string guild)
//
//D
//
//-----------------------------------------------------------------------------
{
  CHARACTER_GUILD character_guild;
  if (guild == "Sentinel") {
    character_guild = SENTINEL;
  }
  else if (guild == "Reaver") {
    character_guild = REAVER;
  }
  else if (guild == "Barbarian") {
    character_guild = BARBARIAN;
  }
  else if (guild == "Paladin") {
    character_guild = PALADIN;
  }
  else if (guild == "Skirmisher") {
    character_guild = SKIRMISHER;
  }
  else if (guild == "Monk") {
    character_guild = MONK;
  }
  else if (guild == "Assassin") {
    character_guild = ASSASSIN;
  }
  else if (guild == "Archer") {
    character_guild = ARCHER;
  }
  else if (guild == "Black School") {
    character_guild = BLACK_SCHOOL;
  }
  else if (guild == "Blue School") {
    character_guild = BLUE_SCHOOL;
  }
  else if (guild == "Brown School") {
    character_guild = BROWN_SCHOOL;
  }
  else if (guild == "Green School") {
    character_guild = GREEN_SCHOOL;
  }
  else if (guild == "Grey School") {
    character_guild = GREY_SCHOOL;
  }
  else if (guild == "Red School") {
    character_guild = RED_SCHOOL;
  }
  else if (guild == "White School") {
    character_guild = WHITE_SCHOOL;
  }
  else if (guild == "Yellow School") {
    character_guild = YELLOW_SCHOOL;
  }
  else if (guild == "Hospitaller") {
    character_guild = HOSPITALLER;
  }
  else if (guild == "Humacti") {
    character_guild = HUMACTI;
  }
  else if (guild == "Micheline") {
    character_guild = MICHELINE;
  }
  else if (guild == "White Path") {
    character_guild = WHITE_PATH;
  }
  else if (guild == "Druid") {
    character_guild = DRUID;
  }
  else if (guild == "Gauntlet") {
    character_guild = GAUNTLET;
  }
  else if (guild == "Grey Path") {
    character_guild = GREY_PATH;
  }
  else if (guild == "Warden") {
    character_guild = WARDEN;
  }
  else if (guild == "Brethren") {
    character_guild = BRETHREN;
  }
  else if (guild == "Dark Path") {
    character_guild = DARK_PATH;
  }
  else if (guild == "Reaper") {
    character_guild = REAPER;
  }
  else if (guild == "Seer") {
    character_guild = SEER;
  }
  else {
    // Unexpected guild
    assert(1 == 0);
  }
  return character_guild;
}
