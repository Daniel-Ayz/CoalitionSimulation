#include "../include/JoinPolicy.h"
#include"Simulation.h"
MandatesJoinPolicy::MandatesJoinPolicy(){}

int MandatesJoinPolicy::select(std::vector<int>& coalitions, Simulation& sim)
{
    int coal = 0;
    int max=0;
    for(int coId : coalitions)
    {
        Coalition& c = sim.getCoalition(coId);
        if(c.getMandates()>=max){
            max = c.getMandates();
            coal = coId;
        }
    }
    return coal;
}
JoinPolicy*  MandatesJoinPolicy::clone() const
{
    return new  MandatesJoinPolicy();
}


LastOfferJoinPolicy::LastOfferJoinPolicy(){}

int LastOfferJoinPolicy::select(std::vector<int>& coalitions,Simulation& sim)
{
    // TO IMPLEMENT
    int n = coalitions.size();
    return coalitions[n-1];
}
JoinPolicy*  LastOfferJoinPolicy::clone() const
{
    return new  LastOfferJoinPolicy();
}


