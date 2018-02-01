//=============================================================================
//D Class for the skill as it is displayed in the skills tab
//
//-----------------------------------------------------------------------------

// Class header include
#include "vieSkillWidget.h"
// includes from project
#include "modSkill.h"
#include "vieSkillWindow.h"
//includes from QT
#include <qmessagebox.h>

//System includes
#include <assert.h>
#include <algorithm>

//=============================================================================
vieSkillWidget::vieSkillWidget(
  modSkill* model,
  vieSkillWindow* parent_win,
  QWidget *parent
)
//
//-----------------------------------------------------------------------------
  : QWidget(parent),
    m_model(model),
    m_parent_win(parent_win)
{
  assert(model != nullptr);
  m_ui.setupUi(this);
  m_ui.costLabel->setText(QString::number(m_model->cost_per_rank()));
  m_ui.maxPicksLabel->setText(QString::number(m_model->max_picks()));
  m_ui.nameLabel->setText(QString::fromStdString(m_model->name()));
  m_ui.statusSkillCheck->setAttribute(Qt::WA_TransparentForMouseEvents);
  m_ui.statusSkillCheck->setFocusPolicy(Qt::NoFocus);
}


//=============================================================================
void vieSkillWidget::actionNumberPicksBoxChanged(QString new_text)
//
//D Called when the user changes the number of  picks for the skill
//
//-----------------------------------------------------------------------------
{
  int num_picks = m_ui.numberBoughtEdit->text().toInt();

  // toInt handles most edge cases but allows negative numbers which we 
  // don't want. 
  num_picks = std::max(0, num_picks);

  bool changed = m_model->set_picks(num_picks);
  // This needs to come back in when dependency is fixed
  //if (!changed) {
  //  QMessageBox box;
  //  box.setText("Removing breaks dependency");
  //  box.exec();
  //}

  m_ui.numberBoughtEdit->setText(QString::number(m_model->num_picks()));
  m_parent_win->redraw();
}

//=============================================================================
void vieSkillWidget::set_total_cost(int total_cost)
//
//D Set the total cost for the number of ranks of the skill
//
//-----------------------------------------------------------------------------
{
  m_ui.totalCostLabel->setText(QString::number(total_cost));
}

//=============================================================================
bool vieSkillWidget::is_visable()
//
//D Should the skill be displayed as a pickable skill
//
//-----------------------------------------------------------------------------
{
  return m_model->is_pickable();
}

//=============================================================================
void vieSkillWidget::update_after_load()
//
//D Update the displayed details after a skill has been loaded
//
//-----------------------------------------------------------------------------
{
  m_ui.numberBoughtEdit->setText(QString::number(m_model->num_picks()));
  m_ui.totalCostLabel->setText(QString::number(m_model->total_cost()));
  m_ui.costLabel->setText(QString::number(m_model->cost_per_rank()));
}

