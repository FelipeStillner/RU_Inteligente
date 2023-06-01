#include "Menu.h"

void Menu::begin(Adafruit_ILI9341* d, Carrinho* c)
{
  car = c;
  ds = d;
  ds->fillScreen(ILI9341_BLACK);
  ds->setCursor(0, 0);
  ds->setTextSize(3);
  ds->setTextColor(ILI9341_WHITE);
  str = String("Iniciar compra:");
  estado = EstINIC;
}

Menu::Menu()
{
  str = String();
  estado = 0;
}

Menu::~Menu()
{
}

void Menu::imprimir()
{
  ds->setCursor(0, 0);
  ds->fillScreen(ILI9341_BLACK);
  ds->print(str);
}

void Menu::atualizar(int est)
{
  if(est)
  {
    estado = est;
  }
  else
  {
    return;
  }

  switch (estado)
  {
  case EstINIC: // Estado Inicial
  {
    str = String("Iniciar compra:");// Inicial
    break;
  }
  case EstCARR: // Mostrar Carrinho
  {
    str = String("Adicione um Produto:\n");
    for (int i = 0; i < car->getNItems(); i++)
    {
      str.concat(i+1);
      str.concat(" - ");
      str.concat(car->getItemName(i));
      str.concat("\n");
    }
    break;
  }
  case EstCANC: // Cancelar Produto
  {
    str = String("Exclua seu Produto:\n");
    for (int i = 0; i < car->getNItems(); i++)
    {
      str.concat(i+1);
      str.concat(" - ");
      str.concat(car->getItemName(i));
      str.concat("\n");
    }
    break;
  }
  case EstRFID: // Fazer Pagamento
  {
    str = String("Aproxime seu\n cartao RFID:\n Valor:");
    str.concat(car->getValor());
    break;
  }
  case EstPGMT: // Pagamento feito
  {
    str = String("Pagamento efetuado\nimprimindo ficha");
    break;
  }
  case EstSSAL: // Pagamento nao feito
  {
    str = String("Saldo insuficiente");
    break;
  }
  }
}

int Menu::getEstado()
{
  return estado;
}