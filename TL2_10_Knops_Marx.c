#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
* Multiplikatoren für die verschiedenen Preise
*/
#define MULTIPL_LAGER 0.1
#define MULTIPL_VERWALTUNGS 0.1
#define MULTIPL_GEWINN 0.1
#define MULTIPL_VERSAND 0.05
#define MULTIPL_MONTAGE 0.15

/*
* Preise für die Fertig PCs
*/
#define PREIS_FUN_STAR 1243.43
#define PREIS_HIGH_END 1658.50
#define PREIS_MULTIMEDIA_STAR 698.20
#define PREIS_OFFICE_STAR 1015.39

/*
* Preise für die Gehäuse
*/
#define PREIS_COMPU_CASE_LX100 98.05
#define PREIS_COMPU_CASE_LX120 69.89
#define PREIS_COMPU_CASE_LX34A 105.60

/*
* Preise für die Einzelkomponenten
*/
#define PREIS_MAINBOARD 193.03
#define PREIS_CPU 334.65
#define PREIS_HDD 130.95
#define PREIS_GPU 319.13

#define MENU_INDENTATION_WHITESPACES 4

/*
* Funktionsprototypen
*/
void printMenuMain(void);
void printMenuStandartkonfiguration(void);
void printWarenkorbForMenu(int iMaxMenuLength);
void printLine(int iLength);
void printLineBreaks(int iLineBreaks);
void printTabs(int iTabs);
void printWhitespaces(int iWhitespaces);

// globale Variable für den Warenkorb
float fWarenkorb = 22320.0;

int main(void)
{
  int iSuccessfullInput = 0;

  printMenuMain();

  system("pause");

  return 0;
}

/*
===============================================================================
* Funktion: printMenuMain
* Input:
* Output:
Zeichnet das Hauptmenü
===============================================================================
*/
void printMenuMain(void)
{
  printLineBreaks(3);
  printWarenkorbForMenu(32);// Warenkorb anzeigen
  printLineBreaks(2);

  //Menu headline
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("P R E I S K A L K U L A T I O N");
  printLineBreaks(1);
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printLine(31);
  printLineBreaks(1);

  // Auswahlmöglichkeiten
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("a: Standardkonfiguration");
  printWhitespaces(22);
  printLineBreaks(2);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("b: Einzelkomponenten");
  printWhitespaces(22);
  printLineBreaks(2);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("x: Ende");
  printWhitespaces(22);
  printLineBreaks(2);
}

/*
===============================================================================
* Funktion:   printMenuStandartkonfiguration
* Input:      -
* Output:     -
===============================================================================
*/
void printMenuStandartkonfiguration(void)
{
  // Warenkorb
  printLineBreaks(3);// space top
  printWarenkorbForMenu(46);// Warenkorb anzeigen
  printLineBreaks(2); // space Warenkorb <-> Menu

  // Menu headline
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("S T A N D A R D K O N F I G U R A T I O N E N");
  printLineBreaks(1);
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printLine(45);
  printLineBreaks(1);

  // Auswahlmöglichkeiten
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



/*
===============================================================================
* Funktion:   printTabs
* Input:      int iTabs
* Output:     -
===============================================================================
*/
void printTabs(int iTabs)
{
  int i;

  for(i = 0;i < iTabs;i++)
  {
    printf("\t");
  }
}

/*
===============================================================================
* Funktion:   printWhitespaces
* Input:      int iWhitespaces
* Output:     -
===============================================================================
*/
void printWhitespaces(int iWhitespaces)
{
  int i;

  for(i = 0; i < iWhitespaces; i++)
  {
    printf(" ");
  }
}

/*
===============================================================================
* Funktion:   printWarenkorbForMenu
* Input:      -
* Output:     -
===============================================================================
*/
void printWarenkorbForMenu(int iMaxMenuLength)
{
  int iStartPos = iMaxMenuLength + MENU_INDENTATION_WHITESPACES - 25;

  printWhitespaces(iStartPos);
  printf("Warenkorb: ");
  printf("%7.2f Euro", fWarenkorb);
}

/*
===============================================================================
* Funktion:   printLineBreaks
* Input:      int iLinebreaks
* Output:     -
===============================================================================
*/
void printLineBreaks(int iLinebreaks)
{
  int i;
  
  for(i = 0;i < iLinebreaks;i++)
  {
    printf("\n");
  }
}
/*
===============================================================================
* Funktion:   printLine
* Input:      int iLength
* Output:     -
*
* Die Funktion gibt eine Linie, bestehend aus "=", mit der Länge iLength aus.
===============================================================================
*/
void printLine(int iLength)
{
  int i;

  for(i = 0; i < iLength; i++)
  {
    printf("=");
  }

  printf("\n");
}