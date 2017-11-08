//=============================================================================
//D The apps main window
//
// Contains a tab list of the windows where things actually happen
//
//-----------------------------------------------------------------------------

// Class header include
#include "AdventureRecordWindow.h"

// includes from project

//includes from QT

//=============================================================================
AdventureRecordWindow::AdventureRecordWindow(QWidget *parent)
//
//D Default constructor
//
//-----------------------------------------------------------------------------
  : QDialog(parent)
{
  m_ui.setupUi(this);
}

//=============================================================================
AdventureRecordWindow::~AdventureRecordWindow()
//
//D Default Destructor
//
//-----------------------------------------------------------------------------
{

}
