#include "../include/JoinPolicy.h"

MandatesJoinPolicy::MandatesJoinPolicy(){}

Coalition& MandatesJoinPolicy::select(std::vector<Coalition>& coalitions)
{
    Coalition& coal = coalitions[0];
    int max=0;
    for(Coalition c : coalitions)
    {
        if(c.getMandates()>=max){
            max = c.getMandates();
            coal = c;
        }
    }
    return coal;
}
JoinPolicy*  MandatesJoinPolicy::clone() const
{
    return new  MandatesJoinPolicy();
}


LastOfferJoinPolicy::LastOfferJoinPolicy(){}

Coalition& LastOfferJoinPolicy::select(std::vector<Coalition>& coalitions)
{
    // TO IMPLEMENT
    int n = coalitions.size();
    Coalition& c = coalitions[n-1];
    return c;
}
JoinPolicy*  LastOfferJoinPolicy::clone() const
{
    return new  LastOfferJoinPolicy();
}


