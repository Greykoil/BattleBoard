#include "vieArmourWindow.h"
#include "modArmourManager.h"
#include "vieBBArmourSourceWidget.h"
#include "vieBBArmourWidget.h"
#include "modArmourSource.h"
#include <assert.h>

vieArmourWindow::vieArmourWindow(
  modArmourManager* model,
  QWidget *parent
)
: QDialog(parent),
  m_model(model)
{
  assert(model);
  m_ui.setupUi(this);
  m_armour_display = new vieBBArmourWidget(model);
  m_ui.verticalLayout->insertWidget(0, m_armour_display);
  m_worn_armour = m_model->add_armour_source();

}

void vieArmourWindow::actionOnAddNewPermenantSource()
{
  modArmourSource* model_source = m_model->add_armour_source();
  m_ui.verticalLayout_2->addWidget(new vieBBArmourSourceWidget(model_source, m_armour_display));
}


void vieArmourWindow::actionOnAddNewLongDurationSource()
{
  modArmourSource* model_source = m_model->add_armour_source();
  m_ui.verticalLayout_3->addWidget(new vieBBArmourSourceWidget(model_source, m_armour_display));
}

//=============================================================================
void vieArmourWindow::actionOnWornArmourChanged()
//
//D Recalulate the worn armour class
//
//-----------------------------------------------------------------------------
{
  int base = 0;
  if (m_ui.armourType->currentText() == "Non-Metal") {
    base = 6;
  } else if (m_ui.armourType->currentText() == "Metal") {
    base = 10;
  }
  m_worn_armour->set_physical(base + m_ui.superiorCount->value());
  m_worn_armour->set_magic(m_ui.ensourcelledCount->value());
  m_worn_armour->set_power(m_ui.empoweredCount->value());
  m_armour_display->redraw();
}
