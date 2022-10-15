#include <string>
using namespace std;
#ifndef UNTITLED_CLASSESCLASS_H
#define UNTITLED_CLASSESCLASS_H


class classesClass {
public:
    string ClassCode;
    string UcCode;
    string Weekday;
    int StartHour{};
    int Duration{};
    string Type;
    static bool intcomp(classesClass a, classesClass b);
};


#endif //UNTITLED_CLASSESCLASS_H
