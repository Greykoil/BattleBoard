//=============================================================================
//D Class to write out the save state as an xml file. 
//
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries

// system includes
#include <string>
// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs
class modCharacter;

//=============================================================================
class xmlWriter {
public:

  xmlWriter();
  // Constructor

  void write_out_state(
    modCharacter* character,
    std::string file_name
  );
  // write out the state to an xml document

  void read_in_state(
    modCharacter* character,
    std::string file_name
  );
  // Read in the xml document and convert it to a character

  xmlWriter(const xmlWriter&) = delete;
  // Deleted copy constructor.

  xmlWriter& operator=(const xmlWriter&) = delete;
  // Deleted assignment operator.

  ~xmlWriter() = default;
  // Default Destructor

protected:

  // functions
  // variables

private:

  // friends
  // functions
  // variables
};
