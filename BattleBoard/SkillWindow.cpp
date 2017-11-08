//=============================================================================
//D The apps main window
//
// Contains a tab list of the windows where things actually happen
//
//-----------------------------------------------------------------------------

// Class header include
#include "SkillWindow.h"

// includes from project

//includes from QT

//=============================================================================
SkillWindow::SkillWindow(QWidget *parent)
//
//D Default constructor
//
//-----------------------------------------------------------------------------
: QDialog(parent)
{
  m_ui.setupUi(this);
}

//=============================================================================
SkillWindow::~SkillWindow()
//
//D Default Destructor
//
//-----------------------------------------------------------------------------
{

}
