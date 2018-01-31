#include "vieBBPowerWidget.h"
#include "vieBBLineWidget.h"

vieBBPowerWidget::vieBBPowerWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    for (int i = 0; i < 10; ++i) {
      ui.verticalLayout_2->addWidget(new vieBBLineWidget);
    }
}

vieBBPowerWidget::~vieBBPowerWidget()
{
}
