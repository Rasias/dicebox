// Copyright 2014 Ivo "Rasias" Enke
#include<stdio.h>
#include<iostream>
#include "../initiative/initiative.h"

int main(int argv, char** argc) {
  InitiativeChar c("stuff", 1, 24);
  // c.printChar();
  InitiativeTracker t;
  t.addChar("stuff2", 1, 7);
  t.addChar("sf3", 1, 8);
  // t.printChars();
  t.rollInitiative();
  t.printInitiative();
  return 0;
}
