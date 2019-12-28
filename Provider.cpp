#include "Provider.h"
#include "iostream"

using namespace std;

// Provider Functions

Provider::Provider(std::string name, double reputation, Equipment equipment): name(name), reputation(reputation) {
    equipment.balls = 0;
    equipment.cones = 0;
    equipment.football_boots = 0;
    equipment.football_kit = 0;
    equipment.goal = 0;
    equipment.medical_kit = 0;
    equipment.tactics_board = 0;
    equipment.water_bottles = 0;
}

void Provider::showInfo() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Reputation: " << reputation << std::endl;
    std::cout << "Balls: " << equipment.balls << std::endl;
    std::cout << "Cones: " << equipment.cones << std::endl;
    std::cout << "Football Boots: " << equipment.football_boots << std::endl;
    std::cout << "Football Kit: " << equipment.football_kit << std::endl;
    std::cout << "Goal: " << equipment.goal << std::endl;
    std::cout << "Medical Kit: " << equipment.medical_kit << std::endl;
    std::cout << "Tactics Board: " << equipment.tactics_board << std::endl;
    std::cout << "Water Bottles: " << equipment.water_bottles << std::endl;
}

string Provider::getName() const {
    return name;
}

void Provider::setName(string n) {
    this->name = n;
}

double Provider::getReputation() const {
    return reputation;
}

void Provider::setReputation(double rate) {
    this->reputation = rate;
}

Equipment Provider::getEquipment() const {
    return equipment;
}

void Provider::setEquipment(int nballs, int ncones, int nfootball_boots, int nfootball_kit, int ngoal, int nmedical_kit, int ntactics_board, int nwater_bottles) {
    this->equipment.balls = nballs;
    this->equipment.cones = ncones;
    this->equipment.football_boots = nfootball_boots;
    this->equipment.football_kit = nfootball_kit;
    this->equipment.goal = ngoal;
    this->equipment.medical_kit = nmedical_kit;
    this->equipment.tactics_board = ntactics_board;
    this->equipment.water_bottles = nwater_bottles;
}

void Provider::setEquipment(int item, int new_value) {
    switch (item) {
        case 1:
            this->equipment.football_kit = new_value;
            break;
        case 2:
            this->equipment.balls = new_value;
            break;
        case 3:
            this->equipment.football_boots = new_value;
            break;
        case 4:
            this->equipment.cones = new_value;
            break;
        case 5:
            this->equipment.goal = new_value;
            break;
        case 6:
            this->equipment.tactics_board = new_value;
        case 7:
            this->equipment.medical_kit = new_value;
            break;
        case 8:
            this->equipment.water_bottles = new_value;
            break;
    }
}

bool Provider::operator<(const Provider &p) const {
    return reputation < p.reputation;
}

bool Provider::operator==(const Provider &p) const {
    return reputation == p.reputation;
}

bool Provider::operator!=(const Provider &p) const {
    return reputation != p.reputation;
}

// ProviderPriorityQueue Functions

void ProviderPriorityQueue::addProvider(Provider &p) {
    provider.push(p);
}

void ProviderPriorityQueue::removeProvider(Provider p) {
    vector<Provider> auxiliar;
    Provider prov_auxiliar;

    while (!provider.empty()) {
        prov_auxiliar = provider.top();
        provider.pop();
        if (prov_auxiliar != p) {
            auxiliar.push_back(prov_auxiliar);
        }
    }

    for (int i = 0; i < auxiliar.size(); i++) {
        provider.push(auxiliar[i]);
    }

}

vector<Provider> ProviderPriorityQueue::searchName(std::string name) {
    vector<Provider> to_return;
    vector<Provider> auxiliar;

    while(!provider.empty()) {
        auxiliar.push_back(provider.top());
        if (provider.top().getName() == name) { to_return.push_back(provider.top()); }
        provider.pop();
    }

    for (int i = 0; i < auxiliar.size(); i++) {
        provider.push(auxiliar[i]);
    }

    return to_return;
}

