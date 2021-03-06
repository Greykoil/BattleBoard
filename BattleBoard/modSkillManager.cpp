//=============================================================================
//D A class that takes skilltree.xml and turns it into a structure of 
//  classes for each skill
//
//-----------------------------------------------------------------------------

// Class header include 
#include "modSkillManager.h"

// includes from our libraries
#include "modSkill.h"
#include "vieSkillWindow.h"
// system includes
#include <memory>
#include <assert.h>

// A macro to check the results from tinyxml2 and turn them into bools
#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != tinyxml2::XML_SUCCESS) { printf("Error: %i\n", a_eResult); return false; }
#endif

using namespace tinyxml2;

//=============================================================================
modSkillManager::modSkillManager(modCharacterDetails* character_details)
//
//-----------------------------------------------------------------------------
  : m_skill_tree(),
    m_view(nullptr),
    m_character_details(character_details)
{
  assert(character_details != nullptr);
}

//=============================================================================
void modSkillManager::set_view(vieSkillWindow* view_model)
//
//-----------------------------------------------------------------------------
{
  assert(view_model != nullptr);
  m_view = view_model;
}

//=============================================================================
tinyxml2::XMLElement * modSkillManager::convert_to_xml(
  tinyxml2::XMLDocument* parent
) const
//
//D Turn the list of skills into an xml element
//
//-----------------------------------------------------------------------------
{

  tinyxml2::XMLElement* element = parent->NewElement("Skills_List");
  for (auto& skill : m_skill_tree) {
    tinyxml2::XMLElement* child_element = skill->convert_to_xml(parent);
    element->InsertEndChild(child_element);
  }
  return element;
}

//=============================================================================
void modSkillManager::load_from_xml(tinyxml2::XMLElement* element)
//
//D Turn an xml element into a list of skills
//
//-----------------------------------------------------------------------------
{
  tinyxml2::XMLElement* child_element = element->FirstChildElement("Skill");
  while (child_element != nullptr) {
    // Find the corresponding skill in the skill tree
    std::string name = child_element->Attribute("Name");
    for (auto& skill : m_skill_tree) {
      if (skill->name() == name) {
        skill->load_from_xml(child_element);
        break;
      }
    }
    child_element = child_element->NextSiblingElement("Skill");
  }
//  m_view->redraw();
}

//=============================================================================
bool modSkillManager::create_skill_tree()
//
//D Create the available skill tree from the supporting xml document
//
//-----------------------------------------------------------------------------
{
  XMLDocument doc;
  XMLError eResult = doc.LoadFile("SkillTree.xml");
  XMLCheckResult(eResult);
  XMLNode* root_node = doc.FirstChild();
  if (root_node == nullptr) {
    return false;
  }
  XMLElement* skill = root_node->FirstChildElement("Skill");
  while (skill != nullptr) {
    skill_from_xml(skill);
    skill = skill->NextSiblingElement("Skill");
  }

  set_up_magic();
  set_up_power();
  set_up_armour();
  return true;
}

//=============================================================================
int modSkillManager::total_points_spent()
//
//D Get the total number of points for the taken skills
//
//-----------------------------------------------------------------------------
{
  int total = 0;
  for (auto& skill : m_skill_tree) {
    total += skill->total_cost();
  }
  return total;
}

//=============================================================================
int modSkillManager::num_skills() const
//
//-----------------------------------------------------------------------------
{
  return m_skill_tree.size();
}

//=============================================================================
modSkill* modSkillManager::skill(int num)
//
//-----------------------------------------------------------------------------
{
  return m_skill_tree[num].get();
}

//=============================================================================
modMagicManager* modSkillManager::get_magic_manager()
//
//-----------------------------------------------------------------------------
{
  return &m_magic_manager;
}

//=============================================================================
modPowerManager * modSkillManager::get_power_manager()
//
//-----------------------------------------------------------------------------
{
  return &m_power_manager;
}

//=============================================================================
modArmourManager* modSkillManager::get_armour_manager()
//
//D
//
//-----------------------------------------------------------------------------
{
  return &m_armour_manager;
}

//=============================================================================
int modSkillManager::life()
//
//-----------------------------------------------------------------------------
{
  modSkill* life = find_skill_by_name("Buy 3 Points of Life");

  return ((life->num_picks() * 3) + 42);
}

