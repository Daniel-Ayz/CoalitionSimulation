#pragma once

#include <vector>

#include "Graph.h"
#include "Agent.h"

class Coalition;

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    const Party &getParty(int partyId) const;
    const vector<int> &getPartyNeighbors(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    void addParty(int partyId, int coalitionId);
    int getCoalitionMandates(int coalitonId) const;
    Coalition& getCoalition(int coalitionId) const;
    int getTicks();
    int addTicks();

private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<Coalition> coalitions;
    int ticks;
};
