#include "../include/Graph.h"
#include "Party.h"

Graph::Graph(vector<Party> vertices, std::vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
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

Party &Graph::getParty(int partyId)
{
    return mVertices[partyId];
}
/*
vector<Party> Graph::getPartyNeighbors(int partyId)
{
    std::vector<Party> partiesToReturn;
    for(Party& p: mVertices){
        if(getEdgeWeight(p.getId(),partyId) != 0){
            partiesToReturn.push_back(p);
        }
    }
    return partiesToReturn;
}*/

vector<int> Graph::getNeighborsWithoutOffer(int partyId,int coalitionId){
    vector<int> v;
    for(Party& p:mVertices){
        if(getEdgeWeight(p.getId(),partyId)!=0 && !p.hasOffer(coalitionId) && p.getState()!=Joined){
            v.push_back(p.getId());
        }
    }
    return v;
}
vector<Party> &Graph::getAllParties(){
    return mVertices;
}

const std::vector<Party> &Graph::getAllParties() const{
    return mVertices;
}