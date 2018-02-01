#pragma once

#include <QWidget>
#include "ui_vieBBMagicWidget.h"

class modMagicManager;
class vieBBSpellSlotWidget;

class vieBBMagicWidget : public QWidget
{
    Q_OBJECT

public:
    vieBBMagicWidget(modMagicManager* magic_manager, QWidget *parent = Q_NULLPTR);

    void update();

    ~vieBBMagicWidget() = default;

private:
    Ui::vieBBMagicWidget m_ui;

    modMagicManager* m_magic_manager;

    std::vector<vieBBSpellSlotWidget*> m_slots;
};
