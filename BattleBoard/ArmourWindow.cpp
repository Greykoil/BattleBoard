//=============================================================================
//D The apps main window
//
// Contains a tab list of the windows where things actually happen
//
//-----------------------------------------------------------------------------

// Class header include
#include "ArmourWindow.h"

// includes from project

//includes from QT

//=============================================================================
ArmourWindow::ArmourWindow(QWidget *parent)
//
//D Default constructor
//
//-----------------------------------------------------------------------------
  : QDialog(parent)
{
  m_ui.setupUi(this);
}

//=============================================================================
ArmourWindow::~ArmourWindow()
//
//D Default Destructor
//
//-----------------------------------------------------------------------------
{

}
