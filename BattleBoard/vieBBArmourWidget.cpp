#include "vieBBArmourWidget.h"
#include "modArmourManager.h"

vieBBArmourWidget::vieBBArmourWidget(
  modArmourManager* armour_manager,
  QWidget *parent
)
  : QWidget(parent),
    m_armour_manager(armour_manager)
{
    m_ui.setupUi(this);
}

//=============================================================================
void vieBBArmourWidget::redraw()
//
//-----------------------------------------------------------------------------
{
  m_ui.purePhysical->setText(QString::number(m_armour_manager->pure_physical()));
  m_ui.dexPhysical->setText(QString::number(m_armour_manager->dex_physical()));
  m_ui.purePower->setText(QString::number(m_armour_manager->pure_power()));
  m_ui.dexPower->setText(QString::number(m_armour_manager->dex_power()));
  m_ui.pureMagic->setText(QString::number(m_armour_manager->pure_magic()));
  m_ui.dexMagic->setText(QString::number(m_armour_manager->dex_magic()));
  m_ui.dex->setText(QString::number(m_armour_manager->dex()));
  m_ui.evil->setText(QString::number(m_armour_manager->evil()));
  m_ui.undead->setText(QString::number(m_armour_manager->undead()));
}
