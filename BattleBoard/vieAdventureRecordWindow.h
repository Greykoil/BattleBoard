//=============================================================================
//D The skill selection window
//
// Has a list of skills that can be chosen
//
//-----------------------------------------------------------------------------
#pragma once
// includes from project

// QT ui include
#include "ui_vieAdventureRecordWindow.h"

//includes from QT
#include <QDialog>
#include <QtWidgets>

// system includes
#include <vector>
#include <memory>

// class predeclarations to avoid header file inclusion
// types: classes, enums, typedefs
class vieAdventureRecordWidget;
class vwmAdventureRecordManager;

//=============================================================================
class vieAdventureRecordWindow : public QDialog
{
  Q_OBJECT

public:

  vieAdventureRecordWindow(
    vwmAdventureRecordManager* view_model,
    QWidget *parent = Q_NULLPTR
  );
  // Constructor

  vieAdventureRecordWindow(const vieAdventureRecordWindow&) = delete;
  // Deleted copy constructor.

  vieAdventureRecordWindow& operator=(const vieAdventureRecordWindow&) = delete;
  // Deleted assignment operator.

  virtual ~vieAdventureRecordWindow();
  // Destructor


private slots:

  void actionNewRecordButton();
  // The button has been pressed to add a new record to the end of the list

private:

  vwmAdventureRecordManager* m_view_model;

  std::vector<std::unique_ptr<vieAdventureRecordWidget>> m_adventures;
  // The list of visable adventures

  Ui::AdventureRecordWindow m_ui;
  // The ui helper class provided by the QT framework
};
