//=============================================================================
//D The apps main window
//
// Contains a tab list of the windows where things actually happen
//
//-----------------------------------------------------------------------------
#pragma once
// includes from project
// QT ui include
#include "ui_vieMainWindow.h"

//includes from QT
#include <QtWidgets/QMainWindow>
#include <QDialog>
// system includes
#include <vector>
#include <memory>

// class predeclarations to avoid header file inclusion
class vieCharacterWindow;
class modCharacter;
// types: classes, enums, typedefs

//=============================================================================
class vieMainWindow : public QMainWindow
{
  Q_OBJECT

public:
  vieMainWindow(
    modCharacter* character_model,
    QWidget *parent = Q_NULLPTR
  );
  // Constructor

  vieMainWindow(const vieMainWindow&) = delete;
  // Deleted copy constructor.

  vieMainWindow& operator=(const vieMainWindow&) = delete;
  // Deleted assignment operator.

  virtual ~vieMainWindow() = default;
  // Destructor


protected:
  
  void add_tabs();
  // Add the list of tabs that the main window is using

private slots:
  // The list of event actions that can happen  

  // Actions from the file menu drop down
  void actionOpen();
  void actionNew();
  void actionSave();
  void actionTabChanged(int index);

private:

  modCharacter* m_model;

  std::vector<std::unique_ptr<QDialog>> m_tab_list;
  // The vector of tabs that this window is going to show

  Ui::MainWindowClass m_ui;
  // The ui helper class provided by the QT framework
};
