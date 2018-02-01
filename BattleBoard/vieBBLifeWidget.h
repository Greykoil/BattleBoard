#pragma once

#include <QWidget>
#include "ui_vieBBLifeWidget.h"

class vieBBLifeWidget : public QWidget
{
    Q_OBJECT

public:
  vieBBLifeWidget(QWidget *parent = Q_NULLPTR);
  
  
  void update(int life);
  // Update the life to show the new value

  ~vieBBLifeWidget();

private:
  Ui::vieBBLifeWidget m_ui;
};
