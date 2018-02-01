#include "vieBBPowerWidget.h"
#include "vieBBLineWidget.h"
#include "modPowerManager.h"

vieBBPowerWidget::vieBBPowerWidget(
  modPowerManager* power_manager, 
  QWidget *parent
)
: QWidget(parent),
  m_power_manager(power_manager)
{
    m_ui.setupUi(this);
    for (int i = 0; i < 10; ++i) {
      m_ui.verticalLayout_2->addWidget(new vieBBLineWidget);
    }
}

//=============================================================================
void vieBBPowerWidget::redraw()
//
//-----------------------------------------------------------------------------
{
  m_ui.powerLabel->setText(QString::number(m_power_manager->total_power()));
}
