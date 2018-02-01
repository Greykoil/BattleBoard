//=============================================================================
//D The skill selection window
//
// Has a list of skills that can be chosen
//
//-----------------------------------------------------------------------------
#pragma once
// includes from project

// QT ui include
#include "ui_vieSkillWidget.h"

//includes from QT
#include <QWidget>

// system includes

// class predeclarations to avoid header file inclusion
// types: classes, enums, typedefs
class modSkill;
class vieSkillWindow;

//=============================================================================
class vieSkillWidget : public QWidget
{
  Q_OBJECT

public:

  vieSkillWidget(
    modSkill* model,
    vieSkillWindow* parent_win,
    QWidget *parent = Q_NULLPTR
  );
  // Constructor

  void set_total_cost(int total_cost);
  // Set the displayed total cost text

  bool is_visable();
  // Is the skill visable as a pickable skill 

  void update_after_load();
  // Update the deatils after a file has been loaded

  vieSkillWidget(const vieSkillWidget&) = delete;
  // Deleted copy constructor.

  vieSkillWidget& operator=(const vieSkillWidget&) = delete;
  // Deleted assignment operator.

  virtual ~vieSkillWidget() = default;
  // Destructor

private slots:

  void actionNumberPicksBoxChanged(QString new_text);
  // The number of picks selected has been changed

private:
  
  Ui::SkillWidget m_ui;

  modSkill* m_model;

  vieSkillWindow* m_parent_win;
};
