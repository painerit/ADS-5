// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int priority(char symb) {
  if (symb == '(') {
    return 0;
  }
  if (symb == ')') {
    return 1;
  }
  if (symb == '+' || symb == '-') {
    return 2;
  }
  if (symb == '/' || symb == '*') {
    return 3;
    }
    return -1;
}

std::string infx2pstfx(std::string inf) {
  TStack <char, 100> myStack;
  std::string pstfx;
  for (int i = 0; i < inf.length(); ++i) {
    int prior = priority(inf[i]);
    if (prior == -1) {
      if (!pstfx.empty() && priority(inf[i - 1]) != -1) {
        pstfx.push_back(' ');
      }
      pstfx.push_back(inf[i]);
      } else if (prior == 0 || prior > priority(myStack.get()) || myStack.isEmpty()) {
        myStack.push(inf[i]);
      } else {
        if (prior == 1) {
          while (myStack.get() != '(') {
            pstfx.push_back(' ');
            pstfx.push_back(myStack.get());
            myStack.pop();
          }
          myStack.pop();
        } else {
          while (priority(myStack.get()) >= prior) {
            pstfx.push_back(' ');
            pstfx.push_back(myStack.get());
            myStack.pop();
          }
          myStack.push(inf[i]);
        }
      }
  }
  while (!myStack.isEmpty()) {
    pstfx.push_back(' ');
    pstfx.push_back(myStack.get());
    myStack.pop();
  }
  return pstfx;
}

int eval(std::string pref) {
  // добавьте код
  return 0;
}
