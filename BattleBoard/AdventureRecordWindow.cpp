//=============================================================================
//D The apps main window
//
// Contains a tab list of the windows where things actually happen
//
//-----------------------------------------------------------------------------

// Class header include
#include "AdventureRecordWindow.h"
// includes from project
#include "AdventureRecordWidget.h"

//includes from QT
#include <QTWidgets>

//=============================================================================
AdventureRecordWindow::AdventureRecordWindow(QWidget *parent)
//
//D Default constructor
//
//-----------------------------------------------------------------------------
  : QDialog(parent)
{
  QVBoxLayout* verticalLayout = new QVBoxLayout;
  QPushButton* PushButton = new QPushButton(this);
  PushButton->setObjectName(QStringLiteral("PushButton"));
  PushButton->setText("Add New Record");
  QObject::connect(PushButton, SIGNAL(clicked()), this, SLOT(actionNewRecordButton()));
  verticalLayout->addWidget(PushButton);
  verticalLayout->addWidget(create_new_record());
  setLayout(verticalLayout);
  m_vert_layout = verticalLayout;
  setWindowTitle(tr("Adventure Record"));
}

//=============================================================================
AdventureRecordWindow::~AdventureRecordWindow()
//
//D Default Destructor
//
//-----------------------------------------------------------------------------
{

}
//=============================================================================
QGroupBox* AdventureRecordWindow::create_new_record()
//
//D
//
//-----------------------------------------------------------------------------
{
  m_adventures.push_back(std::make_unique<AdventureRecordWidget>());
  return m_adventures[m_adventures.size() - 1].get();
}

//=============================================================================
void AdventureRecordWindow::actionNewRecordButton()
//
//D The button has been pushed to add a new record to the list
//
//-----------------------------------------------------------------------------
{
  m_vert_layout->addWidget(create_new_record());
}