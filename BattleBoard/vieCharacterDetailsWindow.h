//=============================================================================
//D The character details window. 
//
// Has information about the character name, class and race
//
//-----------------------------------------------------------------------------
#pragma once
// includes from project
#include "modCharacterDetailsEnum.h"
// QT ui include
#include "ui_vieCharacterDetailsWindow.h"

//includes from QT
#include <QDialog>
#include <QtWidgets>

// system includes

// class predeclarations to avoid header file inclusion
// types: classes, enums, typedefs
class modCharacterDetails;

//=============================================================================
class vieCharacterDetailsWindow : public QDialog
{
  Q_OBJECT

public:
  vieCharacterDetailsWindow(
    modCharacterDetails* model,
    QWidget *parent = Q_NULLPTR
  );
  // Constructor

  vieCharacterDetailsWindow(const vieCharacterDetailsWindow&) = delete;
  // Deleted copy constructor.

  vieCharacterDetailsWindow& operator=(const vieCharacterDetailsWindow&) = delete;
  // Deleted assignment operator.
    
  ~vieCharacterDetailsWindow() = default;
  // Default destructor

protected:
  
private slots:

  void actionCharacterNameChanged(QString name);
  // Called when the user changes the character name

  void actionCharacterRaceChanged(QString race);
  // Called when the user changes the character race

  void actionCharacterClassChanged(QString character_class);
  // Called when the user changes the character class

  void actionCharacterAlignmentChanged(QString alignment);
  // Called when the user changes the characters alignment

  void actionCharacterGuildChanged(QString guild);
  // Called when the user changes the characters guild

private:

  modCharacterDetails* m_model;
  // The model which will do all of the work

  Ui::vieCharacterDetailsWindow m_ui;
  // The gui class provided by QT
};
