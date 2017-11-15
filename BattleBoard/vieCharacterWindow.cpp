//=============================================================================
//D The character window
//
//-----------------------------------------------------------------------------

// Class header include
#include "vieCharacterWindow.h"

// includes from project
#include "vwmCharacter.h"

// System inlcudes
#include <assert.h>

//includes from QT


//=============================================================================
vieCharacterWindow::vieCharacterWindow(
  vwmCharacter* view_model, 
  QWidget *parent
)
//
//D Constructor
//
//-----------------------------------------------------------------------------
  : QDialog(parent),
    m_view_model(view_model)
{
  m_view_model->set_character_window(this);
  m_ui.setupUi(this);
  assert(m_view_model != nullptr);
  update();

}

//=============================================================================
void vieCharacterWindow::update()
//
//D Update the displayed information
//
//-----------------------------------------------------------------------------
{
  m_ui.pointsText->setText(QString::fromStdString(m_view_model->points_text()));
  m_ui.skillsText->setText(QString::fromStdString(m_view_model->skills_text()));
}
