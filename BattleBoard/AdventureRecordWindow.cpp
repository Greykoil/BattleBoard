//=============================================================================
//D The window that tracks the record of where points came from
//
//-----------------------------------------------------------------------------

// Class header include
#include "AdventureRecordWindow.h"

// includes from project
#include "AdventureRecordWidget.h"

//includes from QT
#include <QTWidgets>

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

//=============================================================================
void AdventureRecordWindow::actionNewRecordButton()
//
//D The button has been pushed to add a new record to the list
//
//-----------------------------------------------------------------------------
{
  auto new_adventure = std::make_unique<AdventureRecordWidget>();
  m_adventures.push_back(std::move(new_adventure));
  m_ui.verticalLayout_2->addWidget(new_adventure.get());
}