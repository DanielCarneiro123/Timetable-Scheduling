#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ostream>

using namespace std;

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


int main() {
    //Passar ficheiro Classes para vetor ArrClasses
    vector<classesStruct> ArrClasses;
    classesStruct classe;
   ifstream ClassFile;
   ClassFile.open("C:/Users/utilizador/TrabalhoAED/classes.csv");
    string ClassLine="";
    getline(ClassFile,ClassLine);
    string tempClassString;
   while(getline(ClassFile,ClassLine)) {
        stringstream inputString(ClassLine);
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

       ClassLine = "";
   }
    //Passar ficheiro ClassesPerUc para vetor ArrClassesPerUc
    vector<classesPerUcStruct> ArrClassesPerUc;
    classesPerUcStruct classPerUc;
    ifstream ClassPerUcFile;

    ClassPerUcFile.open("C:/Users/utilizador/TrabalhoAED/classes_per_uc.csv");
    string ClassPerUcLine="";
    getline(ClassPerUcFile,ClassPerUcLine);
    while(getline(ClassPerUcFile,ClassPerUcLine)) {
        stringstream inputString(ClassPerUcLine);
        getline(inputString, classPerUc.UcCode, ',');
        getline(inputString, classPerUc.ClassCode, ',');
        ArrClassesPerUc.push_back(classPerUc);

        ClassPerUcLine= "";
    }
    /* testing
    for (auto x:ArrClassesPerUc){
        cout << x.UcCode << endl;

    }*/

}
