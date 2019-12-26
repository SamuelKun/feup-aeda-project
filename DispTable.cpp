#include "DispTable.h"
#include "algorithm"


bool CompareStaff(Staff s1, Staff s2){
    return s1.getName() == s2.getName();
}
DispTable::DispTable(vector<Staff> v) {
    auto it = v.begin();

    for(size_t i = 0; i < v.size();i++){
        staff_members.insert(v[i]);
        v_atuais.push_back(v[i]);
    }
}

void DispTable::addStaff(Staff s) {
    staff_members.insert(s);
    v_atuais.push_back(s);
}

DispTable::DispTable(Staff s) {
    staff_members.insert(s);
}

void DispTable::removeStaff(Staff s) {
    auto it = staff_members.find(s);
    if(it != staff_members.end()){
        staff_members.erase(it);
        auto iter = find(v_atuais.begin(),v_atuais.end(),s);
        v_antigos.push_back(s);
        v_atuais.erase(iter);
    }
}

const vector<Staff> &DispTable::getVAtuais() const {
    return v_atuais;
}

const vector<Staff> &DispTable::getVAntigos() const {
    return v_antigos;
}

Staff DispTable::findStaff(Staff s) const {
    if (staff_members.find(s) != staff_members.end()){
        return (*staff_members.find(s));
    }
    else throw StaffNotFound(s.getName());
}
