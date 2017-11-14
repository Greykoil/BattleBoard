//=============================================================================
//
//D The view model interface between the skill view and the skill model
//
//-----------------------------------------------------------------------------
// includes from our libraries
#include "vwmSkill.h"
#include "vieSkillWidget.h"
#include "modSkill.h"

// system includes
#include <assert.h>

//=============================================================================
vwmSkill::vwmSkill(modSkill* skill_model)
//
// <Full Description>
//
//-----------------------------------------------------------------------------
  : m_skill_model(skill_model)
{
  assert(skill_model != nullptr);
}

//=============================================================================
std::unique_ptr<vieSkillWidget> vwmSkill::make_widget()
//
//D Make the widget for the corresponding skill
//
//-----------------------------------------------------------------------------
{
  auto skill_model = std::make_unique<vieSkillWidget>(
    QString::fromStdString(m_skill_model->name()),
    m_skill_model->cost_per_rank(),
    m_skill_model->max_picks(),
    m_skill_model->is_status()
  );

  m_skill_view = skill_model.get();

  return std::move(skill_model);
}


//=============================================================================
vwmSkill::~vwmSkill()
//
// Default destructor
//
//-----------------------------------------------------------------------------
{

}

