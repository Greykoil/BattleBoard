#include "vieBBAbilityWidget.h"
#include "modAbilityManager.h"
#include "vieBBAbilityDisplayWidget.h"

vieBBAbilityWidget::vieBBAbilityWidget(
  modAbilityManager* model, 
  QWidget *parent
)
: QWidget(parent),
  m_model(model)
{
  m_ui.setupUi(this);
}

//=============================================================================
void vieBBAbilityWidget::redraw()
//
//-----------------------------------------------------------------------------
{
  // Lets just update everything 
  // This will be wrong if we ever add anything else or if we want to delete abilities.
  for (int i = 1; i < m_ui.sectionalAbilityLayout->count(); ++i) {
    auto current = m_ui.sectionalAbilityLayout->itemAt(i)->widget();
    vieBBAbilityDisplayWidget* widget = dynamic_cast<vieBBAbilityDisplayWidget*>(current);
    if (widget) {
      widget->redraw();
    }
  }
  for (int i = m_ui.sectionalAbilityLayout->count() - 1; i < m_model->num_abilities(); ++i) {
    m_ui.sectionalAbilityLayout->addWidget(new vieBBAbilityDisplayWidget(m_model->ability(i)));
  }
}
