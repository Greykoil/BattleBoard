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
//-----------------------------------------------------------------------------
  : QGroupBox(parent),
    m_model(model)
{
    m_ui.setupUi(this);
    m_model->set_view(this);
    
    // Setup based on the model
    m_ui.lengthBox->setCurrentIndex(model->get_length());
    m_ui.typeBox->setCurrentIndex(model->get_type());
    m_ui.pointsBox->setText(QString::number(model->get_points()));
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
//D Update the model with the new length
//
//-----------------------------------------------------------------------------
{
  ADVENTURE_RECORD_LENGTH ar_length;
  if (length == "Heroquest") {
    ar_length = ADVENTURE_RECORD_LENGTH::HEROQUEST;
  } else if (length == "Special") {
    ar_length = ADVENTURE_RECORD_LENGTH::SPECIAL;
  } else if (length == "Adventure Weekend") {
    ar_length = ADVENTURE_RECORD_LENGTH::ADVENTURE_WEEKEND;
  } else {
    ar_length = ADVENTURE_RECORD_LENGTH::OTHER_LENGTH;
  }
  m_model->set_length(ar_length);
}

//=============================================================================
void vieAdventureRecordWidget::actionTypeBoxChanged(QString type)
//
//D Update the model with the new type
//
//-----------------------------------------------------------------------------
{
  ADVENTURE_RECORD_TYPE ar_type;
  if (type == "Played") {
    ar_type = ADVENTURE_RECORD_TYPE::PLAYED;
  } else if (type == "Monstered") {
    ar_type = ADVENTURE_RECORD_TYPE::MONSTERED;
  } else if (type == "Reffed") {
    ar_type = ADVENTURE_RECORD_TYPE::REFFED;
  } else {
    ar_type = ADVENTURE_RECORD_TYPE::OTHER_TYPE;
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
