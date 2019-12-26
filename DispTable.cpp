#include "DispTable.h"
#include "algorithm"


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
    v_atuais.push_back(s);
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

vector<Staff> DispTable::findStaff(string name) const {
    vector<Staff> v;
    for (const auto& stf : staff_members){
        if( stf.getName().find(name)) v.push_back(stf);
    }
    if(v.empty()) throw StaffNotFound(name);
    else return v;
}

const tabH &DispTable::getStaffMembers() const {
    return staff_members;
}
