#include "vieBBSpellSlotWidget.h"
#include "modSkill.h"
#include <assert.h>

vieBBSpellSlotWidget::vieBBSpellSlotWidget(
  modSkill* spell_slot,
  QWidget *parent
)
: QWidget(parent),
  m_spell_slot(spell_slot)
{
  assert(m_spell_slot);
  m_ui.setupUi(this);
  redraw();
}

//=============================================================================
void vieBBSpellSlotWidget::redraw()
//
//-----------------------------------------------------------------------------
{
  m_ui.levelLabel->setText(QString::fromStdString(m_spell_slot->name()));
  m_ui.slotLabel->setText(QString::number(m_spell_slot->num_picks()));
  m_ui.slotsOutLabel->setText(QString::number(0));
//  ui.levelLbel
}
