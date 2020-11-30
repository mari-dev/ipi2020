
// Kompilieren zum Beispiel mit g++ -o primzahlen primzahlen.cc  
// dann von der Kommandozeile ./primzahlen mit oder ohne Argument, siehe unten

#include "fcpp.hh"

// #include "name" sucht die Datei name im aktuellen Verzeichnis.
// #include <name> sucht die Datei name in einem speziellen Verzeichnis mit Standardateien.

// Ist zahl Primzahl? 
// Der Wert des formalen Parameters index wird beim Aufruf gleich 2 gesetzt, 
// dem kleinsten relevanten Teiler

bool primzahl (int index, int zahl) {
  return cond(zahl<=1, 0, cond(index * index >zahl,1, 
                               cond(zahl%index, primzahl(index+1, zahl),0)));
}

// Wieviel Primzahlen kleiner oder gleich zahl gibt es? 
// Die Werte der formalen Parameter index und summe werden beim Aufruf auf 0 gesetzt.

int primzahlanzahl (int index, int anzahl, int zahl) {
  return cond(index>=zahl+1, anzahl,
               primzahlanzahl(index+1, summe+ cond(primzahl(2, index), 1, 0), zahl));
           //  primzahlanzahl(index+1, anzahl+ (int) primzahl(2, index), zahl));
}


// Suche die kleinste Primzahl größer oder gleich Index. 
int sucheprimzahl (int index) {
  return cond(primzahl(2, index), index, sucheprimzahl(index+1));
}

int main(int argc, char *argv[]) {
// return(print(primzahl(2, 17))); // Ergebnis 1, da 17 Primzahl ist.
// return(print(primzahlanzahl(0,0,10))); // Ergebnis 4, Primzahlen 2, 3, 5 und 7 kleiner 10.
// return(print(sucheprimzahl(14))); // Ergebnis 17, die kleinste Primzahl >= 14.
  
// return(print(primzahl(2,readarg_int(argc,argv,1)))); 
// return(print(primzahlanzahl(0,0,readarg_int(argc,argv,1)))); 
  return(print(sucheprimzahl(readarg_int(argc,argv,1)))); 
}
/*  Die Aufrufe oben können zum Testen der Funktionen verwendet werden.
Die ersten drei haben feste Werte für die Parameter.
Die letzten drei leses einen Wert von der Kommandozeile ein: 
mit nicht auskommentierter vorletzter Zeile ergibt ./primzahlen 14 die Ausgabe 17.
*/   

/* Zur Verwendung des Operators cond in der Funktion primzahl.
Werte vom Typ integer werden automatisch in Werte vom Typ bool konvertiert, 
wenn sie entsprechen verwendet werden, der Wert x wird zur Negation von x==0.
Ein Wert b vom Typ bool wird nicht unbedingt in die Zahl 0 beziehungweise 1 
konvertiert, wenn der Wert entsprechend verwendet wird, zum Beispiel als b*x. 
Die Zahl b*x ergibt sich aber zum Beispiel als Wert des Ausdrucks cond(b,x,0). 
Alternativ und etwas einfacher kann 
primzahlanzahl(index+1, summe+ cond(primzahl(2, index), 1, 0), zahl)
durch 
primzahlanzahl(index+1, summe+ (int) primzahl(2, index), zahl))
ersetzt werden, (int) bewirkt eine explizite Typkonversion.
*/