//=============================================================================
//D The skill selection window
//
// Has a list of skills that can be chosen
//
//-----------------------------------------------------------------------------
#pragma once
// includes from project
#include "vieBBLifeWidget.h"
#include "vieBBPowerWidget.h"
#include "vieBBMagicWidget.h"
#include "vieEquipmentWidget.h"

// QT ui include
#include "ui_vieCharacterWindow.h"

//includes from QT
#include <QDialog>

// system includes

// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs
class modCharacter;

//=============================================================================
class vieCharacterWindow : public QDialog
{
    Q_OBJECT

public:
  
  vieCharacterWindow(
    modCharacter* model,
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

  modCharacter* m_view_model;

  vieBBPowerWidget m_power_widget;

  vieBBMagicWidget m_magic_widget;
  vieBBLifeWidget m_life_widget;
  vieEquipmentWidget m_equipment_widget;

};
