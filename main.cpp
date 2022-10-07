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


int main() {
    vector<classesStruct> ArrClasses;
    classesStruct classe;
   ifstream myFile;
   myFile.open("C:/Users/utilizador/TrabalhoAED/classes.csv");
    string line="";
    getline(myFile,line);
    string tempString;
   while(getline(myFile,line)) {
        stringstream inputString(line);
        getline(inputString, classe.ClassCode, ',');
       getline(inputString, classe.UcCode, ',');
       getline(inputString, classe.Weekday, ',');

       getline(inputString, tempString, ',');
       classe.StartHour=atoi(tempString.c_str());

       tempString="";
       getline(inputString, tempString, ',');
       classe.Duration=atoi(tempString.c_str());

       getline(inputString,classe.Type,',');

       ArrClasses.push_back(classe);

       line = "";
   }
   for (auto x:ArrClasses){
       cout << x.UcCode << endl;

   }}
