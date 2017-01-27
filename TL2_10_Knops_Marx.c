#define _CRT_SECURE_NO_WARNINGS

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

// Anzahl der Leerzeichen, die jedes Menü eingerückt ist.
#define MENU_INDENTATION_WHITESPACES 4

/*
* Funktionsprototypen
*/
// Ausgabefunktionen für die Menüs
void printMenuMain(void);
void printMenuStandardkonfiguration(void);
void printMenuEinzelkomponenten(void);
void printWarenkorbForMenu(int iMaxMenuLength);
void printMenuGehaeuse(void);
float printPreisAusgabeStandard(
  float fPreisArtikel,
  int iAnzahlArtikel,
  int iVersand,
  int iMontage
);
float printPreisAusgabeEinzel(
  float fPreisArtikel,
  int iAnzahlArtikel,
  int iVersand,
  int iMontage
);

// Logikfunktionen für die Menüs
void runMenuMain(void);
void runMenuEinzelkomponenten(void);
void runMenuGehaeuse(void);
void runMenuStandardkonfiguration(void);

void addProductToCart(
  float fProduktPreis,
  int iMontageEnabled,
  int iVersandEnabled,
  int iEinzelkomponente
);

// Utility Funktionen
void clearScreen(void);
void printLine(int iLength);
void printLineBreaks(int iLineBreaks);
void printTabs(int iTabs);
void printWhitespaces(int iWhitespaces);

// globale Variable für den Warenkorb
float fWarenkorb = 0.0;

int main(void)
{
  runMenuMain();

  return 0;
}

/******************************************************************************
* Funktion:   runMenuMain
* Input:      -
* Output:     -
*
* Die Funktion ruft zum einen die Funktion printMenuMain() auf, zu anderen
* liest die Funktion die Eingabe des Nutzers ein und öffnet das gewünschte Menü
******************************************************************************/
void runMenuMain(void){
  int iSuccessfullInput = 0;

  char cAuswahl[2],
       cAuswahlStandardkonfigurationen[] = "a",
       cAuswahlEinzelkomponenten[] = "b",
       cAuswahlAbbruch[] = "x";

  do{
    clearScreen();
    printMenuMain();

    printLineBreaks(1);
    printWhitespaces(MENU_INDENTATION_WHITESPACES);
    printf("Auswahl: ");
    fflush(stdin);
    iSuccessfullInput = scanf("%s", cAuswahl);
    if(iSuccessfullInput == 1){
      if(strcmp(cAuswahl, cAuswahlStandardkonfigurationen) == 0){
        runMenuStandardkonfiguration();
      }
      if(strcmp(cAuswahl, cAuswahlEinzelkomponenten) == 0){
        runMenuEinzelkomponenten();
      }
    }
  } while(iSuccessfullInput == 0 || strcmp(cAuswahl, cAuswahlAbbruch) != 0);
}

/******************************************************************************
* Funktion: runMenuEinzelkomponenten
* Input:    -
* Output:   -
*
* Die Funktion gibt das Menü für die Einzelkomponenten aus und liest die
* Auswahl ein und fügt das ausgewählte Produkt dem Warenkorb hinzu.
******************************************************************************/
void runMenuEinzelkomponenten(void){
  int iSuccessfullInput = 0,
      iAuswahl;

  do{
    clearScreen();
    printMenuEinzelkomponenten();

    printLineBreaks(1);
    printWhitespaces(MENU_INDENTATION_WHITESPACES);
    printf("Auswahl: ");
    fflush(stdin);

    iSuccessfullInput = scanf("%i", &iAuswahl);

    if(iSuccessfullInput == 1){
      switch(iAuswahl){
        // Gehäuse
        case 1:
          runMenuGehaeuse();
          break;
        // Mainboard
        case 2:
          addProductToCart(PREIS_MAINBOARD, 1, 1, 1);
          iAuswahl = 0;
          break;
        // CPU
        case 3:
          addProductToCart(PREIS_CPU, 1, 1, 1);
          iAuswahl = 0;
          break;
        // HDD
        case 4:
          addProductToCart(PREIS_HDD, 1, 1, 1);
          iAuswahl = 0;
          break;
        // GPU
        case 5:
          addProductToCart(PREIS_GPU, 1, 1, 1);
          iAuswahl = 0;
          break;
        case 0:
          runMenuMain();
          break;
      }
    }
  } while(iSuccessfullInput == 0 || iAuswahl != 0);
}

