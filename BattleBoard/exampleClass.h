//=============================================================================
//D <One line description>
//
// <Full description.>
//
//-----------------------------------------------------------------------------
#pragma once
// includes from our libraries

// system includes

// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs

//=============================================================================
class exampleClass {
public:

  exampleClass();
  // Constructor

  exampleClass(const exampleClass&) = delete;
  // Deleted copy constructor.

  exampleClass& operator=(const exampleClass&) = delete;
  // Deleted assignment operator.

  ~exampleClass();
  // Destructor

protected:

  // functions
  // variables

private:

  // friends
  // functions
  // variables
};
