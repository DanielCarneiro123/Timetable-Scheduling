#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ostream>

using namespace std;

/// *Parsing* do ficheiro classes.csv nos seus cinco atributos
///
/// This is the Complete Description
struct classesStruct{
    string ClassCode;
    string UcCode;
    string Weekday;
    int StartHour{};
    int Duration{};
    string Type;
};

/// *Parsing* do ficheiro classes_per_uc.csv nos seus dois atributos.
///
/// This is the Complete Description
struct classesPerUcStruct{
    string UcCode;
    string ClassCode;
};

/// *Parsing* do ficheiro student_classes.csv nos seus quatro atributos.
///
/// This is the Complete Description
struct StudentsClassesStruct{
    string StudentCode;
    string StudentName;
    string UcCode;
    string ClassCode;
};


int func(const string& cadeira, const string& turma, const vector<StudentsClassesStruct>& arr){
    int acc=0;
    for (const auto& x:arr){
        int i = x.UcCode.compare(cadeira);
        if (i==0){
            acc++;
        }
    }

    cout << "Todas as strings analisadas";
    return acc;}


int main() {
    ifstream myFile;
    string CurrentLine;   // string usada para ler os ficheiros

    //Passar ficheiro Classes para vetor ArrClasses

    vector<classesStruct> ArrClasses;
    classesStruct classe;

    myFile.open("/Users/goncalocosta/Downloads/schedule/classes.csv");
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

    myFile.open("/Users/goncalocosta/Downloads/schedule/classes_per_uc.csv");
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

    myFile.open("/Users/goncalocosta/Downloads/schedule/students_classes.csv");
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
    int acc = func("L.EIC002","1LEIC05",ArrStudentsClasses);
    cout << acc <<endl;
}