#include "../include/Simulation.h"
#include <vector>
#include "Coalition.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    // You can change the implementation of the constructor, but not the signature!
}

void Simulation::step()
{
    // TODO: implement this method
    //iterate throught the parties of the graph and activate step(...) in each of theme
    int numOfVertices = mGraph.getNumVertices();
    for(int i = 0; i < numOfVertices; i++){
        Party p = mGraph.getParty(i);
        p.step(*this);
    }
    for(int i=0; i< mAgents.size();i++)
    {
        mAgents[i].step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    // TODO implement this method
    return true;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    vector<vector<int>> ans;
    for(int i = 0; i < coalitions.size();i++)
    {
        ans.push_back(coalitions[i].getParties());
    }
    return ans;
}

const vector<int>& Simulation::getPartyNeighbors(int partyId) const
{
    return mGraph.getPartyNeighbors(partyId);
}

void Simulation::addParty(int partyId, int coalitionId){
    Coalition c = getCoalition(coalitionId);
    c.addParty(partyId, getParty(partyId).getMandates());
}

Coalition& Simulation::getCoalition(int coalitionId) const{
    for(Coalition c : coalitions){
        if (c.getCoalitionId() == coalitionId){
            return c;
        }
    }
}
