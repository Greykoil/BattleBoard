#include "vieBBAbilityWidget.h"
#include "modAbilityManager.h"
#include "vieBBAbilityDisplayWidget.h"

//=============================================================================
vieBBAbilityWidget::vieBBAbilityWidget(
  modAbilityManager* model,
  QWidget *parent
)
//
//-----------------------------------------------------------------------------
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
  while (m_ui.sectionalAbilityLayout->count() > 1) {
    auto current = m_ui.sectionalAbilityLayout->itemAt(1)->widget();
    vieBBAbilityDisplayWidget* widget = dynamic_cast<vieBBAbilityDisplayWidget*>(current);
    if (widget) {
      m_ui.sectionalAbilityLayout->removeWidget(widget);
      delete widget;
    }
  }
  while (m_ui.dailyAbilityLayout->count() > 1) {
    auto current = m_ui.dailyAbilityLayout->itemAt(1)->widget();
    vieBBAbilityDisplayWidget* widget = dynamic_cast<vieBBAbilityDisplayWidget*>(current);
    if (widget) {
      m_ui.dailyAbilityLayout->removeWidget(widget);
      delete widget;
    }
  }
  while (m_ui.perEventAbilityLayout->count() > 1) {
    auto current = m_ui.perEventAbilityLayout->itemAt(1)->widget();
    vieBBAbilityDisplayWidget* widget = dynamic_cast<vieBBAbilityDisplayWidget*>(current);
    if (widget) {
      m_ui.perEventAbilityLayout->removeWidget(widget);
      delete widget;
    }
  }
  while (m_ui.onceEverAbilityLayout->count() > 1) {
    auto current = m_ui.onceEverAbilityLayout->itemAt(1)->widget();
    vieBBAbilityDisplayWidget* widget = dynamic_cast<vieBBAbilityDisplayWidget*>(current);
    if (widget) {
      m_ui.onceEverAbilityLayout->removeWidget(widget);
      delete widget;
    }
  }

  // Abilities are laid out to get 10 charges to a line. This might get a bit cramped.
  for (int i = 0; i < m_model->num_abilities(); ++i) {
    modAbility* ability = m_model->ability(i);
    ABILITY_FREQUENCY frequency = ability->get_frequency();

    switch (frequency)
    {
    case PER_SECTIONAL:
      m_ui.sectionalAbilityLayout->addWidget(new vieBBAbilityDisplayWidget(ability));
      break;
    case PER_DAY:
      m_ui.dailyAbilityLayout->addWidget(new vieBBAbilityDisplayWidget(ability));
      break;
    case PER_EVENT:
      m_ui.perEventAbilityLayout->addWidget(new vieBBAbilityDisplayWidget(ability));
      break;
    case ONCE_EVER:
      m_ui.onceEverAbilityLayout->addWidget(new vieBBAbilityDisplayWidget(ability));
      break;
    default:
      break;
    }
  }

  if (m_ui.sectionalAbilityLayout->count() == 1) {
    m_ui.groupBox->setVisible(false);
  } 
  else {
    m_ui.groupBox->setVisible(true);
  }

  if (m_ui.dailyAbilityLayout->count() == 1) {
    m_ui.groupBox_2->setVisible(false);
  }
  else {
    m_ui.groupBox_2->setVisible(true);
  }
  if (m_ui.perEventAbilityLayout->count() == 1) {
    m_ui.groupBox_3->setVisible(false);
  }
  else {
    m_ui.groupBox_3->setVisible(true);
  }
  if (m_ui.onceEverAbilityLayout->count() == 1) {
    m_ui.groupBox_4->setVisible(false);
  }
  else {
    m_ui.groupBox_4->setVisible(true);
  }
}
