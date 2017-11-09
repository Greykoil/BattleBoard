//=============================================================================
//D The skill selection window
//
// Has a list of skills that can be chosen
//
//-----------------------------------------------------------------------------
#pragma once
// includes from project

// QT ui include
#include "ui_SkillWidget.h"

//includes from QT
#include <QWidget>

// system includes

// class predeclarations to avoid header file inclusion
// types: classes, enums, typedefs

//=============================================================================
class SkillWidget : public QWidget
{
  Q_OBJECT

public:

  SkillWidget(
    QString name,
    int cost_per_rank,
    int max_picks,
    bool status_skill,
    int num_bought = 0,
    QWidget *parent = Q_NULLPTR
  );
  // Constructor

  SkillWidget(const SkillWidget&) = delete;
  // Deleted copy constructor.

  SkillWidget& operator=(const SkillWidget&) = delete;
  // Deleted assignment operator.

  virtual ~SkillWidget();
  // Destructor

private slots:

  void actionNumberPicksBoxChanged(QString new_text);
  // The number of picks selected has been changed

private:
  
  Ui::SkillWidget m_ui;

  int m_cost_per_rank;

};
