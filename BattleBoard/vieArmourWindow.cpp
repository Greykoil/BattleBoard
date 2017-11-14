//=============================================================================
//D The apps main window
//
// Contains a tab list of the windows where things actually happen
//
//-----------------------------------------------------------------------------

// Class header include
#include "vieArmourWindow.h"

// includes from project

//includes from QT

//=============================================================================
vieArmourWindow::vieArmourWindow(QWidget *parent)
//
//D Default constructor
//
//-----------------------------------------------------------------------------
  : QDialog(parent)
{
  m_ui.setupUi(this);
}

//=============================================================================
vieArmourWindow::~vieArmourWindow()
//
//D Default Destructor
//
//-----------------------------------------------------------------------------
{

}
