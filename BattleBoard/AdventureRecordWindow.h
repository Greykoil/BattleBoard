//=============================================================================
//D The skill selection window
//
// Has a list of skills that can be chosen
//
//-----------------------------------------------------------------------------
#pragma once
// includes from project

// QT ui include
#include "ui_SkillWindow.h"

//includes from QT
#include <QDialog>

// system includes

// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs

//=============================================================================
class AdventureRecordWindow : public QDialog
{
  Q_OBJECT

public:

  AdventureRecordWindow(QWidget *parent = Q_NULLPTR);
  // Constructor

  AdventureRecordWindow(const AdventureRecordWindow&) = delete;
  // Deleted copy constructor.

  AdventureRecordWindow& operator=(const AdventureRecordWindow&) = delete;
  // Deleted assignment operator.

  virtual ~AdventureRecordWindow();
  // Destructor


private:

  Ui::SkillWindow m_ui;
  // The ui helper class provided by the QT framework
};
