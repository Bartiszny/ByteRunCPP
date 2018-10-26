#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[]) {
//%%%%%%%%%ZMIENNE%%%%%%%%%%%%%%

string temp;
short licznik=0;   //długoąć indeksów
short indeks =1;    // licznik indeksów tych samych liczb
short j=0;          // indeks roboczy bufora
char wyjscie[100]; //bufor
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//Wprowadznie danych
std::cout << "Wpisz ciąg liczb" << '\n';
std::cin >> temp;
//Konwersja string -> char
char tab2[strlen(temp.c_str())];
strcpy(tab2, temp.c_str());

//Program
/*std::cout << "Wpisany wektor: " << '\n';
for (size_t i = 0; i <= sizeof(tab2); i++) {
    std::cout << tab2[i];
  }*/
//%%%%%%% Inicjalizacja bufora %%%%
  for (size_t i = 0; i < 100; i++) {
  wyjscie[i]='0';
  }
//%%%%%%% Szukanie podobnych wystąpień %%%%
  for (size_t i=0; i<sizeof(tab2);i++)
    {
      if(tab2[i]==tab2[i+1])
      {
        while (tab2[i+indeks]==tab2[i+indeks+1])
        {
          if(indeks<sizeof(tab2))
          indeks++;
        }
        indeks++;
        wyjscie[j]=tab2[i];
        j++;
        wyjscie[j]=char(indeks+48);
        i=i+indeks-1;
        indeks=1;
      } else
        {
        wyjscie[j]=tab2[i];
        j++;
        wyjscie[j]='1';
        }
      j++;
      licznik=j;
    }
  char wektor[licznik];
  //  for (size_t i = 0; i <sizeof(wyjscie); i++) {
    //std::cout <<wyjscie[i];
  //  }
    std::cout << '\n';
    for (size_t i = 0; i <sizeof(wektor); i++) {
    wektor[i]=wyjscie[i];
    std::cout <<wektor[i];
    }
//%%%%%%KONIEC%%%%%%%%%%%%%%%%%%%%
  return 0;
}
