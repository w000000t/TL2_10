#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* Multiplikatoren f�r die verschiedenen Preise
*/
#define MULTIPL_LAGER 0.1
#define MULTIPL_VERWALTUNGS 0.1
#define MULTIPL_GEWINN 0.1
#define MULTIPL_VERSAND 0.05
#define MULTIPL_MONTAGE 0.15

/*
* Preise f�r die Fertig PCs
*/
#define PREIS_FUN_STAR 1243.43
#define PREIS_HIGH_END 1658.50
#define PREIS_MULTIMEDIA_STAR 698.20
#define PREIS_OFFICE_STAR 1015.39

/*
* Preise f�r die Geh�use
*/
#define PREIS_COMPU_CASE_LX100 98.05
#define PREIS_COMPU_CASE_LX120 69.89
#define PREIS_COMPU_CASE_LX34A 105.60

/*
* Preise f�r die Einzelkomponenten
*/
#define PREIS_MAINBOARD 193.03
#define PREIS_CPU 334.65
#define PREIS_HDD 130.95
#define PREIS_GPU 319.13

// globale Variable f�r den Warenkorb
float fWarenkorb = 0.0;

int main(void){
  int iSuccessfullInput = 0;
}

/*
* Funktion:   printMenuStandartkonfiguration
* Input:      -
* Output:     -
*/
void printMenuStandartkonfiguration(void){

}

/*
* Funktion:   printLine
* Input:      int iLength
* Output:     -
*
* Die Funktion gibt eine Linie, bestehend aus "=", mit der L�nge iLength aus.
*/
void printLine(int iLength){
  int i;

  for(i = 0; i < iLength; i++){
    printf("=");
  }

  printf("\n");
}