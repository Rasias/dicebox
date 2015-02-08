// Copyright 2014 Ivo "Rasias" Enke
#include<stdio.h>
#include<iostream>
#include<string>
#include "./dicebox.h"

std::string name;
int dice;
int bonus;

using namespace dicebox;

int main(int argv, char** argc) {
  InitiativeTracker t;
  initInitiative(&t);  // Initializes the InitiativeTracker.
  while(true) {
    std::cout << "___" << std::endl;
    std::cout << "Press Enter to roll initiative, Sucker" << std::endl;
    std::cin.ignore();
    clearScreen();
    t.rollInitiative();
    t.printInitiative();
  }
  return 0;
}

