#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ostream>
#include <algorithm>
#include <cstring>

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

///funcao para comparares strings
bool strcomp0(string a, string b){
    return a<b;
}

bool strcomp1(string a, string b) {
    return a > b;
}

bool intcomp(classesStruct a, classesStruct b){
    return a.StartHour<b.StartHour;}


///Numero de estudantes numa turma x (Ocuupação da turma)

void ocupacaoTurma(const string cadeira, string turma, const vector<StudentsClassesStruct>& arr){
    int acc=0;
    for (const auto& x:arr){
        int i = x.UcCode.compare(cadeira);
        int j = x.ClassCode.compare(turma);
        if (i==0 && j==0){
            acc++;
        }
    }

    cout << "Number of people in class " << turma << " for UC " << cadeira << ": " << acc;
}

void ocupacaoUcsAno(const vector<StudentsClassesStruct>& arr, char ano){
    vector<string> v;
    for (const auto& x: arr){
        if(x.ClassCode.at(0) == ano && !(find(v.begin(), v.end(), x.StudentName) != v.end())){
            v.push_back(x.StudentName);
        }}
    int acc=0;
    for (auto x: v) acc++;
    cout << "Number of people attending UCs belonging to ano " << ano << ": " << acc;
}
///Número de estudantes numa UC x (Ocupação UC)

void ocupacaoUc(const vector<StudentsClassesStruct>& arr, string cadeira){
    int sum = 0;
    for (const auto& x: arr){
        int i = x.UcCode.compare(cadeira);
        if (i == 0){
            sum++;
        }
    }
    cout << "Number of students in UC " << cadeira << ": " << sum;
}

///Estudantes em determinada turma x

void estudantesTurma(const vector<StudentsClassesStruct>& arr, string turma){
    string sep = ":";
    vector<string> names;
    cout << "The students that belong to class " << turma << " are";
    for (const auto& x: arr){
        if (x.ClassCode.compare(turma) == 0){
            names.push_back(x.StudentName);
        }
    }
    sort(names.begin(), names.end(), strcomp1);
    for (const auto& n: names){
        cout << sep << " " << n;
        sep = ",";
    }
    cout << ".";
}

void estudantesEmUcsAno(const vector<StudentsClassesStruct>& arr, char ano){
    string sep = ":";
    vector<string> v;
    for (const auto& x: arr){
        if(x.ClassCode.at(0) == ano && !(find(v.begin(), v.end(), x.StudentName) != v.end())){
            v.push_back(x.StudentName);
        }

    }
    sort(v.begin(), v.end(), strcomp1);
    cout << "The students that are attending UCs belonging to year " << ano << " are";
    for (auto x : v){
        cout << sep << " " << x;
        sep = ",";

    }
    cout << ".";

}
void todasUcs(const vector<classesPerUcStruct>& arr){
    string sep = ":";
    vector<string> v;
    for (const auto& x: arr){
        if (!(find(v.begin(), v.end(), x.UcCode) != v.end())){
            v.push_back(x.UcCode);
        }

    }
    cout << "Todas as UCs são: ";
    for (auto x: v){
        cout << x << " ";

    }

}

///Estudantes em determinada UC x
void estudantesUC(const vector<StudentsClassesStruct>& arr, string cadeira){
    string sep = ":";
    vector<string> v;
    cout << "The students that are attending UC " << cadeira << " are";
    for (const auto& x: arr){
        if (x.UcCode.compare(cadeira) == 0){
            v.push_back(x.StudentName);
        }
    }
    sort(v.begin(), v.end(), strcomp1);
    for (const auto& n: v){
        cout << sep << " " << n;
        sep = ",";
    }
    cout << ".";
}



///Horário de determinado estudante

void horarioEstudante(const vector<StudentsClassesStruct>& arr1, const vector<classesStruct>& arr2, string nomeEstudante) {
    string turmaAtual;
    string cadeiraAtual;
    vector<classesStruct> v1;
    vector<classesStruct> v2;
    vector<classesStruct> v3;
    vector<classesStruct> v4;
    vector<classesStruct> v5;
    for (auto x: arr1) {
        if (x.StudentName.compare(nomeEstudante) == 0) {
            turmaAtual = x.ClassCode;
            cadeiraAtual = x.UcCode;
            for (auto y: arr2) {
                int n1 = y.ClassCode.compare(turmaAtual);
                int n2 = y.UcCode.compare(cadeiraAtual);
                if (n1 == 0 && n2 == 0) {
                    if (y.Weekday.compare("Monday") == 0) {
                        v1.push_back(y);
                        sort(v1.begin(), v1.end(), intcomp);
                    }
                    if (y.Weekday.compare("Tuesday") == 0) {
                        v2.push_back(y);
                        sort(v2.begin(), v2.end(), intcomp);
                    }
                    if (y.Weekday.compare("Wednesday") == 0) {
                        v3.push_back(y);
                        sort(v3.begin(), v3.end(), intcomp);
                    }
                    if (y.Weekday.compare("Thursday") == 0) {
                        v4.push_back(y);
                        sort(v4.begin(), v4.end(), intcomp);
                    }
                    if (y.Weekday.compare("Friday") == 0) {
                        v5.push_back(y);
                        sort(v5.begin(), v5.end(), intcomp);
                    }

                }

            }
        }

    }
    if (v1.size() + v2.size() + v3.size()+v4.size()+v5.size()==0) cout << "There is no student with the name " << nomeEstudante << ".";

    for (const auto &n: v1) {
        cout << nomeEstudante << " has a " << n.Type << " class for UC " << n.UcCode << " from "
             << n.StartHour << " to " << n.StartHour + n.Duration << " on " << n.Weekday << endl;
    }
    for (const auto &n: v2) {
        cout << nomeEstudante << " has a " << n.Type << " class for UC " << n.UcCode << " from "
             << n.StartHour << " to " << n.StartHour + n.Duration << " on " << n.Weekday << endl;
    }
    for (const auto &n: v3) {
        cout << nomeEstudante << " has a " << n.Type << " class for UC " << n.UcCode << " from "
             << n.StartHour << " to " << n.StartHour + n.Duration << " on " << n.Weekday << endl;
    }
    for (const auto &n: v4) {
        cout << nomeEstudante << " has a " << n.Type << " class for UC " << n.UcCode << " from "
             << n.StartHour << " to " << n.StartHour + n.Duration << " on " << n.Weekday << endl;
    }
    for (const auto &n: v5) {
        cout << nomeEstudante << " has a " << n.Type << " class for UC " << n.UcCode << " from "
             << n.StartHour << " to " << n.StartHour + n.Duration << " on " << n.Weekday << endl;
    }
}



int main() {
    ifstream myFile;
    string CurrentLine;   // string usada para ler os ficheiros

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

    //estudantesUC(ArrStudentsClasses,"L.EIC002");
    //estudantesTurma(ArrStudentsClasses, "1LEIC05");
    //ocupacaoTurma("L.EIC002","1LEIC14",ArrStudentsClasses);
    //ocupacaoUc(ArrStudentsClasses, "L.EIC021");
    //horarioEstudante(ArrStudentsClasses,ArrClasses, "ZezinhoDoBonezinho");
    //estudantesEmUcsAno(ArrStudentsClasses, '1');
    //ocupacaoUcsAno(ArrStudentsClasses,'1');
    todasUcs(ArrClassesPerUc);
}