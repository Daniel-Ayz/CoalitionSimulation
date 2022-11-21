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
    vector<Party> parties = getAllParties();
    for(Party p: parties){
        p.step(*this);
    }
    for(Agent a: mAgents){
        a.step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    // TODO implement this method
    for(Coalition c: coalitions)
    {
        if(c.getMandates() >60)
        {
            return true;
        }
    }
    vector<Party> parties = getAllParties();
    for(Party p : parties)
    {
        if(p.getState()!= Joined){
            return false;
        }
    }
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

vector<Party>& Simulation::getPartyNeighbors(int partyId)
{
    return mGraph.getPartyNeighbors(partyId);
}

void Simulation::addParty(int partyId, int coalitionId){
    Coalition c = getCoalition(coalitionId);
    c.addParty(partyId, getParty(partyId).getMandates());
}

Coalition& Simulation::getCoalition(int coalitionId){
    for(Coalition c : coalitions){
        if (c.getCoalitionId() == coalitionId){
            return c;
        }
    }
}

vector<Party>& Simulation::getAllParties(){
    return mGraph.getAllParties();
}

const vector<Party>& Simulation::getAllParties() const
{
    return mGraph.getAllParties();
}