vector<Provider> ProviderPriorityQueue::searchReputation(double rep) {
    vector<Provider> to_return;
    vector<Provider> auxiliar;

    while(!provider.empty()) {
        auxiliar.push_back(provider.top());
        if (provider.top().getReputation() >= rep) { to_return.push_back(provider.top()); }
        provider.pop();
    }

    for (int i = 0; i < auxiliar.size(); i++) {
        provider.push(auxiliar[i]);
    }

    return to_return;
}

vector<Provider> ProviderPriorityQueue::searchEquipment(int item) {
    vector<Provider> to_return;
    vector<Provider> auxiliar;

    while(!provider.empty()) {
        auxiliar.push_back(provider.top());
        switch (item) {
        case 1:
            if (provider.top().getEquipment().football_kit != 0) {
                to_return.push_back(provider.top());
            }
            break;
        case 2:
            if (provider.top().getEquipment().balls != 0) {
                to_return.push_back(provider.top());
            }
            break;
        case 3:
            if (provider.top().getEquipment().football_boots != 0) {
                to_return.push_back(provider.top());
            }
            break;
        case 4:
            if (provider.top().getEquipment().cones != 0) {
                to_return.push_back(provider.top());
            }
            break;
        case 5:
            if (provider.top().getEquipment().goal != 0) {
                to_return.push_back(provider.top());
            }
            break;
        case 6:
            if (provider.top().getEquipment().tactics_board != 0) {
                to_return.push_back(provider.top());
            }
            break;
        case 7:
            if (provider.top().getEquipment().medical_kit != 0) {
                to_return.push_back(provider.top());
            }
            break;
        case 8:
            if (provider.top().getEquipment().water_bottles != 0) {
                to_return.push_back(provider.top());
            }
            break;
        default:
            break;
        }
        provider.pop();
    }

    for (int i = 0; i < auxiliar.size(); i++) {
        provider.push(auxiliar[i]);
    }

    return to_return;
}

void ProviderPriorityQueue::updateName(Provider p, std::string name) {
    vector<Provider> auxiliar;
    Provider aux;

    while(!provider.empty()) {
        aux = provider.top();
        if (provider.top() == p) { aux.setName(name); }
        auxiliar.push_back(aux);
        provider.pop();
    }

    for (int i = 0; i < auxiliar.size(); i++) {
        provider.push(auxiliar[i]);
    }

}

void ProviderPriorityQueue::updateReputation(Provider p, double rep) {
    vector<Provider> auxiliar;
    Provider aux;

    while(!provider.empty()) {
        aux = provider.top();
        if (provider.top() == p) { aux.setReputation(rep); }
        auxiliar.push_back(aux);
        provider.pop();
    }

    for (int i = 0; i < auxiliar.size(); i++) {
        provider.push(auxiliar[i]);
    }

}

void ProviderPriorityQueue::updateEquipmentItem(Provider p, int item, int new_value) {
    vector<Provider> auxiliar;
    Provider aux;
    while(!provider.empty()) {
        aux = provider.top();
        if (aux == p) { aux.setEquipment(item, new_value); }
        auxiliar.push_back(aux);
        provider.pop();
    }

    for (int i = 0; i < auxiliar.size(); i++) {
        provider.push(auxiliar[i]);
    }

}

void ProviderPriorityQueue::updateEquipmentAll(Provider p, Equipment new_equip) {
     vector<Provider> auxiliar;
     Provider aux;

    while(!provider.empty()) {
        aux = provider.top();
        if (aux == p) { aux.setEquipment(new_equip.balls, new_equip.cones, new_equip.football_boots, new_equip.football_kit, new_equip.goal, new_equip.medical_kit, new_equip.tactics_board, new_equip.water_bottles); }
        auxiliar.push_back(aux);
        provider.pop();
    }

    for (int i = 0; i < auxiliar.size(); i++) {
        provider.push(auxiliar[i]);
    }

}
    
void ProviderPriorityQueue::print() const {
    priority_queue<Provider> aux = provider;
    while(!aux.empty()) {
        aux.top().showInfo();
        cout << endl
             << "-----------------------------------" << endl
             << endl;
        aux.pop();
    }

}