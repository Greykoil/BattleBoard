//=============================================================================
//D The character window
//
//-----------------------------------------------------------------------------

// Class header include
#include "vieCharacterWindow.h"
#include "modCharacter.h"
// includes from project
#include "modCharacter.h"

// System inlcudes
#include <assert.h>

//includes from QT


//=============================================================================
vieCharacterWindow::vieCharacterWindow(
  modCharacter* model, 
  QWidget *parent
)
//
//D Constructor
//
//-----------------------------------------------------------------------------
  : QDialog(parent),
    m_view_model(model)
{
//  m_view_model->set_character_window(this);
  m_ui.setupUi(this);
  assert(m_view_model != nullptr);

  m_ui.gridLayout->addWidget(&m_life_widget, 0, 0);
  m_ui.gridLayout->addWidget(&m_magic_widget, 1, 0);
  m_ui.gridLayout->addWidget(&m_power_widget, 0, 1);
  m_ui.gridLayout->addWidget(&m_equipment_widget, 1, 1);

  m_ui.gridLayout->setColumnStretch(0, 1);
  m_ui.gridLayout->setColumnStretch(1, 1);
  m_ui.gridLayout->setRowStretch(0, 1);
  m_ui.gridLayout->setRowStretch(1, 1);

  update();
}

//=============================================================================
void vieCharacterWindow::update()
//
//D Update the displayed information
//
//-----------------------------------------------------------------------------
{
  m_life_widget.update(m_view_model->get_skill_page_manager()->life());
  // this will cause the widgets to refresh their displayed information
  //auto life = m_view_model->get_character_model()->get_life();
  //m_life_widget->update(100);
}
