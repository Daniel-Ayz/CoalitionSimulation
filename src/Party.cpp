#include "../include/Party.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting) 
{
    // You can change the implementation of the constructor, but not the signature!
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

Party::Party(const Party& other): mId(other.mId), mName(other.mName), mMandates(other.mMandates), mState(other.mState)
{
   mJoinPolicy = other.mJoinPolicy->clone();
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
    }
}

Party::Party(Party&& other) : mId(other.mId), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy), mState(other.mState){
    other.mJoinPolicy = nullptr;
}

Party& Party::operator=(Party&& other)
{
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
}

