//=============================================================================
//D The skill selection window
//
// Has a list of skills that can be chosen
//
//-----------------------------------------------------------------------------
#pragma once
// includes from project

// QT ui include
#include "ui_AdventureRecordWindow.h"

//includes from QT
#include <QDialog>

// system includes
#include <vector>
#include <memory>

// class predeclarations to avoid header file inclusion
// types: classes, enums, typedefs
class AdventureRecordWidget;

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


private slots:

  void actionNewRecordButton();
  // The button has been pressed to add a new record to the end of the list

  QGroupBox* create_new_record();
  // Create a new record

private:

  std::vector<std::unique_ptr<AdventureRecordWidget>> m_adventures;


  QVBoxLayout* m_vert_layout;

  Ui::AdventureRecordWindow m_ui;
  // The ui helper class provided by the QT framework
};
