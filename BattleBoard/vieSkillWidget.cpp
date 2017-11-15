//=============================================================================
//D Class for the skill as it is displayed in the skills tab
//
//-----------------------------------------------------------------------------

// Class header include
#include "vieSkillWidget.h"
// includes from project
#include "vwmSkill.h"

//includes from QT
#include <qmessagebox.h>

//System includes
#include <assert.h>
#include <algorithm>

//=============================================================================
vieSkillWidget::vieSkillWidget(
  vwmSkill* view_model,
  QString name, 
  int cost_per_rank,
  int max_picks,
  bool status_skill,
  int num_bought,
  QWidget *parent
)
//
//D Construct the visable widget and assign the labels
//
//-----------------------------------------------------------------------------
  : QWidget(parent),
    m_view_model(view_model)
{
  assert(view_model != nullptr);
  m_view_model->set_view_skill(this);
  m_ui.setupUi(this);
  m_ui.costLabel->setText(QString::number(cost_per_rank));
  m_ui.maxPicksLabel->setText(QString::number(max_picks));
  m_ui.nameLabel->setText(name);
  if (status_skill) {
    m_ui.statusSkillCheck->setCheckState(Qt::Checked);
  }
  m_ui.statusSkillCheck->setAttribute(Qt::WA_TransparentForMouseEvents);
  m_ui.statusSkillCheck->setFocusPolicy(Qt::NoFocus);
  m_ui.numberBoughtEdit->setText(QString::number(num_bought));
  m_ui.totalCostLabel->setText(QString::number(num_bought * cost_per_rank));
}


//=============================================================================
void vieSkillWidget::actionNumberPicksBoxChanged(QString new_text)
//
//D Called when the user changes the number of 
//
//-----------------------------------------------------------------------------
{
  int num_picks = m_ui.numberBoughtEdit->text().toInt();

  // toInt handles most edge cases but allows negative numbers which we 
  // don't want. 
  num_picks = std::max(0, num_picks);

  bool changed = m_view_model->change_num_picks(num_picks);

  if (!changed) {
    QMessageBox box;
    box.setText("Removing breaks dependency");
    box.exec();
  }

  m_ui.numberBoughtEdit->setText(QString::number(m_view_model->num_picks()));
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
  return m_view_model->is_visable();
}

