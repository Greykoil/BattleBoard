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
  m_ui.label->setText(QString::fromStdString(m_model->get_name()));
  // Add a radio button for each charge
  // This will not reduce the number of charges which could be a second check.
  for (int i = 0; i < m_model->get_uses(); ++i) {
    m_ui.horizontalLayout->addWidget(new QRadioButton());
  }

  // If we have a sectional ability we want to display boxes for each section.
  if (m_model->get_frequency() == PER_SECTIONAL) {
    for (int i = 0; i < 2; ++i) {
      QFrame* line = new QFrame();
      line->setObjectName(QStringLiteral("line"));
      line->setFrameShape(QFrame::VLine);
      line->setFrameShadow(QFrame::Sunken);
      m_ui.horizontalLayout->addWidget(line);
      for (int i = 0; i < m_model->get_uses(); ++i) {
        m_ui.horizontalLayout->addWidget(new QRadioButton());
      }
    }
  }
}