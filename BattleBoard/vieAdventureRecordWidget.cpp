//=============================================================================
//D The apps main window
//
// Contains a tab list of the windows where things actually happen
//
//-----------------------------------------------------------------------------

// Class header include
#include "vieAdventureRecordWindow.h"
// includes from project
#include "vieAdventureRecordWidget.h"

//includes from QT
#include <QTWidgets>


//=============================================================================
vieAdventureRecordWidget::vieAdventureRecordWidget(QWidget *parent)
//
//D
//
//-----------------------------------------------------------------------------
  : QGroupBox(parent)
{
    m_ui.setupUi(this);
}

//=============================================================================
vieAdventureRecordWidget::~vieAdventureRecordWidget()
//
//D
//
//-----------------------------------------------------------------------------
{
}

//=============================================================================
void vieAdventureRecordWidget::update_points()
//
//D
//
//-----------------------------------------------------------------------------
{
  QString length_text = m_ui.lengthBox->currentText();
  QString type_text = m_ui.typeBox->currentText();

  if (length_text == "Other" || type_text == "Other") {
    return;
  }
  int base;
  int multiplier = 2;
  if (type_text == "Monstered") {
    multiplier = 1;
  }

  if (length_text == "Heroquest") {
    base = 50;
  } else if (length_text == "Special") {
    base = 35;
  } else if (length_text == "Adventure Weekend") {
    base = 25;
  }
  int points = base * multiplier;
  m_ui.pointsBox->setText(QString::number(points));
}

//=============================================================================
void vieAdventureRecordWidget::actionLengthBoxChanged(QString length)
//
//D
//
//-----------------------------------------------------------------------------
{
  update_points();
}

//=============================================================================
void vieAdventureRecordWidget::actionTypeBoxChanged(QString type)
//
//D
//
//-----------------------------------------------------------------------------
{
  update_points();
}
