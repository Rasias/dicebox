// Copyright 2014
#include<stdlib.h>
#include<time.h>
#include<string>
#include<vector>
#include<tuple>
#include<iostream>
#include<algorithm>


class InitiativeTracker;
class InitiativeChar;

class InitiativeTracker {
 public:
  InitiativeTracker();

  int addChar(std::string name, int dice, int bonus);
  void printChars();
  bool rollInitiative();
  void printInitiative();
 private:
  int _count;
  std::vector<InitiativeChar*> _chars;
  std::vector<std::tuple<int, InitiativeChar*>> _initiativeList;
};

class InitiativeChar {  
 public:
  InitiativeChar();
  InitiativeChar(std::string name, int dice, int bonus);
  int roll();

  void printChar();
  std::string getName();
 private:
  std::string _name;
  int _dice;
  int _bonus;
};

