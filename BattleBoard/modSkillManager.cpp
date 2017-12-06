//=============================================================================
//D A class that takes skilltree.xml and turns it into a structure of 
//  classes for each skill
//
//-----------------------------------------------------------------------------

// Class header include 
#include "modSkillManager.h"
#include "vwmSkillPage.h"

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
//-----------------------------------------------------------------------------
  : m_skill_tree(),
    m_view_model(nullptr)
{

}

//=============================================================================
void modSkillManager::set_view_model(vwmSkillPage * view_model)
//
//-----------------------------------------------------------------------------
{
  assert(view_model != nullptr);
  m_view_model = view_model;
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
  m_view_model->update_displayed_skills();
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

  m_skill_tree.push_back(std::make_unique<modSkill>(
    name, 
    cost, 
    max_picks, 
    is_status, 
    pre_reqs
  ));

  return true;
}

