//=============================================================================
//D The window that tracks the record of where points came from
//
//-----------------------------------------------------------------------------

// Class header include
#include "vieAdventureRecordWindow.h"

// includes from project
#include "vieAdventureRecordWidget.h"

//includes from QT
#include <QTWidgets>

//=============================================================================
vieAdventureRecordWindow::vieAdventureRecordWindow(QWidget *parent)
//
//D Default constructor
//
//-----------------------------------------------------------------------------
  : QDialog(parent)
{

  m_ui.setupUi(this);

}

//=============================================================================
vieAdventureRecordWindow::~vieAdventureRecordWindow()
//
//D Default Destructor
//
//-----------------------------------------------------------------------------
{

}

//=============================================================================
void vieAdventureRecordWindow::actionNewRecordButton()
//
//D The button has been pushed to add a new record to the list
//
//-----------------------------------------------------------------------------
{
  auto new_adventure = std::make_unique<vieAdventureRecordWidget>();
  m_adventures.push_back(std::move(new_adventure));
  m_ui.verticalLayout_2->addWidget(new_adventure.get());
}