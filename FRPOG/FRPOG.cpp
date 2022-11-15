// FRPOG.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";

    /*
        struct word(
            string word
            int numb
        ) 
        Vector<Vector<word>>
        Vector<word>
    
    
        1. vector open directory (path, type)
            opens directory
            saves all correct files in vector
            for each file opens 
                2. vector look for word(string)
                    removes all , and ; from string
                    goes through and checks for sepereation by " " and "\n"
                    saves new words in vector of structs
                        struct{
                            string word
                            int number
                        }
                    returns vector
            saves for each file the vector in a new vector(vecofvecs)
            creates new vector
            vector = count(vecofvecs)   returns a new vector of struct where all vector where counted
    */

}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
