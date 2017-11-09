//=============================================================================
//D A class that takes skilltree.xml and turns it into a structure of 
//  classes for each skill
//
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries
#include "3rdPartyXml\tinyxml2.h"
// system includes
#include <vector>
#include <memory>

// class predeclarations to avoid header file inclusion
class SkillLinear;

// types: classes, enums, typedefs

//=============================================================================
class SkillTreeCreator {
public:

  SkillTreeCreator();
  // Constructor

  bool create_skill_tree();
  // Create the skill tree 

  int num_skills() const;
  // the number of created skill

  SkillLinear* skill(int num);
  // Return the nth skill

  SkillTreeCreator(const SkillTreeCreator&) = delete;
  // Deleted copy constructor.

  SkillTreeCreator& operator=(const SkillTreeCreator&) = delete;
  // Deleted assignment operator.

  ~SkillTreeCreator();
  // Destructor

protected:

  // functions
  bool skill_from_xml(tinyxml2::XMLElement* node);
  // variables

private:

  // friends
  // functions
  // variables
  std::vector<std::unique_ptr<SkillLinear>> m_skill_tree;

};
