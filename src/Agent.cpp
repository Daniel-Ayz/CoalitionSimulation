#include "Agent.h"
#include "SelectionPolicy.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
{
    // You can change the implementation of the constructor, but not the signature!
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
    // TODO: implement this method
}

Agent::~Agent()
{
    if(mSelectionPolicy){
        delete mSelectionPolicy;
        mSelectionPolicy = nullptr;
    }
}

Agent::Agent(const Agent& other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId)
{
    mSelectionPolicy = other.mSelectionPolicy->clone();
}

Agent::Agent(Agent&& other) : mAgentId(other.mAgentId), mPartyId(other.mPartyId)
{
    mSelectionPolicy = other.mSelectionPolicy;
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