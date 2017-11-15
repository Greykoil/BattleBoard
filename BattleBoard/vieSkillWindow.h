//=============================================================================
//D The skill selection window
//
// Has a list of skills that can be chosen
//
//-----------------------------------------------------------------------------
#pragma once
// includes from project
#include "vwmSkillPage.h"
// QT ui include
#include "ui_vieSkillWindow.h"

//includes from QT
#include <QDialog>

// system includes
#include <memory>
#include <vector>

// class predeclarations to avoid header file inclusion

// types: classes, enums, typedefs
class vwmSkillPage;

//=============================================================================
class vieSkillWindow : public QDialog
{
    Q_OBJECT

public:
  
  vieSkillWindow(
    vwmSkillPage* manager,
    QWidget *parent = Q_NULLPTR
  );
  // Constructor

  void redraw();
  // Redraw the list of available skills

  vieSkillWindow(const vieSkillWindow&) = delete;
  // Deleted copy constructor.

  vieSkillWindow& operator=(const vieSkillWindow&) = delete;
  // Deleted assignment operator.

  virtual ~vieSkillWindow() = default;
  // Destructor


private:

  vwmSkillPage* m_vm_manager;
  // The view model for the skill window

  std::vector<std::unique_ptr<vieSkillWidget>> m_full_skill_list;
  // All the available skills

  Ui::SkillWindow m_ui;
  // The ui helper class provided by the QT framework

  std::vector<std::pair<vieSkillWidget*, QListWidgetItem*>> m_all_skills;
  // All the skills with their containing place in the list
};
