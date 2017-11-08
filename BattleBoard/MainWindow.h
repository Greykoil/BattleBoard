//=============================================================================
//D The apps main window
//
// Contains a tab list of the windows where things actually happen
//
//-----------------------------------------------------------------------------
#pragma once
// includes from project

// QT ui include
#include "ui_MainWindow.h"

//includes from QT
#include <QtWidgets/QMainWindow>

// system includes
#include <vector>
#include <memory>

// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs

//=============================================================================
class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = Q_NULLPTR);
  // Constructor

  MainWindow(const MainWindow&) = delete;
  // Deleted copy constructor.

  MainWindow& operator=(const MainWindow&) = delete;
  // Deleted assignment operator.

  virtual ~MainWindow();
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

private:

  std::vector<std::unique_ptr<QDialog>> m_tab_list;
  // The vector of tabs that this window is going to show

  Ui::MainWindowClass m_ui;
  // The ui helper class provided by the QT framework
};
