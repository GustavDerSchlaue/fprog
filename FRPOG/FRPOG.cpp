// FRPOG.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <vector>
#include <sys/types.h>
#include <fstream>
#include "dirent.h"
#include <sstream>
#include <algorithm>

struct wordstruct {
    std::string word;
    int count;
};

auto CountWordsinFile = [](const std::string content)
{
    std::vector<wordstruct> vec;
    std::string clearedstring;

    //remove special characters
    for (int i = 0; i < content.size(); ++i)
    {
        if ((content[i] >= 'a' && content[i] <= 'z') || (content[i] >= 'A' && content[i] <= 'Z') || content[i] == ' ') //initializing condition  
        {
            clearedstring = clearedstring + content[i];//passing characters that match condition to temp string from initialized string
        }
    }


    //count words
    std::istringstream iss(clearedstring);
    std::string buffer;
    while (iss >> buffer) {
        if (vec.size() == 0)
        {
            wordstruct wordstruct;
            wordstruct.word = buffer;
            wordstruct.count = 1;
            vec.push_back(wordstruct);
        }
        else {
            for (int i = 0; i < vec.size(); i++)
            {
                if (vec[i].word == buffer) {

                    vec[i].count = vec[i].count + 1;
                    break;
                }
                else if (i + 1 >= vec.size()) {
                    wordstruct wordstruct;
                    wordstruct.word = buffer;
                    wordstruct.count = 0;
                    vec.push_back(wordstruct);
                }
            }
        }
    }
    return vec;
};

auto CombineVectors = [](const std::vector<std::vector<wordstruct>> vec) {
    std::vector<wordstruct> finalvec;
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++)
            if (finalvec.size() == 0)
            {
                wordstruct wordstruct;
                wordstruct.word = vec[i][j].word;
                wordstruct.count = vec[i][j].count;
                finalvec.push_back(wordstruct);
            }
            else {
                bool found = false;
                for (int k = 0; k < finalvec.size(); k++)
                {
                    if (finalvec[k].word == vec[i][j].word)
                    {
                        finalvec[k].count = finalvec[k].count + vec[i][j].count;
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    wordstruct wordstruct;
                    wordstruct.word = vec[i][j].word;
                    wordstruct.count = vec[i][j].count;
                    finalvec.push_back(wordstruct);
                }
            }
    }
    return finalvec;
};

auto CountWords= [](const std::string dir, const std::string filetyp) {
    std::vector<wordstruct> vec;
    std::vector<std::vector<wordstruct>> vecofvecs;
    char dirchar[100000];
    strcpy_s(dirchar, dir.c_str());
    DIR* dr;
    struct dirent* en;
    std::ifstream myfile;
    dr = opendir(dirchar); //open all directory
    if (dr) {
        while ((en = readdir(dr)) != NULL) {
            std::string nameoffile;
            for (int x = 0; x < 261; x++) {
                nameoffile = nameoffile + en->d_name[x];
            }
            if (nameoffile.find(filetyp) != std::string::npos) {
                myfile.open(dir + "\\" + en->d_name);
                if(myfile.is_open()){
                    std::cout << dir + "\\" + en->d_name;
                    std::string content((std::istreambuf_iterator<char>(myfile)),
                                        (std::istreambuf_iterator<char>()));
                    vecofvecs.push_back(CountWordsinFile(content));
                    myfile.close();
                }

            }
        }
        closedir(dr); //close all directory
    }

    vec = CombineVectors(vecofvecs);

    return vec;
};

// used to print the vector
// For debugging
auto printvector = [](std::vector<wordstruct> vec)
{
    std::string string;
    for (int i = 0; i < vec.size(); i++)
    {

        string = string + "Word: " + vec[i].word + " \tCount: " + std::to_string(vec[i].count) + "\n";

    }
    std::cout << "\n\n";
    return string;
};

//used in sort
bool compareByLength(wordstruct &a, wordstruct &b)
{
    return a.count > b.count;
}

// Sorted vector
auto sortVector = [](const std::vector<wordstruct> &vec){
    std::vector<wordstruct> sorted_vec = vec;

    std::sort(sorted_vec.begin(), sorted_vec.end(), compareByLength);

    return sorted_vec;
};

int main(int argc, char** argv) {
    std::string directory;
    std::string filetyp;
    std::vector<wordstruct> vec;

    if(argc == 3 ){
        directory = argv[1];
        filetyp = argv[2];
    }else{
        std::cout << "Insert path: ";
        std::cin >> directory;

        std::cout << "Insert extension:";
        std::cin >> filetyp;
    }



    vec = CountWords(directory, filetyp);

    vec = sortVector(vec);
    std::string displayVector = printvector(vec);

    std::cout << displayVector;

}






















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

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
