//=============================================================================
//
//D The view model interface between the skill view and the skill model
//
//-----------------------------------------------------------------------------
// includes from our libraries
#include "SkillVMManager.h"
#include "SkillWidget.h"
#include "SkillLinear.h"

// system includes
#include <assert.h>

//=============================================================================
SkillVMManager::SkillVMManager(SkillLinear* skill_model)
//
// <Full Description>
//
//-----------------------------------------------------------------------------
  : m_skill_model(skill_model)
{
  assert(skill_model != nullptr);
}

//=============================================================================
std::unique_ptr<SkillWidget> SkillVMManager::make_widget()
//
//D Make the widget for the corresponding skill
//
//-----------------------------------------------------------------------------
{
  auto skill_model = std::make_unique<SkillWidget>(
    QString::fromStdString(m_skill_model->name()),
    m_skill_model->cost_per_rank(),
    m_skill_model->max_picks(),
    m_skill_model->is_status()
  );

  m_skill_view = skill_model.get();

  return std::move(skill_model);
}


//=============================================================================
SkillVMManager::~SkillVMManager()
//
// Default destructor
//
//-----------------------------------------------------------------------------
{

}

