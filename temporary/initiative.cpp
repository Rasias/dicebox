// Copyright 2014
#include "./initiative.h"
bool sortInitiative(std::tuple<int, InitiativeChar*> a, std::tuple<int, InitiativeChar*> b) {
  return a > b;
}

InitiativeTracker::InitiativeTracker() {
  _count = 0;
}

int InitiativeTracker::addChar(std::string name, int dice, int bonus) {
  InitiativeChar* tmpChar;
  tmpChar = new InitiativeChar(name, dice, bonus);
  _chars.push_back(tmpChar);
  return _count;
}

void InitiativeTracker::printChars() {
  for (unsigned int i = 0; i < _chars.size(); i++) {
    _chars[i]->printChar();
  }
}

  void InitiativeTracker::printInitiative() {
  for (unsigned int i = 0; i < _initiativeList.size(); i++) {
      std::cout << std::get<1>(_initiativeList[i])->getName() << " - "
      << std::get<0>(_initiativeList[i]) << std::endl;
  }
}

bool InitiativeTracker::rollInitiative() {
  _initiativeList.clear();
  srand(time(NULL));
  int tmp;
  std::tuple<int, InitiativeChar*> tmpTuple;
    for (unsigned int i = 0; i < _chars.size(); i++) {
    tmp = _chars[i]->roll();
    if(tmp <= 10) {
      std::get<0>(tmpTuple) = tmp;
      std::get<1>(tmpTuple) = _chars[i];
      _initiativeList.push_back(tmpTuple);
      continue;
    }
    for(int j = tmp; j > 0; j-= 10) {
      std::get<0>(tmpTuple) = j;
      std::get<1>(tmpTuple) = _chars[i];
      _initiativeList.push_back(tmpTuple);
    }
  }
  std::sort (_initiativeList.begin(), _initiativeList.end(), sortInitiative);
  return true;
}


InitiativeChar::InitiativeChar() {
  _name = "";
  _dice = -1;
  _bonus = -1;
}

InitiativeChar::InitiativeChar(std::string name, int dice, int bonus) {
  _name = name; 
  _dice = dice;
  _bonus = bonus;
}

std::string InitiativeChar::getName() {
  return _name;
}
  
void InitiativeChar::printChar() {
  std::cout << "Name: " <<_name << std::endl;
  std::cout << "Dice: " << _dice << std::endl;
  std::cout << "Bonus: " << _bonus << std::endl;
}

int InitiativeChar::roll() {
  int dicerolls = 0;
  for (int i = 0; i < _dice; i++) {
    dicerolls = dicerolls + (rand() % 6) + 1;
  }
  return dicerolls + _bonus;
}
