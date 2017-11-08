//=============================================================================
//D The apps main window
//
// Contains a tab list of the windows where things actually happen
//
//-----------------------------------------------------------------------------

// Class header include
#include "MainWindow.h"

// includes from project
#include "AdventureRecordWindow.h"
#include "ArmourWindow.h"
#include "SkillWindow.h"

//includes from QT
#include <QVBoxLayout>

//=============================================================================
MainWindow::MainWindow(QWidget *parent)
// 
//D Default constructor sets up the list list of tabs 
// 
//-----------------------------------------------------------------------------
: QMainWindow(parent),
  m_ui(),
  m_tab_list()
{
    m_ui.setupUi(this);
    add_tabs();
}

//=============================================================================
MainWindow::~MainWindow()
//
//D Default destructor
//
//-----------------------------------------------------------------------------
{

}

//=============================================================================
void MainWindow::add_tabs()
//
//D Add the tabs that the main window displays and manages
//
//-----------------------------------------------------------------------------
{
  // Add the tabs to storeage
  m_tab_list.push_back(std::make_unique<SkillWindow>());
  m_tab_list.push_back(std::make_unique<ArmourWindow>());
  m_tab_list.push_back(std::make_unique<AdventureRecordWindow>());

  // Add the tabs to the widget that displays them
  for (auto& window : m_tab_list) {
    m_ui.tabWidget->addTab(window.get(), window.get()->windowTitle());
  }
}

//=============================================================================
void MainWindow::actionOpen()
//
//D Called when the open file menu button is pushed. 
// To Do: Make this actually open a file
//
//-----------------------------------------------------------------------------
{

}

//=============================================================================
void MainWindow::actionNew()
//
//D Called when the new file menu button is pushed
//
//-----------------------------------------------------------------------------
{

}

//=============================================================================
void MainWindow::actionSave()
//
//0 Called when the save file button is pushed
//
//-----------------------------------------------------------------------------

{

}
