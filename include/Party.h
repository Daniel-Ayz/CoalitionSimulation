#pragma once
#include <string>

#include <iostream>
#include <vector>
using namespace std;

using std::string;

class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 

    State getState() const;
    void setState(State state);
    int getMandates() const;
    int getId() const;
    void step(Simulation &s);
    const string &getName() const;
    void addOffer(int coalitionId);
    bool hasOffer(int coalitionId) const;
    int getTicks();
    void addTicks();
    void setCoalition(int coalitionId);
    //rule of 5
    Party(const Party& other);
    ~Party();
    Party& operator=(const Party& other);
    Party(Party&& other);
    Party& operator=(Party&& other);
private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    std::vector<int> offers;
    int CoalitionId;
    int ticks;
};
