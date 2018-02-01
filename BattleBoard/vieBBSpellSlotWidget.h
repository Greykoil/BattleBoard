#pragma once

#include <QWidget>
#include "ui_vieBBSpellSlotWidget.h"

class modSkill;

class vieBBSpellSlotWidget : public QWidget
{
    Q_OBJECT

public:
    vieBBSpellSlotWidget(modSkill* spell_slot, QWidget *parent = Q_NULLPTR);
    
    void redraw();

    ~vieBBSpellSlotWidget() = default;

private:
    Ui::vieBBSpellSlotWidget m_ui;
    modSkill* m_spell_slot;
};
