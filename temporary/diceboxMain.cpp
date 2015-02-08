// Copyright 2014 Ivo "Rasias" Enke
#include<stdio.h>
#include<iostream>
#include<string>
#include "initiative.h"

void ClearScreen();
std::string name;
int dice;
int bonus;

int main(int argv, char** argc) {
  InitiativeTracker t;
  while(true) {
    std::cout << "Enter character name or \"cont\" to continue." << std::endl;
    std::cin >> name;
    if(name.compare("cont") == 0) break;
    std::cout << "Enter dice" << std::endl;
    std::cin >> dice;
    if(std::cin.fail()){
      std::cin.clear();
      std::cin.ignore();
      ClearScreen();
      std::cout << "Error" << std::endl;
      continue;
    }
    std::cout << "Enter bonus" << std::endl;
    std::cin >> bonus;
    if(std::cin.fail()){
      std::cin.clear();
      std::cin.ignore();
      ClearScreen();
      std::cout << "Error" << std::endl;
      continue;
    }
    t.addChar(name, dice, bonus);
  }
  while(true) {
    std::cout << "___" << std::endl;
    std::cout << "Press Enter to roll initiative, Sucker" << std::endl;
    std::cin.ignore();
    ClearScreen();
    t.rollInitiative();
    t.printInitiative();
  }
  return 0;
}

void ClearScreen() {
  std::cout << std::string( 100, '\n' );
}
