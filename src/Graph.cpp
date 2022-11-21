#include "../include/Graph.h"
#include "Party.h"

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
{
    // You can change the implementation of the constructor, but not the signature!
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}

const vector<int> & Graph::getPartyNeighbors(int partyId) const
{
    vector<int> partiesToReturn;
    for(Party other: mVertices){
        if(getEdgeWeight(other.getId(),partyId) != 0){
            partiesToReturn.push_back(other.getId());
        }
    }
    return partiesToReturn;
}

vector<Party> &Graph::getAllParties(){
    return mVertices;
}