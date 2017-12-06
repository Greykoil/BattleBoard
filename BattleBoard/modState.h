//=============================================================================
//D A pure vitual base class to ensure that any part of the model 
//  can be saved and loaded
//
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries
#include "3rdPartyXml\tinyxml2.h"
// system includes

// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs

//=============================================================================
class modState {
public:

  modState();
  // Constructor

  virtual tinyxml2::XMLElement* convert_to_xml(tinyxml2::XMLDocument* parent) const = 0;
  // Convert the state into an xml element

  virtual void load_from_xml(tinyxml2::XMLElement* element) = 0;
  // Load the state from an xml element

  modState(const modState&) = delete;
  // Deleted copy constructor.

  modState& operator=(const modState&) = delete;
  // Deleted assignment operator.

  virtual ~modState() = default;
  // Default Destructor

protected:

  // functions
  // variables

private:

  // friends
  // functions
  // variables
};
