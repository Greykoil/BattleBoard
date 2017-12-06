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
//D Default constructor
//
//-----------------------------------------------------------------------------
  : QDialog(parent),
    m_model(model)
{
  m_ui.setupUi(this);
}

//=============================================================================
vieAdventureRecordWindow::~vieAdventureRecordWindow()
//
//D Default Destructor
//
//-----------------------------------------------------------------------------
{

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
  m_adventures.push_back(std::make_unique<vieAdventureRecordWidget>(record));
  // Add the record to the list
  vieAdventureRecordWidget* adventure = m_adventures[m_adventures.size() - 1].get();
  QListWidgetItem* item = new QListWidgetItem();
  item->setSizeHint(adventure->sizeHint());
  m_ui.listWidget->addItem(item);
  m_ui.listWidget->setItemWidget(item, adventure);
}