//=============================================================================
//D The skill selection window
//
// Has a list of skills that can be chosen
//
//-----------------------------------------------------------------------------
#pragma once
// includes from project

// QT ui include
#include "ui_vieArmourWindow.h"

//includes from QT
#include <QDialog>

// system includes

// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs

//=============================================================================
class vieArmourWindow : public QDialog
{
  Q_OBJECT

public:

  vieArmourWindow(QWidget *parent = Q_NULLPTR);
  // Constructor

  vieArmourWindow(const vieArmourWindow&) = delete;
  // Deleted copy constructor.

  vieArmourWindow& operator=(const vieArmourWindow&) = delete;
  // Deleted assignment operator.

  virtual ~vieArmourWindow();
  // Destructor


private:

  Ui::ArmourWindow m_ui;
  // The ui helper class provided by the QT framework
};