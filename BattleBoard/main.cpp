#include "vieMainWindow.h"
#include "modCharacter.h"
#include "vwmCharacter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);


  modCharacter model_character(
    CHARACTER::RACE::ELF,
    CHARACTER::CLASS::MAGE
  );


  vwmCharacter view_model_character(
    &model_character
  );
  
  vieMainWindow main_window(&view_model_character, &model_character);



  main_window.show();
  return a.exec();
}
