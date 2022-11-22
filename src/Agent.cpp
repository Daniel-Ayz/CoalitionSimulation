#include "Agent.h"
#include "SelectionPolicy.h"
#include "Simulation.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mCoalitionId(partyId), mSelectionPolicy(selectionPolicy)
{
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

void Agent::step(Simulation &sim)
{
    std::vector<Party> neighbors = sim.getPartyNeighbors(mPartyId);
    std::vector<Party> noOfferNeighbors;
    for (Party& p: neighbors){
        if(!(p.hasOffer(mCoalitionId))){
            noOfferNeighbors.push_back(p);
        }
    }
    if(noOfferNeighbors.size()>0){
        Party p = mSelectionPolicy->select(sim.getGraph(), noOfferNeighbors, mPartyId);
        p.addOffer(mCoalitionId);
    }
}

Agent::~Agent()
{
    if(mSelectionPolicy){
        delete mSelectionPolicy;
        mSelectionPolicy = nullptr;
    }
}

Agent::Agent(const Agent& other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId), mCoalitionId(other.mCoalitionId), mSelectionPolicy(other.mSelectionPolicy->clone())
{
}

Agent::Agent(Agent&& other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId), mCoalitionId(other.mCoalitionId), mSelectionPolicy(other.mSelectionPolicy)
{
    other.mSelectionPolicy = nullptr;
}


Agent& Agent::operator=(const Agent& other)
{
    if(this!= &other){
        if(mSelectionPolicy) delete mSelectionPolicy;
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy->clone();
    }
    return *this;
}

Agent& Agent::operator=(Agent&& other)
{
    if(this!= &other){
        if(mSelectionPolicy) delete mSelectionPolicy;
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy;
        other.mSelectionPolicy = nullptr;
    }
    return *this;
}

void Agent::setCoalition(int _coalitionId){
    mCoalitionId = _coalitionId;
}

int Agent::getCoalitionId(){
    return mCoalitionId;
}

void Agent::setAgentId(int agentId){
    mAgentId = agentId;
}

void Agent::setPartyId(int partyId){
    mPartyId = partyId;
}