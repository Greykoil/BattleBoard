#include "vieBBMagicWidget.h"
#include "modMagicManager.h"
#include "vieBBSpellSlotWidget.h"

vieBBMagicWidget::vieBBMagicWidget(
  modMagicManager* magic_manager, 
  QWidget *parent
)
  : QWidget(parent),
    m_magic_manager(magic_manager)
{
    m_ui.setupUi(this);

    for (int i = 1; i <= 5; ++i) {
      auto widget = new vieBBSpellSlotWidget(magic_manager->spell_level(i));
      m_ui.verticalLayout->addWidget(widget);
      m_slots.push_back(widget);
    }
}

//=============================================================================
void vieBBMagicWidget::update()
//
//-----------------------------------------------------------------------------
{
  for (vieBBSpellSlotWidget* slot : m_slots) {
    slot->redraw();
  }
}
