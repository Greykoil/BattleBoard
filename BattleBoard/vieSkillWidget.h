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
class vwmSkill;

//=============================================================================
class vieSkillWidget : public QWidget
{
  Q_OBJECT

public:

  vieSkillWidget(
    vwmSkill* view_model,
    QString name,
    int cost_per_rank,
    int max_picks,
    bool status_skill,
    int num_bought = 0,
    QWidget *parent = Q_NULLPTR
  );
  // Constructor

  void set_total_cost(int total_cost);
  // Set the displayed total cost text

  vieSkillWidget(const vieSkillWidget&) = delete;
  // Deleted copy constructor.

  vieSkillWidget& operator=(const vieSkillWidget&) = delete;
  // Deleted assignment operator.

  virtual ~vieSkillWidget();
  // Destructor

private slots:

  void actionNumberPicksBoxChanged(QString new_text);
  // The number of picks selected has been changed

private:
  
  Ui::SkillWidget m_ui;

  vwmSkill* m_view_model;

};
