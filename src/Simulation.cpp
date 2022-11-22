#include "../include/Simulation.h"
#include <vector>
#include "Coalition.h"

Simulation::Simulation(Graph graph, std::vector<Agent> agents) : mGraph(graph), mAgents(agents), coalitions()
{
    vector<Party> & parties = getAllParties();
    for(Party& p : parties){
        if(p.getState() == Joined){
            p.setCoalition(p.getId());
            coalitions.push_back(Coalition(p.getId(),p.getMandates()));
        }
    }
}

void Simulation::step()
{
    // TODO: implement this method
    //iterate throught the parties of the graph and activate step(...) in each of theme
    std::vector<Party>& parties = getAllParties();
    for(Party& p: parties){
        p.step(*this);
    }
    for(Agent& a: mAgents){
        a.step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    // TODO implement this method
    for(const Coalition& c: coalitions)
    {
        if(c.getMandates() >60)
        {
            return true;
        }
    }
    std::vector<Party> parties = getAllParties();
    for(Party& p : parties)
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

const std::vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}
Party &Simulation::getParty(int partyId)
{
    return mGraph.getParty(partyId);
}
/// This method returns a "coalition" std::vector, where each element is a std::vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const std::vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    std::vector<vector<int>> ans;
    for(unsigned int i = 0; i < coalitions.size();i++)
    {
        ans.push_back(coalitions[i].getParties());
    }
    return ans;
}
/*
vector<Party> Simulation::getPartyNeighbors(int partyId)
{
    return mGraph.getPartyNeighbors(partyId);
}*/

void Simulation::addParty(int partyId, int coalitionId){
    Coalition c = getCoalition(coalitionId);
    c.addParty(partyId, getParty(partyId).getMandates());
}

Coalition& Simulation::getCoalition(int coalitionId){
    for(Coalition& c : coalitions){
        if (c.getCoalitionId() == coalitionId){
            return c;
        }
    }
    return coalitions[0];
}

vector<Party>& Simulation::getAllParties(){
    return mGraph.getAllParties();
}

const std::vector<Party>& Simulation::getAllParties() const
{
    return mGraph.getAllParties();
}

void Simulation::addAgent(int partyId, int coalitionId){
    Agent agent = getAgentFromCoalition(coalitionId);
    agent.setAgentId(mAgents.size());
    agent.setPartyId(partyId);
    mAgents.push_back(agent);
}

const Agent& Simulation::getAgentFromCoalition(int coalitionId){
    for(Agent& a: mAgents){
        if(a.getCoalitionId()==coalitionId){
            return a;
        }
    }
    return mAgents[0];
}

std::vector<int> Simulation::getNeighborsWithoutOffer(int partyId,int coalitionId){
    return mGraph.getNeighborsWithoutOffer(partyId,coalitionId);
}