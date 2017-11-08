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
class SkillWindow : public QDialog
{
    Q_OBJECT

public:
  
  SkillWindow(QWidget *parent = Q_NULLPTR);
  // Constructor

  SkillWindow(const SkillWindow&) = delete;
  // Deleted copy constructor.

  SkillWindow& operator=(const SkillWindow&) = delete;
  // Deleted assignment operator.

  virtual ~SkillWindow();
  // Destructor


private:

  Ui::SkillWindow m_ui;
  // The ui helper class provided by the QT framework
};
