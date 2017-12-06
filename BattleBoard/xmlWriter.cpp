//=============================================================================
//D Class to write out the state as an xml file
//
//-----------------------------------------------------------------------------
// Class Header include
#include "xmlWriter.h"
// Includes from our libraries
#include "modCharacter.h"
#include "3rdPartyXml/tinyxml2.h"

// system includes

//=============================================================================
xmlWriter::xmlWriter()
//
// Constructor
//
//-----------------------------------------------------------------------------
{

}

//=============================================================================
void xmlWriter::write_out_state(
  modCharacter* character,
  std::string file_name
)
//
//D Write out the state as an xml document
//
//-----------------------------------------------------------------------------
{
  tinyxml2::XMLDocument xmlDoc;
  tinyxml2::XMLNode* root= xmlDoc.NewElement("Root");
  xmlDoc.InsertFirstChild(root);
  tinyxml2::XMLElement* character_node = character->convert_to_xml(&xmlDoc);
  root->InsertEndChild(character_node);
  tinyxml2::XMLError eResult = xmlDoc.SaveFile(file_name.c_str());
  
}

//=============================================================================
void xmlWriter::read_in_state(modCharacter* character, std::string file_name)
//
//D Read in the xml document and convert it to a character
//
//-----------------------------------------------------------------------------
{
  tinyxml2::XMLDocument xmlDoc;
  tinyxml2::XMLError result = xmlDoc.LoadFile(file_name.c_str());
  tinyxml2::XMLNode* root = xmlDoc.FirstChild();
  tinyxml2::XMLElement* element = root->FirstChildElement("Character");
  character->load_from_xml(element);
}

