#pragma once

#include <vector>
#include "Graph.h"

class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);

    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    void setCoalition(int coalitionId);
    void setAgentId(int agentId);
    void setPartyId(int partyId);
    int getCoalitionId();
    //rule of 5
    Agent(const Agent& other);
    Agent(Agent&& other);
    ~Agent();
    Agent& operator=(const Agent& other);
    Agent& operator=(Agent&& other);

private:
    int mAgentId;
    int mPartyId;
    int mCoalitionId;
    SelectionPolicy *mSelectionPolicy;
};
