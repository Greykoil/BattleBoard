//=============================================================================
//D The skill selection window
//
// Has a list of skills that can be chosen
//
//-----------------------------------------------------------------------------
#pragma once
// includes from project

// QT ui include
#include "ui_ArmourWindow.h"

//includes from QT
#include <QDialog>

// system includes

// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs

//=============================================================================
class ArmourWindow : public QDialog
{
  Q_OBJECT

public:

  ArmourWindow(QWidget *parent = Q_NULLPTR);
  // Constructor

  ArmourWindow(const ArmourWindow&) = delete;
  // Deleted copy constructor.

  ArmourWindow& operator=(const ArmourWindow&) = delete;
  // Deleted assignment operator.

  virtual ~ArmourWindow();
  // Destructor


private:

  Ui::ArmourWindow m_ui;
  // The ui helper class provided by the QT framework
};