//=============================================================================
bool modSkillManager::skill_from_xml(tinyxml2::XMLElement* node)
//
//D Build an instance of a skill from the corresponding xml node
//
//-----------------------------------------------------------------------------
{
  std::string name = node->Attribute("Name");
  


  int max_picks;
  XMLError out = node->QueryIntAttribute("MaxPicks", &max_picks);
  XMLCheckResult(out);

  std::vector<modSkill*> pre_reqs;

  std::unique_ptr<modSkillCost> costs = read_costs(node);

  XMLElement* skill = node->FirstChildElement("Prerequisite");
  while (skill != nullptr) {
    std::string name = skill->GetText();
    for (auto& current : m_skill_tree) {
      if (current->name() == name) {
        pre_reqs.push_back(current.get());
      }
    }
    skill = skill->NextSiblingElement("Prerequisite");
  }


  bool is_status = false;

  m_skill_tree.push_back(std::make_unique<modSkill>(
    name, 
    std::move(costs), 
    max_picks, 
    is_status, 
    pre_reqs
  ));

  return true;
}

//=============================================================================
std::unique_ptr<modSkillCost> modSkillManager::read_costs(XMLElement* node)
//
//D Costs are in sub nodes for each race and class
//
//-----------------------------------------------------------------------------
{

  // Read the costs of skills for the various race/class combos
  XMLElement* human= node->FirstChildElement("HumanCost");
  XMLElement* elf= node->FirstChildElement("ElfCost");
  XMLElement* halforc = node->FirstChildElement("HalfOrcCost");

  return std::make_unique<modSkillCost>(
    cost_for_race(human),
    cost_for_race(elf),
    cost_for_race(halforc),
    m_character_details
  );
}

//=============================================================================
std::unique_ptr<modRaceCost> modSkillManager::cost_for_race(
  tinyxml2::XMLElement * node
)
//
//D Read the attributes for cost depending on class
//
//-----------------------------------------------------------------------------
{
  std::vector<std::string> points = { "Acolyte", "Warrior", "Mage", "Scout" };
  int acolyte_points = 0;
  node->QueryIntAttribute("Acolyte", &acolyte_points);

  int warrior_points = 0;
  node->QueryIntAttribute("Warrior", &warrior_points);

  int mage_points = 0;
  node->QueryIntAttribute("Mage", &mage_points);

  int scout_points = 0;
  node->QueryIntAttribute("Scout", &scout_points);
  
  return std::make_unique<modRaceCost>(
    warrior_points, 
    scout_points, 
    acolyte_points, 
    mage_points
  );
}

//=============================================================================
void modSkillManager::set_up_magic()
//
//D
//
//-----------------------------------------------------------------------------
{
  m_magic_manager.set_slot_level(find_skill_by_name("Buy Level 1 Spell Slot"), 1);
  m_magic_manager.set_slot_level(find_skill_by_name("Buy Level 2 Spell Slot"), 2);
  m_magic_manager.set_slot_level(find_skill_by_name("Buy Level 3 Spell Slot"), 3);
  m_magic_manager.set_slot_level(find_skill_by_name("Buy Level 4 Spell Slot"), 4);
  m_magic_manager.set_slot_level(find_skill_by_name("Buy Level 5 Spell Slot"), 5);
}

//=============================8================================================
void modSkillManager::set_up_power()
//
//-----------------------------------------------------------------------------
{
  m_power_manager.set_power_picks(find_skill_by_name("Buy 1 Point of Power"));
}

//=============================================================================
void modSkillManager::set_up_armour()
//
//-----------------------------------------------------------------------------
{
  m_armour_manager.add_unarmoured_dex(find_skill_by_name("Unarmoured Dexterity"));
  m_armour_manager.add_armoured_dex(find_skill_by_name("Armoured Dexterity"));
  m_armour_manager.add_mastery_skill(find_skill_by_name("Armour Proficiency"));
}

//=============================================================================
modSkill * modSkillManager::find_skill_by_name(std::string name)
//
//-----------------------------------------------------------------------------
{
  for (std::unique_ptr<modSkill>& skill : m_skill_tree) {
    if (skill->name() == name) {
      return skill.get();
    }
  }
  // Failed to find the correct skill
  assert(1 == 0);
  return nullptr;
}

