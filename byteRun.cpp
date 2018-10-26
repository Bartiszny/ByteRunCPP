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
int wyjscie[100]; //bufor
short ind=1;
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
  wyjscie[i]=0;
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
        wyjscie[j]=-(indeks-1);
        j++;
        wyjscie[j]=int(tab2[i]-48);
        i=i+indeks-1;
        indeks=1;
      } else if (tab2[i]!=tab2[i+1]) {
        while (tab2[i+indeks]!=tab2[i+indeks+1])
        {
          if(indeks<sizeof(tab2))
          { indeks++;
            ind++;
          //  if (tab2[i+indeks+1]==tab2[i+indeks+2]) {
          //  ind--;
          //  }
          }
        }
          indeks++;
          wyjscie[j]=(ind);
          j++;
          for (size_t k = 0; k < ind; k++) {
          wyjscie[j+1+k]=int(tab2[i+k]-48);
          }

        //  wyjscie[j]=int(tab2[i]-48);
          i=i+ind;
          indeks=1;
          ind=1;
      //  wyjscie[j]=1;
        //j++;
      //  wyjscie[j]=int(tab2[i]-48);
        }
      j++;
      //licznik=j;
    }
  for (size_t i = 0; i <sizeof(wyjscie); i++) {
    if(wyjscie[i]==0&&wyjscie[i+1]==0)
      { licznik--;
        break;
      }
        else
      {
        licznik++;
      }
    }
  std::cout << licznik << '\n';
  int wektor[licznik];
  for (size_t i = 0; i <=licznik; i++) {
    wektor[i]=wyjscie[i];
    std::cout <<wektor[i];
    }
//%%%%%%KONIEC%%%%%%%%%%%%%%%%%%%%
  return 0;
}
