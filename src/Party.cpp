#include "Party.h"

#include <iostream>

#include <algorithm>
#include <vector>
Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting), offers() 
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
    // TODO: implement this method
}

Party::Party(const Party& other)
{
    *this = other;
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
        mJoinPolicy = other.mJoinPolicy;
        mState = other.mState;
    }
}

Party::Party(Party&& other) : mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy), mState(other.mState){
    other.mJoinPolicy = nullptr;
}

Party& Party::operator=(Party&& other)
{
    
}

void Party::addOffer(int coalitionId){
    if(!hasOffer(coalitionId)){
        offers.push_back(coalitionId);
    }
}
// bool Party::hasOffer(int coalitionId){
//     return std::find((offers.begin(), offers.end(), coalitionId) != offers.end());
// }
