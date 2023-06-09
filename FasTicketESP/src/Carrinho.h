#pragma once

#include <Arduino.h>

#define MAX 7

using namespace std;

class Carrinho
{
private:
  class Item
  {
  private:
    int code;
    String name;
    int price;
  public:
    Item(int n = 0);
    String getName();
    int getValor();
    ~Item();
  };
  int nItems;
  Item items[MAX];
public:
  Carrinho();
  ~Carrinho();
  String getItemName(int i);
  int getNItems();
  bool setItem(int n);
  void reset();
  bool deleteItem(int n);
  int getValor();
};
