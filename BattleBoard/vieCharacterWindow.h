//=============================================================================
//D The skill selection window
//
// Has a list of skills that can be chosen
//
//-----------------------------------------------------------------------------
#pragma once
// includes from project

// QT ui include
#include "ui_vieCharacterWindow.h"

//includes from QT
#include <QDialog>

// system includes

// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs
class vwmCharacter;

//=============================================================================
class vieCharacterWindow : public QDialog
{
    Q_OBJECT

public:
  
  vieCharacterWindow(
    vwmCharacter* view_model,
    QWidget *parent = Q_NULLPTR
  );
  // Constructor

  void update(); 
  // Update the displayed information

  vieCharacterWindow(const vieCharacterWindow&) = delete;
  // Deleted copy constructor.

  vieCharacterWindow& operator=(const vieCharacterWindow&) = delete;
  // Deleted assignment operator.

  virtual ~vieCharacterWindow() = default;
  // Destructor



private:
    Ui::vieCharacter m_ui;

    vwmCharacter* m_view_model;
};