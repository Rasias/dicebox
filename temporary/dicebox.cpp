#include "./dicebox.h"


namespace dicebox {

  int initInitiative(InitiativeTracker* t){
    std::string name;
    int dice;
    int bonus;
    
    while(true) {
      std::cout << "Enter character name or \"cont\" to continue." << std::endl;
      std::cin >> name;
      if(name.compare("cont") == 0) break;
      std::cout << "Enter dice" << std::endl;
      std::cin >> dice;
      if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore();
        clearScreen();
        std::cout << "Error" << std::endl;
        continue;
      }
      std::cout << "Enter bonus" << std::endl;
      std::cin >> bonus;
      if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore();
        clearScreen();
        std::cout << "Error" << std::endl;
        continue;
      }
      t->addChar(name, dice, bonus);
    }
    return 0;
  }

  void clearScreen() {
    std::cout << std::string( 100, '\n' );
  }
}