/******************************************************************************
* Funktion: runMenuGehaeuse
* Input:    -
* Output:   -
* Leert den Bildschirm und zeichnet dann das Gehäusemenü. Es überprüft auch die
* Auswahl.
******************************************************************************/
void runMenuGehaeuse(void){
  int iAuswahl, iSuccessfullInput = 0;
  float fProduktPreis;

  do{
    clearScreen();

    printMenuGehaeuse();

    printLineBreaks(1);

    printWhitespaces(MENU_INDENTATION_WHITESPACES);
    printf("Auswahl: ");
    fflush(stdin);
    iSuccessfullInput = scanf("%1i", &iAuswahl);
  } while(iSuccessfullInput == 0);

  switch(iAuswahl){
    // Case LX100
    case 1:
      fProduktPreis = PREIS_COMPU_CASE_LX100;
      break;
    // Case LX120
    case 2:
      fProduktPreis = PREIS_COMPU_CASE_LX120;
      break;
    // Case LX34A
    case 3:
      fProduktPreis = PREIS_COMPU_CASE_LX34A;
      break;
    case 0:
      runMenuEinzelkomponenten();
      break;
  }
  addProductToCart(fProduktPreis, 1, 1, 1);
}

/******************************************************************************
* Funktion:   addProductToCart
* Input:      float fProduktPreis,
*             int iMontageEnabled,
*             int iVersandEnabled,
*             int iEinzelkomponente
* Output:     -
*
* Die Funktion fragt die verschiedenen Informationen wie Anzahl,
* Versand und Montage ab und gibt zum Schluss die Preisübersicht
* aus und fügt den Artikel zum Warenkorb hinzu.
*******************************************************************************/
void addProductToCart(
  float fProduktPreis,
  int iMontageEnabled,
  int iVersandEnabled,
  int iEinzelkomponente
){
  int iSuccessfullInput = 0,
      iAnzahl,
      iMontage,
      iVersand,
      iWarenkorb;

  char cMontage[2],
       cVersand[2],
       cWarenkorb[2],
       cJa[] = "j",
       cNein[] = "n";

  float fPreis;

  // Anzahl der Produkte einlesen
  do{
    printLineBreaks(1);
    printWhitespaces(MENU_INDENTATION_WHITESPACES);
    printf("Anzahl: ");

    fflush(stdin);
    iSuccessfullInput = scanf("%i", &iAnzahl);
  } while(iSuccessfullInput == 0 || iAnzahl < 0);

  // Montage abfrage (j/n)
  if(iMontageEnabled == 1){

    // Abfragen, ob Montage gewünscht
    iSuccessfullInput = 0;
    do{
      printLineBreaks(1);
      printWhitespaces(MENU_INDENTATION_WHITESPACES);
      printf("Montage (j/n)? ");

      fflush(stdin);
      iSuccessfullInput = scanf("%s", cMontage);

      if(strcmp(cMontage, cJa) == 0){
        // Ja
        iMontage = 1;
      } else if(strcmp(cMontage, cNein) == 0){
        // Nein
        iMontage = 0;
      } else{
        // else
        iMontage = -1;
      }
    } while(iSuccessfullInput == 0 || iMontage == -1);
  }

  // Versand abfrage(j/n)
  if(iVersandEnabled == 1){

    // Abfrage, ob Versand gewünscht ist
    iSuccessfullInput = 0;
    do{
      printLineBreaks(1);
      printWhitespaces(MENU_INDENTATION_WHITESPACES);
      printf("Versand (j/n)? ");

      fflush(stdin);
      iSuccessfullInput = scanf("%s", cVersand);

      if(strcmp(cVersand, cJa) == 0){
        iVersand = 1;
      } else if(strcmp(cVersand, cNein) == 0){
        iVersand = 0;
      } else{
        iVersand = -1;
      }
    } while(iSuccessfullInput == 0 || iVersand == -1);
  }

  clearScreen();

  if(iEinzelkomponente == 1){
    fPreis = printPreisAusgabeEinzel(fProduktPreis, iAnzahl, iVersand, iMontage);
  } else if(iEinzelkomponente == 0){
    fPreis = printPreisAusgabeStandard(fProduktPreis, iAnzahl, iVersand, iMontage);
  }

  iSuccessfullInput = 0;

  do{
    printLineBreaks(2);
    printWhitespaces(MENU_INDENTATION_WHITESPACES);
    printf("In den Warenkorb (j/n)? ");

    fflush(stdin);
    iSuccessfullInput = scanf("%s", cWarenkorb);

    if(strcmp(cWarenkorb, cJa) == 0){
      fWarenkorb = fWarenkorb + fPreis;
      iWarenkorb = 1;
    } else if(strcmp(cWarenkorb, cNein) == 0){
      iWarenkorb = 0;
    } else{
      iWarenkorb = -1;
    }
  } while(iSuccessfullInput == 0 || iWarenkorb == -1);
}

