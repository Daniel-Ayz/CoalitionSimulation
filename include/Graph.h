#pragma once

#include <iostream>
#include <vector>
using namespace std;
#include "Party.h"

using std::vector;

class Graph
{
public:
    Graph(vector<Party> vertices, std::vector<vector<int>> edges);
    int getMandates(int partyId) const;
    int getEdgeWeight(int v1, int v2) const;
    int getNumVertices() const;
    const Party &getParty(int partyId) const;
    Party &getParty(int partyId);
    //std::vector<Party>& getPartyNeighbors(int partyId);
    std::vector<int> getNeighborsWithoutOffer(int partyId,int coalitionId);
    std::vector<Party> &getAllParties();
    const std::vector<Party> &getAllParties() const;

private:
    std::vector<Party> mVertices;
    std::vector<vector<int>> mEdges;
};
