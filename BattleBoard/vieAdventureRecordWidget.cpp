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

#include "modAdventureRecord.h"
//includes from QT
#include <QTWidgets>


//=============================================================================
vieAdventureRecordWidget::vieAdventureRecordWidget(
  modAdventureRecord* model,
  QWidget *parent
)
//
//D
//
//-----------------------------------------------------------------------------
  : QGroupBox(parent),
    m_model(model)
{
    m_ui.setupUi(this);
    m_model->set_view(this);
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
void vieAdventureRecordWidget::set_points(int points)
//
//D Set the number of points displayed
//
//-----------------------------------------------------------------------------
{
  m_ui.pointsBox->setText(QString::number(points));
}

//=============================================================================
void vieAdventureRecordWidget::actionLengthBoxChanged(QString length)
//
//D Update the model with the new type
//
//-----------------------------------------------------------------------------
{
  ADVENTURERECORD::LENGTH ar_length;
  if (length == "Heroquest") {
    ar_length = ADVENTURERECORD::LENGTH::HEROQUEST;
  } else if (length == "Special") {
    ar_length = ADVENTURERECORD::LENGTH::SPECIAL;
  } else if (length == "Adventure Weekend") {
    ar_length = ADVENTURERECORD::LENGTH::ADVENTURE_WEEKEND;
  } else {
    ar_length = ADVENTURERECORD::LENGTH::OTHER;
  }
  m_model->set_length(ar_length);
}

//=============================================================================
void vieAdventureRecordWidget::actionTypeBoxChanged(QString type)
//
//D
//
//-----------------------------------------------------------------------------
{
  ADVENTURERECORD::TYPE ar_type;
  if (type == "Played") {
    ar_type = ADVENTURERECORD::TYPE::PLAYED;
  } else if (type == "Monstered") {
    ar_type = ADVENTURERECORD::TYPE::MONSTERED;
  } else if (type == "Reffed") {
    ar_type = ADVENTURERECORD::TYPE::REFFED;
  } else {
    ar_type = ADVENTURERECORD::TYPE::UNKNOWN;
  }
  m_model->set_type(ar_type);
}

//=============================================================================
void vieAdventureRecordWidget::actionPointsBoxChanged(QString points)
//
//D The user has manually changed the number of points. 
//
//-----------------------------------------------------------------------------
{
  int ar_points = points.toInt();
  m_model->set_points(ar_points);
}
