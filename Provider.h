#ifndef PROVIDER_H
#define PROVIDER_H

#include <string>
#include <queue>
#include <vector>

struct Equipment {
    int football_kit;
    int balls;
    int football_boots;
    int cones;
    int goal;
    int tactics_board;
    int medical_kit;
    int water_bottles;
};

class Provider {

private:

    std::string name;
    double reputation;
    Equipment equipment;

public:

    Provider() {}
    Provider(std::string name, double reputation, Equipment equipment);
    
    void showInfo() const;

    std::string getName() const;
    void setName(std::string n);
    
    double getReputation() const;
    void setReputation(double rate);

    vector<int> getEquipment() const;
    void setEquipment(int nballs, int ncones, int nfootball_boots, int nfootball_kit, int ngoal, int nmedical_kit, int ntactics_board, int nwater_bottles);

    bool operator < (const Provider &p) const;
    bool operator == (const Provider &p) const;
};

class ProviderPriorityQueue {

private:

    priority_queue<Provider> provider;

public:

    ProviderPriorityQueue() {};
    
    void addProvider(Provider &p);
    void removeProvider(Provider p);

    vector<Provider> searchName(std::string name);
    vector<Provider> searchReputation(double rep);
    vector<Provider> searchEquipment(int item);

    void updateName(Provider p, std::string name);
    void updateReputation(Provider p, double rep);
    void updateEquipmentItem(Provider p, int item);
    void updateEquipmentAll(Provider p, vector<int> new_equip);
    
    void print() const;

};

#endif


