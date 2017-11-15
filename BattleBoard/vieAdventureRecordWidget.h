//=============================================================================
//D The skill selection window
//
// Has a list of skills that can be chosen
//
//-----------------------------------------------------------------------------
#pragma once
// includes from project

// QT ui include
#include "ui_vieAdventureRecordWidget.h"

//includes from QT
#include <QGroupBox>

// system includes

// class predeclarations to avoid header file inclusion
// types: classes, enums, typedefs

//=============================================================================
class vieAdventureRecordWidget : public QGroupBox
{
  Q_OBJECT

public:

  vieAdventureRecordWidget(QWidget *parent = Q_NULLPTR);
  // Constructor

  vieAdventureRecordWidget(const vieAdventureRecordWidget&) = delete;
  // Deleted copy constructor.

  vieAdventureRecordWidget& operator=(const vieAdventureRecordWidget&) = delete;
  // Deleted assignment operator.

  virtual ~vieAdventureRecordWidget();
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
