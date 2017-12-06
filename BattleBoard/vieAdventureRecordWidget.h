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

  virtual ~vieAdventureRecordWidget();
  // Destructor

protected:

private slots:

  void actionLengthBoxChanged(QString length);
  void actionTypeBoxChanged(QString type);
  void actionPointsBoxChanged(QString points);


private:
    Ui::AdventureRecordWidget m_ui;

    modAdventureRecord* m_model;
};
