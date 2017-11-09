//=============================================================================
//D The skill selection window
//
// Has a list of skills that can be chosen
//
//-----------------------------------------------------------------------------
#pragma once
// includes from project
#include "SkillVMManager.h"
// QT ui include
#include "ui_SkillWindow.h"

//includes from QT
#include <QDialog>

// system includes
#include <memory>
#include <vector>

// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs
class SkillPageVMManager;

//=============================================================================
class SkillWindow : public QDialog
{
    Q_OBJECT

public:
  
  SkillWindow(
    SkillPageVMManager* manager,
    QWidget *parent = Q_NULLPTR
  );
  // Constructor

  SkillWindow(const SkillWindow&) = delete;
  // Deleted copy constructor.

  SkillWindow& operator=(const SkillWindow&) = delete;
  // Deleted assignment operator.

  virtual ~SkillWindow();
  // Destructor


private:

  SkillPageVMManager* m_vm_manager;
  // The view model for the skill window

  std::vector<std::unique_ptr<SkillWidget>> m_visable_skills;

  Ui::SkillWindow m_ui;
  // The ui helper class provided by the QT framework
};
