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
void printMenuGehaeuse(void);
void printWarenkorbForMenu(int iMaxMenuLength);
void printPreisAusgabeStandard(float fPreisArtikel, int iAnzahlArtikel, int iVersand);
void runMenuGehaeuse(void);
void runMenuMain(void);
void runMenuEinzelkomponenten(void);
void clearScreen(void);
void programmExit(void);
void printLine(int iLength);
void printLineBreaks(int iLineBreaks);
void printTabs(int iTabs);
void printWhitespaces(int iWhitespaces);

// globale Variable für den Warenkorb
float fWarenkorb = 22320.0;

int main(void)
{
  int iSuccessfullInput = 0;

  runMenuMain();

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
* Funktion: printMenuGehaeuse
* Input:
* Output:
Zeichnet das Gehäusemenü
===============================================================================
*/
void printMenuGehaeuse(void)
{
  printLineBreaks(3);
  printWarenkorbForMenu(30);// Warenkorb anzeigen
  printLineBreaks(2);

  //Menu headline
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("G E H A E U S E A U S W A H L");
  printLineBreaks(1);
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printLine(29);
  printLineBreaks(1);

  // Auswahlmöglichkeiten
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("1: Compucase LX100");
  printWhitespaces(15);
  printf("%7.2f Euro", PREIS_COMPU_CASE_LX100);
  printLineBreaks(1);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("2: Compucase LX120");
  printWhitespaces(15);
  printf("%7.2f Euro", PREIS_COMPU_CASE_LX120);
  printLineBreaks(1);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("3: Compucase LX34A");
  printWhitespaces(15);
  printf("%7.2f Euro", PREIS_COMPU_CASE_LX34A);
  printLineBreaks(1);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("0: Abbruch");
  printLineBreaks(1);
}

/*
===============================================================================
* Funktion: printPreisAusgabeStandard
* Input: fPreisArtikel, iAnzahlArtikel, iVersand
* Output:
Gibt die Preise aus.
===============================================================================
*/
void printPreisAusgabeStandard(float fPreisArtikel, int iAnzahlArtikel, int iVersand)
{

  float fListenPreisGesamt=iAnzahlArtikel * fPreisArtikel,
        fLagerkosten = fListenPreisGesamt * MULTIPL_LAGER, 
        fMaterialKosten = fListenPreisGesamt + fLagerkosten,
        fVerwaltungsKosten = fMaterialKosten * MULTIPL_VERWALTUNGS,
        fSelbstKosten = fMaterialKosten + fVerwaltungsKosten,
        fGewinn = fSelbstKosten * MULTIPL_GEWINN,
        fBarverkaufsPreis = fSelbstKosten + fGewinn,
        fVersandKosten = fBarverkaufsPreis * MULTIPL_VERSAND,
        fVersandPreis = fBarverkaufsPreis + fVersandKosten;

  clearScreen();

  printLineBreaks(3);
  printWarenkorbForMenu(30);// Warenkorb anzeigen
  printLineBreaks(5);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("Listenpreis pro Artikel:");
  printWhitespaces(10);
  printf("%7.2f Euro", fPreisArtikel);
  printLineBreaks(1);
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printLine(46);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("Listenpreis gesamt:");
  printWhitespaces(15);
  printf("%7.2f Euro", fListenPreisGesamt);
  printLineBreaks(1);


  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("+ Lagerkosten:");
  printWhitespaces(21);
  printf("%7.2f Euro", fLagerkosten);
  printLineBreaks(1);
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printLine(46);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("Materialkosten:");
  printWhitespaces(19);
  printf("%7.2f Euro", fMaterialKosten);
  printLineBreaks(1);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("+ Verwaltungskosten:");
  printWhitespaces(15);
  printf("%7.2f Euro", fVerwaltungsKosten);
  printLineBreaks(1);
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printLine(46);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("Selbstkosten:");
  printWhitespaces(21);
  printf("%7.2f Euro", fSelbstKosten);
  printLineBreaks(1);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("+ Gewinn:");
  printWhitespaces(26);
  printf("%7.2f Euro", fGewinn);
  printLineBreaks(1);
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printLine(46);

  if(iVersand == 1)
  {
    printWhitespaces(MENU_INDENTATION_WHITESPACES);
    printf("Versandpreis:");
    printWhitespaces(21);
    printf("%7.2f Euro",  fVersandPreis);
  }
}

/*
===============================================================================
* Funktion: printPreisAusgabeEinzel
* Input: fPreisArtikel, iAnzahlArtikel, iVersand, iMontage
* Output:
Gibt die Preise aus
===============================================================================
*/
void printPreisAusgabeEinzel(float fPreisArtikel, int iAnzahlArtikel, int iVersand, int iMontage)
{

  float fListenPreisGesamt=iAnzahlArtikel * fPreisArtikel,
        fLagerkosten = fListenPreisGesamt * MULTIPL_LAGER, 
        fMaterialKosten = fListenPreisGesamt + fLagerkosten,
        fFertigungsKosten = fMaterialKosten * MULTIPL_MONTAGE,
        fHerstellungsKosten = fMaterialKosten + fFertigungsKosten,
        fVerwaltungsKosten = fHerstellungsKosten * MULTIPL_VERWALTUNGS,
        fSelbstKosten = fHerstellungsKosten + fVerwaltungsKosten,
        fGewinnKosten = fSelbstKosten * MULTIPL_GEWINN,
        fBarverkaufsPreis = fSelbstKosten + fGewinnKosten,
        fVersandKosten = fBarverkaufsPreis * MULTIPL_VERSAND,
        fVersandPreis = fBarverkaufsPreis + fVersandKosten;

  clearScreen();

  printLineBreaks(3);
  printWarenkorbForMenu(30);// Warenkorb anzeigen
  printLineBreaks(5);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("Listenpreis pro Artikel:");
  printWhitespaces(10);
  printf("%7.2f Euro", fPreisArtikel);
  printLineBreaks(1);
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printLine(46);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("Listenpreis gesamt:");
  printWhitespaces(15);
  printf("%7.2f Euro", fListenPreisGesamt);
  printLineBreaks(1);


  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("+ Lagerkosten:");
  printWhitespaces(21);
  printf("%7.2f Euro", fLagerkosten);
  printLineBreaks(1);
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printLine(46);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("Materialkosten:");
  printWhitespaces(19);
  printf("%7.2f Euro", fMaterialKosten);
  printLineBreaks(1);

  if(iMontage == 1)

  {
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("+ Fertigungskosten:");
  printWhitespaces(15);
  printf("%7.2f Euro", fFertigungsKosten);
  printLineBreaks(1);
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printLine(46);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("Herstellungskosten:");
  printWhitespaces(21);
  printf("%7.2f Euro", fHerstellungsKosten);
  printLineBreaks(1);
  }

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("+ Verwaltungskosten:");
  printWhitespaces(26);
  printf("%7.2f Euro", fVerwaltungsKosten);
  printLineBreaks(1);
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printLine(46);

   printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("Selbstkosten:");
  printWhitespaces(21);
  printf("%7.2f Euro", fSelbstKosten);
  printLineBreaks(1);
  
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("+ Gewinn:");
  printWhitespaces(26);
  printf("%7.2f Euro", fGewinnKosten);
  printLineBreaks(1);
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printLine(46);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("Barverkaufspreis:");
  printWhitespaces(21);
  printf("%7.2f Euro", fBarverkaufsPreis);
  printLineBreaks(1);

  if(iVersand == 1)
  {
    printWhitespaces(MENU_INDENTATION_WHITESPACES);
    printf("+ Versandkosten:");
    printWhitespaces(21);
    printf("%7.2f Euro",  fVersandKosten);
    printLineBreaks(1);

    printWhitespaces(MENU_INDENTATION_WHITESPACES);
    printf("Versandpreis:");
    printWhitespaces(21);
    printf("%7.2f Euro",  fVersandPreis);
  }
}



/*
===============================================================================
* Funktion: runMenuGehaeuse
* Input:
* Output:

Leert den Bildschirm und zeichnet dann das Gehäusemenü. Es überprüft auch die
Auswahl.
===============================================================================
*/

float runMenuGehaeuse(void)
{
  int iAuswahl=4;
  float fProduktPreis;

  do
  {
    clearScreen();

    printMenuGehaeuse();

    printLineBreaks(1);

    printWhitespaces(MENU_INDENTATION_WHITESPACES);
    printf("Auswahl: ");
    fflush(stdin);
    scanf("%1i", &iAuswahl);
  }
  while (iAuswahl>=4);

  switch (iAuswahl)
  {
    case 1:
      fProduktPreis = PREIS_COMPU_CASE_LX100;
    break;
    case 2:
      fProduktPreis = PREIS_COMPU_CASE_LX120;
    break;
    case 3:
      fProduktPreis = PREIS_COMPU_CASE_LX34A;
    break;
    default:
      runMenuEinzelkomponenten();
    break;
  }

  return fProduktPreis;
}

/*
===============================================================================
* Funktion: runMenuStandardkonfiguration
* Input:
* Output:

Leert den Bildschirm und zeichnet dann das Standardkonfigurationsmenü. Es
überprüft auch die Auswahl.
===============================================================================
*/

float runMenuStandardkonfiguration(void)
{
  int iAuswahl=5;
  float fProduktPreis;

  do
  {
    clearScreen();

    //printMenuStandardkonfiguration();

    printLineBreaks(1);

    printWhitespaces(MENU_INDENTATION_WHITESPACES);
    printf("Auswahl: ");
    fflush(stdin);
    scanf("%1i", &iAuswahl);
  }
  while (iAuswahl>=5);

  switch (iAuswahl)
  {
    case 1:
      fProduktPreis = PREIS_FUN_STAR;
    break;
    case 2:
      fProduktPreis = PREIS_HIGH_END;
    break;
    case 3:
      fProduktPreis = PREIS_MULTIMEDIA_STAR;
    break;
    case 4:
      fProduktPreis = PREIS_OFFICE_STAR;
    break;
    default:
      runMenuMain();
    break;
  }
  return fProduktPreis;
}

/*
===============================================================================
* Funktion: runMenuEinzelkomponenten
* Input:
* Output:

Leert den Bildschirm und zeichnet dann das Einzelkomponentenmenü. Es überprüft 
auch die Auswahl.
===============================================================================
*/

float runMenuEinzelkomponenten(void)
{
  int iAuswahl=6;
  float fProduktPreis;

  do
  {
    clearScreen();

    //printMenuEinzelkomponenten();

    printLineBreaks(1);

    printWhitespaces(MENU_INDENTATION_WHITESPACES);
    printf("Auswahl: ");
    fflush(stdin);
    scanf("%1i", &iAuswahl);
  }
  while (iAuswahl>=6);
}


/*
===============================================================================
* Funktion: clearScreen
* Input:
* Output:

Leert den Bildschirm
===============================================================================
*/
void clearScreen(void)
{
  system("cls");
}


/*
===============================================================================
* Funktion: exit
* Input:
* Output:

Beendet das Programm
===============================================================================
*/

void programmExit(void)
{
  
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