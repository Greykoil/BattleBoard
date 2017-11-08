//=============================================================================
//D The skill selection window
//
// Has a list of skills that can be chosen
//
//-----------------------------------------------------------------------------
#pragma once
// includes from project

// QT ui include
#include "ui_AdventureRecordWidget.h"

//includes from QT
#include <QGroupBox>

// system includes

// class predeclarations to avoid header file inclusion
// types: classes, enums, typedefs

//=============================================================================
class AdventureRecordWidget : public QGroupBox
{
  Q_OBJECT

public:

  AdventureRecordWidget(QWidget *parent = Q_NULLPTR);
  // Constructor

  AdventureRecordWidget(const AdventureRecordWidget&) = delete;
  // Deleted copy constructor.

  AdventureRecordWidget& operator=(const AdventureRecordWidget&) = delete;
  // Deleted assignment operator.

  virtual ~AdventureRecordWidget();
  // Destructor


protected:
  
  void update_points();
  // Check if we can fill in points automatically and if so then do it

private slots:

  void actionLengthBoxChanged(QString length);
  void actionTypeBoxChanged(QString type);

private:
    Ui::AdventureRecordWidget m_ui;
};
