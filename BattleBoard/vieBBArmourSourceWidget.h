#pragma once

#include <QWidget>
#include "ui_vieBBArmourSourceWidget.h"

class modArmourSource;
class vieBBArmourWidget;

class vieBBArmourSourceWidget : public QWidget
{
    Q_OBJECT

public:
  vieBBArmourSourceWidget(modArmourSource* source, vieBBArmourWidget* armour_widget, QWidget *parent = Q_NULLPTR);


  ~vieBBArmourSourceWidget() = default;

private slots:

  void actionNameBoxChanged(QString name);

  void actionPhysicalBoxChanged(int value);

  void actionPowerBoxChanged(int value);

  void actionMagicBoxChanged(int value);

  void actionEvilBoxChanged(int value);

  void actionUndeadBoxChanged(int value);

  void actionDexterityBoxChanged(int value);


private:
    Ui::vieBBArmourSourceWidget m_ui;
    modArmourSource* m_model;
};
