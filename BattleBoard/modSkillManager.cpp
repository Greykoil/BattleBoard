//=============================================================================
//D A class that takes skilltree.xml and turns it into a structure of 
//  classes for each skill
//
//-----------------------------------------------------------------------------

// Class header include 
#include "modSkillManager.h"

// includes from our libraries
#include "modSkill.h"
// system includes
#include <memory>
#include <assert.h>

// A macro to check the results from tinyxml2 and turn them into bools
#ifndef XMLCheckResult
#define XMLCheckResult(a_eResult) if (a_eResult != tinyxml2::XML_SUCCESS) { printf("Error: %i\n", a_eResult); return false; }
#endif

using namespace tinyxml2;

//=============================================================================
modSkillManager::modSkillManager()
//
// Default constructor
//
//-----------------------------------------------------------------------------
  : m_skill_tree()
{

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

  //Check the skills that we have the pre-requs for


  return true;
}

//=============================================================================
int modSkillManager::num_skills() const
//
//D Get the number of available skills
//
//-----------------------------------------------------------------------------
{
  return m_skill_tree.size();
}

//=============================================================================
modSkill* modSkillManager::skill(int num)
//
//D Get the n'th skill
//
//-----------------------------------------------------------------------------
{
  return m_skill_tree[num].get();
}

//=============================================================================
bool modSkillManager::skill_from_xml(tinyxml2::XMLElement* node)
//
//D Build an instance of a skill from the corresponding xml node
//
//-----------------------------------------------------------------------------
{
  std::string name = node->Attribute("Name");
  int cost;
  XMLError out = node->QueryIntAttribute("Cost", &cost);
  XMLCheckResult(out);
  int max_picks;
  out = node->QueryIntAttribute("MaxPicks", &max_picks);
  XMLCheckResult(out);

  std::vector<modSkill*> pre_reqs;


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

  m_skill_tree.push_back(std::make_unique<modSkill>(name, cost, max_picks, is_status, pre_reqs));
  return true;
}

