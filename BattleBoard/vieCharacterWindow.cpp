//=============================================================================
//D The character window
//
//-----------------------------------------------------------------------------

// Class header include
#include "vieCharacterWindow.h"
// includes from project
#include "modCharacter.h"
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
    m_view_model(model),
    m_magic_widget(model->get_magic_manager()),
    m_power_widget(model->get_power_manager()),
    m_armour_widget(model->get_armour_manager())
{
//  m_view_model->set_character_window(this);
  m_ui.setupUi(this);
  assert(m_view_model != nullptr);

  m_ui.gridLayout->addWidget(&m_armour_widget, 0, 0, 1, 1);
  m_ui.gridLayout->addWidget(&m_life_widget, 1, 0, 5, 1);
  m_ui.gridLayout->addWidget(&m_magic_widget, 6, 0, 4, 1);
  m_ui.gridLayout->addWidget(&m_power_widget, 0, 1, 5, 1);
  m_ui.gridLayout->addWidget(&m_equipment_widget, 6, 1, 5, 1);

  m_ui.gridLayout->setColumnStretch(0, 1);
  m_ui.gridLayout->setColumnStretch(1, 1);
  for (int i = 0; i < 10; ++i) {
    m_ui.gridLayout->setRowStretch(i, 1);
  }

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
  m_magic_widget.update();
  m_power_widget.redraw();
  m_armour_widget.redraw();
}
