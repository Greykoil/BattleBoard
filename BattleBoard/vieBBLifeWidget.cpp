// This should be set up to have only three things that stretch across multiple grid squares

#include "vieBBLifeWidget.h"
#include "vieBBLineWidget.h"

vieBBLifeWidget::vieBBLifeWidget(QWidget *parent)
    : QWidget(parent)
{
    m_ui.setupUi(this);

    for (int i = 0; i < 10; ++i) {
      m_ui.verticalLayout_2->addWidget(new vieBBLineWidget);
      m_ui.verticalLayout_6->addWidget(new vieBBLineWidget);
      m_ui.verticalLayout_6->addWidget(new vieBBLineWidget);
    }
}

//=============================================================================
void vieBBLifeWidget::update(int life)
//
//D
//
//-----------------------------------------------------------------------------
{
  m_ui.label->setText(QString::number(life));
}


//=============================================================================
vieBBLifeWidget::~vieBBLifeWidget()
//
//-----------------------------------------------------------------------------
{
}
