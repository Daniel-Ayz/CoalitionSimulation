#include "../include/JoinPolicy.h"

MandatesJoinPolicy::MandatesJoinPolicy(){}

int MandatesJoinPolicy::select(std::vector<Coalition>& coalitions)
{
    int coalitionId=-1;
    int max=0;
    for(Coalition c : coalitions)
    {
        if(c.getMandates()>=max){
            max = c.getMandates();
            coalitionId = c.getCoalitionId();
        }
    }
    return coalitionId;
}
JoinPolicy*  MandatesJoinPolicy::clone() const
{
    return new  MandatesJoinPolicy();
}


LastOfferJoinPolicy::LastOfferJoinPolicy(){}

int LastOfferJoinPolicy::select(std::vector<Coalition>& coalitions)
{
    // TO IMPLEMENT
    int n = coalitions.size();
    Coalition c = coalitions[n-1];
    return c.getCoalitionId();
}
JoinPolicy*  LastOfferJoinPolicy::clone() const
{
    return new  LastOfferJoinPolicy();
}


