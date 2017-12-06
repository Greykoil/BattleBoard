//=============================================================================
//D The window that tracks the record of where points came from
//
//-----------------------------------------------------------------------------

// Class header include
#include "vieAdventureRecordWindow.h"

// includes from project
#include "vieAdventureRecordWidget.h"
#include "modAdventureRecordManager.h"
//includes from QT
#include <QTWidgets>

//=============================================================================
vieAdventureRecordWindow::vieAdventureRecordWindow(
  modAdventureRecordManager* model, 
  QWidget *parent
)
//
//-----------------------------------------------------------------------------
  : QDialog(parent),
    m_model(model)
{
  m_ui.setupUi(this);
  model->set_view(this);
}

//=============================================================================
void vieAdventureRecordWindow::update_after_load()
//
//D Update all the adventure records after a list is loaded
//
//-----------------------------------------------------------------------------
{
  for (int i = 0; i < m_model->num_adventures(); ++i) {
    add_record_widget(m_model->adventure(i));
  }
}

//=============================================================================
void vieAdventureRecordWindow::add_record_widget(modAdventureRecord* record)
//
//D A a new record widget to the list for record
//
//-----------------------------------------------------------------------------
{
  m_adventures.push_back(std::make_unique<vieAdventureRecordWidget>(record));
  // Add the record to the list
  vieAdventureRecordWidget* adventure = m_adventures[m_adventures.size() - 1].get();
  QListWidgetItem* item = new QListWidgetItem();
  item->setSizeHint(adventure->sizeHint());
  m_ui.listWidget->addItem(item);
  m_ui.listWidget->setItemWidget(item, adventure);
}

//=============================================================================
void vieAdventureRecordWindow::actionNewRecordButton()
//
//D The button has been pushed to add a new record to the list
//
//-----------------------------------------------------------------------------
{
  // Add a new adventure record to the model manager
  modAdventureRecord* record = m_model->add_new_adventure();
  add_record_widget(record);

}