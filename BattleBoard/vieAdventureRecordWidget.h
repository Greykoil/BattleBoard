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
class modAdventureRecord;
// types: classes, enums, typedefs

//=============================================================================
class vieAdventureRecordWidget : public QGroupBox
{
  Q_OBJECT

public:

  vieAdventureRecordWidget(
    modAdventureRecord* view_model,
    QWidget *parent = Q_NULLPTR
  );
  // Constructor

  void set_points(int points);
  // Set the number of points that the user sees

  vieAdventureRecordWidget(const vieAdventureRecordWidget&) = delete;
  // Deleted copy constructor.

  vieAdventureRecordWidget& operator=(const vieAdventureRecordWidget&) = delete;
  // Deleted assignment operator.

  virtual ~vieAdventureRecordWidget() = default;
  // Destructor

protected:

private slots:

  void actionLengthBoxChanged(QString length);
  // Called when the user changes the Length Drop down

  void actionTypeBoxChanged(QString type);
  // Called when the user changes the type drop down

  void actionPointsBoxChanged(QString points);
  // Called when the user changes the points box

private:
    Ui::AdventureRecordWidget m_ui;

    modAdventureRecord* m_model;
};
