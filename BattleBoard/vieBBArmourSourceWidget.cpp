#include "vieBBArmourSourceWidget.h"
#include "modArmourSource.h"
#include "vieBBArmourWidget.h"

vieBBArmourSourceWidget::vieBBArmourSourceWidget(
  modArmourSource* model,
  vieBBArmourWidget* armour_widget,
  QWidget *parent
)
: QWidget(parent),
  m_model(model)
{
    m_ui.setupUi(this);


    // Ensure that the attached display box is redrawn when any values change
    QObject::connect(m_ui.spinBox, SIGNAL(valueChanged(int)), armour_widget, SLOT(redraw()));
    QObject::connect(m_ui.spinBox_2, SIGNAL(valueChanged(int)), armour_widget, SLOT(redraw()));
    QObject::connect(m_ui.spinBox_3, SIGNAL(valueChanged(int)), armour_widget, SLOT(redraw()));
    QObject::connect(m_ui.spinBox_4, SIGNAL(valueChanged(int)), armour_widget, SLOT(redraw()));
    QObject::connect(m_ui.spinBox_5, SIGNAL(valueChanged(int)), armour_widget, SLOT(redraw()));
    QObject::connect(m_ui.spinBox_6, SIGNAL(valueChanged(int)), armour_widget, SLOT(redraw()));
}



void vieBBArmourSourceWidget::actionNameBoxChanged(QString name)
{
  m_model->set_name(name.toStdString());
}

//=============================================================================
void vieBBArmourSourceWidget::actionPhysicalBoxChanged(int value)
//
//-----------------------------------------------------------------------------
{
  m_model->set_physical(value);
}

void vieBBArmourSourceWidget::actionPowerBoxChanged(int value)
{
  m_model->set_power(value);
}

void vieBBArmourSourceWidget::actionMagicBoxChanged(int value)
{
  m_model->set_magic(value);
}

void vieBBArmourSourceWidget::actionEvilBoxChanged(int value)
{
  m_model->set_evil(value);
}

void vieBBArmourSourceWidget::actionUndeadBoxChanged(int value)
{
  m_model->set_undead(value);
}

void vieBBArmourSourceWidget::actionDexterityBoxChanged(int value)
{
  m_model->set_dex(value);
}
