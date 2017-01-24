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

#define MENU_INDENTATION_WHITESPACES 4

/*
* Funktionsprototypen
*/
void printMenuStandartkonfiguration(void);
void printMenuEinzelkomponenten(void);
void printWarenkorbForMenu(int iMaxMenuLength);
void printLine(int iLength);
void printLineBreaks(int iLineBreaks);
void printTabs(int iTabs);
void printWhitespaces(int iWhitespaces);

// globale Variable f�r den Warenkorb
float fWarenkorb = 22320.0;

int main(void)
{
  int iSuccessfullInput = 0;

  printMenuStandartkonfiguration();

  system("pause");

  return 0;
}

/******************************************************************************
* Funktion:   printMenuStandartkonfiguration
* Input:      -
* Output:     -
*
* Die Funktion gibt das Men� f�r die Standardkonfigurationen aus.
******************************************************************************/
void printMenuStandartkonfiguration(void)
{
  // Warenkorb
  printWarenkorbForMenu(46);// Warenkorb anzeigen

  // Menu headline
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("S T A N D A R D K O N F I G U R A T I O N E N");
  printLineBreaks(1);
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printLine(45);
  printLineBreaks(1);

  // Auswahlm�glichkeiten
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("1: Fun Star");
  printWhitespaces(22);
  printf("%7.2f Euro", PREIS_FUN_STAR);
  printLineBreaks(1);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("2: High End");
  // Leerzeichen zwischen Bezeichnung und Preis
  printWhitespaces(22);
  printf("%7.2f Euro", PREIS_HIGH_END);
  printLineBreaks(1);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("3: Multimedia Star");
  // Leerzeichen zwischen Bezeichnung und Preis
  printWhitespaces(15);
  printf("%7.2f Euro", PREIS_MULTIMEDIA_STAR);
  printLineBreaks(1);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("4: Office Star");
  // Leerzeichen zwischen Bezeichnung und Preis
  printWhitespaces(19);
  printf("%7.2f Euro", PREIS_OFFICE_STAR);
  printLineBreaks(1);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("0: Abbruch");
  printLineBreaks(1);
}

/******************************************************************************
* Funktion:   printMenuEinzelkomponenten
* Input:      -
* Output:     -
******************************************************************************/
void printMenuEinzelkomponenten(void){

  printWarenkorbForMenu(34);//Warenkorb anzeigen

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("E I N Z E L K O M P O N E N T E N");
  printLineBreaks(1);
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printLine(34);
  printLineBreaks(1);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("1: Gehaeuse");
  printLineBreaks(1);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("2: Mainboard");

}

/*******************************************************************************
* Funktion:   printTabs
* Input:      int iTabs
* Output:     -
*
* Die Funktion gibt die �bergebene Anzahl an Tabs aus ("\t");
******************************************************************************/
void printTabs(int iTabs)
{
  int i;

  for(i = 0;i < iTabs;i++)
  {
    printf("\t");
  }
}

/******************************************************************************
* Funktion:   printWhitespaces
* Input:      int iWhitespaces
* Output:     -
*
* Die Funktion gibt die �bergebene Anzahl an Whitespaces aus.
******************************************************************************/
void printWhitespaces(int iWhitespaces)
{
  int i;

  for(i = 0; i < iWhitespaces; i++)
  {
    printf(" ");
  }
}

/******************************************************************************
* Funktion:   printWarenkorbForMenu
* Input:      -
* Output:     -
*
* Die Funktion gibt den Warenkorb am rechten Rand des jeweiligen Men�s,
* basierend auf der angegebenenen maximalen Men�l�nge aus.
******************************************************************************/
void printWarenkorbForMenu(int iMaxMenuLength)
{
  int iStartPos = iMaxMenuLength + MENU_INDENTATION_WHITESPACES - 25;

  printLineBreaks(3);// space top
  printWhitespaces(iStartPos);
  printf("Warenkorb: ");
  printf("%7.2f Euro", fWarenkorb);
  printLineBreaks(2); // space Warenkorb <-> Menu
}

/******************************************************************************
* Funktion:   printLineBreaks
* Input:      int iLinebreaks
* Output:     -
*
* Die Funktion gibt die �bergebene Menge an Linebreaks ("\n") aus.
*******************************************************************************/
void printLineBreaks(int iLinebreaks)
{
  int i;
  
  for(i = 0;i < iLinebreaks;i++)
  {
    printf("\n");
  }
}
/******************************************************************************
* Funktion:   printLine
* Input:      int iLength
* Output:     -
*
* Die Funktion gibt eine Linie, bestehend aus "=", mit der L�nge iLength aus.
******************************************************************************/
void printLine(int iLength)
{
  int i;

  for(i = 0; i < iLength; i++)
  {
    printf("=");
  }

  printf("\n");
}