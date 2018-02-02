#include "vieBBAbilityDisplayWidget.h"
#include "modAbility.h"
#include <QtWidgets/QRadioButton>
vieBBAbilityDisplayWidget::vieBBAbilityDisplayWidget(
  modAbility* model,
  QWidget *parent
)
  : QWidget(parent),
    m_model(model)
{
  m_ui.setupUi(this);
  redraw();
}

//=============================================================================
void vieBBAbilityDisplayWidget::redraw()
//
//-----------------------------------------------------------------------------
{
  m_ui.label->setText(QString::fromStdString(m_model->get_name()));
  // Add a radio button for each charge
  // This will not reduce the number of charges which could be a second check.
  for (int i = m_ui.horizontalLayout->count() - 1; i < m_model->get_uses(); ++i) {
    m_ui.horizontalLayout->addWidget(new QRadioButton());
  }
}
