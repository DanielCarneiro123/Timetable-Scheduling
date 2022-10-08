#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ostream>

using namespace std;

//inicializar as classes para representar cada ficheiro .csv

struct classesStruct{
    string ClassCode;
    string UcCode;
    string Weekday;
    int StartHour;
    int Duration;
    string Type;
};

struct classesPerUcStruct{
    string UcCode;
    string ClassCode;
};

struct StudentsClassesStruct{
    string StudentCode;
    string StudentName;
    string UcCode;
    string ClassCode;
};


int main() {
    ifstream myFile;
    string CurrentLine="";   // string usada para ler os ficheiros

    //Passar ficheiro Classes para vetor ArrClasses

    vector<classesStruct> ArrClasses;
    classesStruct classe;

    myFile.open("C:/Users/utilizador/TrabalhoAED/classes.csv");
    getline(myFile,CurrentLine);
    string tempClassString; // string criada para poder copiar ints como classes.StartHour e classe.Duration para uma string

    while(getline(myFile,CurrentLine)) {
        stringstream inputString(CurrentLine);
        getline(inputString, classe.ClassCode, ',');
       getline(inputString, classe.UcCode, ',');
       getline(inputString, classe.Weekday, ',');

       getline(inputString, tempClassString, ',');
       classe.StartHour=atoi(tempClassString.c_str());

       tempClassString="";
       getline(inputString, tempClassString, ',');
       classe.Duration=atoi(tempClassString.c_str());

       getline(inputString,classe.Type,',');

       ArrClasses.push_back(classe);

       CurrentLine = "";
   }
    
    myFile.close();
    CurrentLine = "";

    //Passar ficheiro ClassesPerUc para vetor ArrClassesPerUc
    
    vector<classesPerUcStruct> ArrClassesPerUc;
    classesPerUcStruct classPerUc;

    myFile.open("C:/Users/utilizador/TrabalhoAED/classes_per_uc.csv");
    getline(myFile,CurrentLine);
    while(getline(myFile,CurrentLine)) {
        stringstream inputString(CurrentLine);
        getline(inputString, classPerUc.UcCode, ',');
        getline(inputString, classPerUc.ClassCode, ',');
        ArrClassesPerUc.push_back(classPerUc);

        CurrentLine= "";
    }
    
    myFile.close();
    CurrentLine = "";

    //Passar ficheiro StudentsClasses para vetor ArrStudentsClasses

    vector<StudentsClassesStruct> ArrStudentsClasses;
    StudentsClassesStruct studentClasses;

    myFile.open("C:/Users/utilizador/TrabalhoAED/students_classes.csv");
    getline(myFile,CurrentLine);

    while(getline(myFile,CurrentLine)) {
        stringstream inputString(CurrentLine);
        getline(inputString, studentClasses.StudentCode, ',');
        getline(inputString, studentClasses.StudentName, ',');
        getline(inputString, studentClasses.UcCode, ',');
        getline(inputString, studentClasses.ClassCode, ',');
        ArrStudentsClasses.push_back(studentClasses);

        CurrentLine= "";
    }
    /* -----TESTING-------
    for (auto x:ArrStudentsClasses){
        cout << x.StudentName << endl;

    }
     */


}
