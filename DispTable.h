#ifndef FEUP_AEDA_PROJECT_DISPTABLE_H
#define FEUP_AEDA_PROJECT_DISPTABLE_H

#include "Staff.h"
#include <vector>
#include <unordered_set>
using namespace std;

struct hashing {
    int operator()(const Staff & s) const {
        //Função de hash, redefinir mais tarde
        return s.getName().size();
    }
};
struct equall{
    bool operator() (const Staff& s1, const Staff& s2) const
    {
        return s1.getName() == s2.getName();
    }
};

typedef unordered_set<Staff, hashing, equall> tabH;

class DispTable{
private:
    tabH staff_members;
    vector<Staff> v_atuais;
    vector<Staff> v_antigos;

public:
    DispTable(vector<Staff> v);
    DispTable(Staff s);
    void addStaff(Staff s);
    void removeStaff(Staff s);
    Staff findStaff(Staff s) const ;

    const vector<Staff> &getVAtuais() const;
    const vector<Staff> &getVAntigos() const;
};


class StaffNotFound{
    std::string name;
public:
    StaffNotFound(std::string name): name(name){};
    std::string getName()const {return name;}
};

#endif //FEUP_AEDA_PROJECT_DISPTABLE_H