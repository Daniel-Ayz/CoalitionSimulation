#pragma once


#include <iostream>
#include <vector>
using namespace std;

#include "Graph.h"
#include "Agent.h"

class Coalition;

using std::string;

class Simulation
{
public:
    Simulation(Graph g, std::vector<Agent> agents);

    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const std::vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    Party &getParty(int partyId);
    std::vector<Party> &getAllParties();
    const std::vector<Party>& getAllParties() const;
    //std::vector<Party> getPartyNeighbors(int partyId);
    const std::vector<vector<int>> getPartiesByCoalitions() const;
    void addParty(int partyId, int coalitionId);
    int getCoalitionMandates(int coalitonId) const;
    Coalition& getCoalition(int coalitionId);
    void addAgent(int partyId, int coalitionId);
    const Agent& getAgentFromCoalition(int coalitionId);
    std::vector<int> getNeighborsWithoutOffer(int partyId,int coalitionId);

private:
    Graph mGraph;
    std::vector<Agent> mAgents;
    std::vector<Coalition> coalitions;
};
