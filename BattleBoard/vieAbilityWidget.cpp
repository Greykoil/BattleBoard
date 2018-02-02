#include "vieAbilityWidget.h"
#include "modAbility.h"
#include <assert.h>

vieAbilityWidget::vieAbilityWidget(modAbility* model, QWidget *parent)
  : QWidget(parent),
    m_model(model)
{
  m_ui.setupUi(this);
}

void vieAbilityWidget::onActionNameChanged(QString name)
{
  m_model->set_name(name.toStdString());
}

void vieAbilityWidget::onActionFrequency(QString type)
{
  ABILITY_FREQUENCY frequency;
  if (type.toStdString() == "Sectional") {
    m_model->set_frequency(ABILITY_FREQUENCY::PER_SECTIONAL);
  }
  else if (type.toStdString() == "Daily") {
    m_model->set_frequency(ABILITY_FREQUENCY::PER_DAY);
  }
  else if (type.toStdString() == "Per Event") {
    m_model->set_frequency(ABILITY_FREQUENCY::PER_EVENT);
  }
  else if (type.toStdString() == "Once Ever") {
    m_model->set_frequency(ABILITY_FREQUENCY::ONCE_EVER);
  }
  else {
    // Something has gone wrong
    assert(1 == 0);
  }
}

void vieAbilityWidget::onActionChargesChanged(int charges)
{
  m_model->set_uses(charges);
}
