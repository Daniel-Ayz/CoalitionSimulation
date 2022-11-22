#include "Party.h"
#include "JoinPolicy.h"
#include "Simulation.h"
#include <iostream>

#include <algorithm>
#include <vector>

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), offers(), CoalitionId(-1), ticks(1)
{

}

int Party::getId() const{
    return mId;
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}

void Party::step(Simulation &s)
{
    if(mState == CollectingOffers)
    {
        if(getTicks() < 3)
        {
            addTicks();
        }
        else
        {
            //select offer using the join policy
            std::vector<int> coalitionsOffered;
            for(int i : offers)
            {
                coalitionsOffered.push_back(i);
            }
            int c = mJoinPolicy->select(coalitionsOffered,s);
            Coalition& coal = s.getCoalition(c);
            coal.addParty(mId,mMandates);
            setCoalition(c);
            s.addAgent(mId, CoalitionId);
            mState = Joined;
        }
    }
    
}

Party::Party(const Party& other): mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy->clone()), mState(other.mState), offers(), CoalitionId(other.CoalitionId), ticks(other.ticks)
{
}

Party::~Party()
{
    if(mJoinPolicy){
        delete mJoinPolicy;
        mJoinPolicy = nullptr;
    }
}

Party& Party::operator=(const Party& other)
{
    if(this != &other){
        if(mJoinPolicy){
            delete mJoinPolicy;
            mJoinPolicy = nullptr;
        }
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mJoinPolicy = other.mJoinPolicy->clone();
        mState = other.mState;
        offers = other.offers;
        CoalitionId = other.CoalitionId;
    }
    return *this;
}

Party::Party(Party&& other) : mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy), mState(other.mState), offers(), CoalitionId(other.CoalitionId), ticks(other.ticks){
    other.mJoinPolicy = nullptr;
}

Party& Party::operator=(Party&& other)
{
    if(this != &other){
        if(mJoinPolicy){
            delete mJoinPolicy;
            mJoinPolicy = nullptr;
        }
        mJoinPolicy = other.mJoinPolicy;
        other.mJoinPolicy = nullptr;
        
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mJoinPolicy = other.mJoinPolicy;
        mState = other.mState;
        offers = other.offers;
        CoalitionId = other.CoalitionId;
    }
    return *this;
}

void Party::addOffer(int coalitionId){
    if(!hasOffer(coalitionId)){
        if(mState == Waiting){
            mState = CollectingOffers;
        }
        offers.push_back(coalitionId);
    }
}
bool Party::hasOffer(int coalitionId) const
{
    for(int c: offers){
        if(c == coalitionId)
        {
            return true;
        }
    }
    return false;
}


int Party::getTicks(){
    return ticks;
}

void Party::addTicks(){
    ticks = ticks + 1;
}

void Party::setCoalition(int coalitionId){
    CoalitionId = coalitionId;
}
