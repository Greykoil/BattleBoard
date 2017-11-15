//=============================================================================
//D The apps main window
//
// Contains a tab list of the windows where things actually happen
//
//-----------------------------------------------------------------------------

// Class header include
#include "vieMainWindow.h"

// includes from project
#include "vieAdventureRecordWindow.h"
#include "vieSkillWindow.h"
#include "vieCharacterWindow.h"
#include "vwmCharacter.h"
// standard library includes
#include <assert.h>

//includes from QT
#include <QVBoxLayout>

//=============================================================================
vieMainWindow::vieMainWindow(
  vwmCharacter* character_view_model, 
  QWidget *parent
)
// 
//D Default constructor sets up the list list of tabs 
// 
//-----------------------------------------------------------------------------
: QMainWindow(parent),
  m_view_model(character_view_model),
  m_ui(),
  m_tab_list()
{
  assert(character_view_model != nullptr);
  m_ui.setupUi(this);
  m_view_model->set_main_window(this);
  add_tabs();
}


//=============================================================================
void vieMainWindow::add_tabs()
//
//D Add the tabs that the main window displays and manages
//
//-----------------------------------------------------------------------------
{
  // Add the tabs to storeage
  m_tab_list.push_back(std::make_unique<vieCharacterWindow>(m_view_model));
  m_tab_list.push_back(std::make_unique<vieSkillWindow>(m_view_model->get_skill_view_model()));
  m_tab_list.push_back(std::make_unique<vieAdventureRecordWindow>(m_view_model->get_adventure_record_view_model()));
  
  // Add the tabs to the widget that displays them
  for (auto& window : m_tab_list) {
    m_ui.tabWidget->addTab(window.get(), window.get()->windowTitle());
  }
}

//=============================================================================
void vieMainWindow::actionOpen()
//
//D Called when the open file menu button is pushed. 
// To Do: Make this actually open a file
//
//-----------------------------------------------------------------------------
{

}

//=============================================================================
void vieMainWindow::actionNew()
//
//D Called when the new file menu button is pushed
//
//-----------------------------------------------------------------------------
{

}

//=============================================================================
void vieMainWindow::actionSave()
//
//0 Called when the save file button is pushed
//
//-----------------------------------------------------------------------------

{

}