/******************************************************************************
* Funktion:   printMenuMain
* Input:      -
* Output:     -
*
* Zeichnet das Hauptmenü
******************************************************************************/
void printMenuMain(void)
{
  clearScreen();

  printWarenkorbForMenu(32);// Warenkorb anzeigen

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

/******************************************************************************
* Funktion:   printMenuStandartkonfiguration
* Input:      -
* Output:     -
*
* Die Funktion gibt das Menü für die Standardkonfigurationen aus.
******************************************************************************/
void printMenuStandardkonfiguration(void)
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

/******************************************************************************
* Funktion:   printMenuEinzelkomponenten
* Input:      -
* Output:     -
*
* Die Funktion gibt das Menü für die Einzelkomponenten aus.
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
  printWhitespaces(9);
  printf("%7.2f Euro", PREIS_MAINBOARD);
  printLineBreaks(1);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("3: CPU");
  printWhitespaces(15);
  printf("%7.2f Euro", PREIS_CPU);
  printLineBreaks(1);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("4: Festplatte");
  printWhitespaces(8);
  printf("%7.2f Euro", PREIS_HDD);
  printLineBreaks(1);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("5: Grafikkarte");
  printWhitespaces(7);
  printf("%7.2f Euro", PREIS_GPU);
  printLineBreaks(1);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("0: Abbruch");
  printWhitespaces(11);
  printLineBreaks(1);
}

/******************************************************************************
* Funktion: printMenuGehaeuse
* Input:    -
* Output:   -
* Zeichnet das Gehäusemenü
******************************************************************************/
void printMenuGehaeuse(void){
  printWarenkorbForMenu(30);// Warenkorb anzeigen

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

/******************************************************************************
* Funktion: printMenuGehaeuse
* Input:    -
* Output:   -
* Zeichnet das Gehäusemenü
******************************************************************************/
float printPreisAusgabeStandard(
  float fPreisArtikel,
  int iAnzahlArtikel,
  int iVersand,
  int iMontage
){
  float fListenPreisGesamt = iAnzahlArtikel * fPreisArtikel,
    fLagerkosten = fListenPreisGesamt * MULTIPL_LAGER,
    fMaterialKosten = fListenPreisGesamt + fLagerkosten,
    fVerwaltungsKosten = fMaterialKosten * MULTIPL_VERWALTUNGS,
    fSelbstKosten = fMaterialKosten + fVerwaltungsKosten,
    fGewinn = fSelbstKosten * MULTIPL_GEWINN,
    fBarverkaufsPreis = fSelbstKosten + fGewinn,
    fVersandKosten = fBarverkaufsPreis * MULTIPL_VERSAND,
    fVersandPreis = fBarverkaufsPreis + fVersandKosten;

  clearScreen();

  // REchnungsausgabe
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
  printf("+ Lagerkosten");
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
  printf("+ Verwaltungskosten");
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
  printf("+ Gewinn");
  printWhitespaces(26);
  printf("%7.2f Euro", fGewinn);
  printLineBreaks(1);
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printLine(46);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("Barverkaufspreis:");
  printWhitespaces(17);
  printf("%7.2f Euro", fBarverkaufsPreis);
  printLineBreaks(1);

  if(iVersand == 1){
    printWhitespaces(MENU_INDENTATION_WHITESPACES);
    printf("+ Versandkosten");
    printWhitespaces(19);
    printf("%7.2f Euro", fVersandKosten);
    printLineBreaks(1);
    printWhitespaces(MENU_INDENTATION_WHITESPACES);
    printLine(46);
    printWhitespaces(MENU_INDENTATION_WHITESPACES);
    printf("Versandpreis:");
    printWhitespaces(21);
    printf("%7.2f Euro", fVersandPreis);
    return fVersandPreis;
  }
  return fBarverkaufsPreis;
}

/******************************************************************************
* Funktion: printPreisAusgabeEinzel
* Input:    fPreisArtikel, iAnzahlArtikel, iVersand, iMontage
* Output:   fBarverkaufspreis || fVersandpreis
* Gibt die Rechnung für die Einzelkomponenten aus
===============================================================================
*/
float printPreisAusgabeEinzel(
  float fPreisArtikel,
  int iAnzahlArtikel, 
  int iVersand, 
  int iMontage
){
  //Variablen der Kosten
  float fListenPreisGesamt = iAnzahlArtikel * fPreisArtikel,
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

  printWarenkorbForMenu(47);// Warenkorb anzeigen

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
  printWhitespaces(20);
  printf("%7.2f Euro", fLagerkosten);
  printLineBreaks(1);
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printLine(46);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("Materialkosten:");
  printWhitespaces(19);
  printf("%7.2f Euro", fMaterialKosten);
  printLineBreaks(1);

  //Es wird geprüft ob die Montage gewünscht ist und sie wird berechnet
  if(iMontage == 1){
    printWhitespaces(MENU_INDENTATION_WHITESPACES);
    printf("+ Fertigungskosten:");
    printWhitespaces(15);
    printf("%7.2f Euro", fFertigungsKosten);
    printLineBreaks(1);
    printWhitespaces(MENU_INDENTATION_WHITESPACES);
    printLine(46);

    printWhitespaces(MENU_INDENTATION_WHITESPACES);
    printf("Herstellungskosten:");
    printWhitespaces(15);
    printf("%7.2f Euro", fHerstellungsKosten);
    printLineBreaks(1);
  }

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("+ Verwaltungskosten:");
  printWhitespaces(14);
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
  printWhitespaces(25);
  printf("%7.2f Euro", fGewinnKosten);
  printLineBreaks(1);
  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printLine(46);

  printWhitespaces(MENU_INDENTATION_WHITESPACES);
  printf("Barverkaufspreis:");
  printWhitespaces(17);
  printf("%7.2f Euro", fBarverkaufsPreis);
  printLineBreaks(1);

  if(iVersand == 1){
    printWhitespaces(MENU_INDENTATION_WHITESPACES);
    printf("+ Versandkosten:");
    printWhitespaces(18);
    printf("%7.2f Euro", fVersandKosten);
    printLineBreaks(1);

    printWhitespaces(MENU_INDENTATION_WHITESPACES);
    printLine(46);

    printWhitespaces(MENU_INDENTATION_WHITESPACES);
    printf("Versandpreis:");
    printWhitespaces(21);
    printf("%7.2f Euro", fVersandPreis);
    return fVersandPreis;
  }
  return fBarverkaufsPreis;
}

/******************************************************************************
* Funktion: runMenuStandardkonfiguration
* Input:    -
* Output:   -
*
* Leert den Bildschirm und zeichnet dann das Standardkonfigurationsmenü. Es
* überprüft auch die Auswahl.
******************************************************************************/
void runMenuStandardkonfiguration(void){
  int iAuswahl = 5, iSuccessfullInput = 0;
  float fProduktPreis;

  do{
    clearScreen();

    printMenuStandardkonfiguration();

    printLineBreaks(1);

    printWhitespaces(MENU_INDENTATION_WHITESPACES);
    printf("Auswahl: ");
    fflush(stdin);
    iSuccessfullInput = scanf("%1i", &iAuswahl);
  } while(iSuccessfullInput == 0 || iAuswahl >= 5);

  switch(iAuswahl){
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
  addProductToCart(fProduktPreis, 0, 1, 0);
}
/******************************************************************************
* Funktion: clearScreen
* Input:    -
* Output:   -
*
* Leert den Bildschirm
******************************************************************************/
void clearScreen(void){
  system("cls");
}

/******************************************************************************
* Funktion:   printTabs
* Input:      int iTabs
* Output:     -
*
* Die Funktion gibt die als Parameter übergebene Anzahl an Tabs aus. ("\t").
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
* Die Funktion gibt die als Paramter übergebene Anzahl an Whitespaces aus.
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
* Die Funktion gibt den Warenkorb am rechten Rand des Menüs aus.
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
* Die Funktion gibt die als Parameter übergebene Anzahl an Linebreaks aus.("\n")
******************************************************************************/
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
* Die Funktion gibt eine Linie, bestehend aus "=", mit der Länge iLength aus.
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