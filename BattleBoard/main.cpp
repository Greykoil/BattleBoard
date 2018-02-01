#include "vieMainWindow.h"
#include "modCharacter.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);


  modCharacter model_character;


  //vwmCharacter view_model_character(
  //  &model_character
  //);
  
  vieMainWindow main_window(&model_character);



  main_window.show();
  return a.exec();
}
