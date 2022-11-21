#include "../include/JoinPolicy.h"


MandatesJoinPolicy::MandatesJoinPolicy(){}

int MandatesJoinPolicy::select(const std::vector<int[]> parties)
{
// TO IMPLEMENT
}
JoinPolicy*  MandatesJoinPolicy::clone() const
{
    return new  MandatesJoinPolicy();
}


LastOfferJoinPolicy::LastOfferJoinPolicy(){}

int LastOfferJoinPolicy::select(const std::vector<int[]> parties)
{
// TO IMPLEMENT

}
JoinPolicy*  LastOfferJoinPolicy::clone() const
{
    return new  LastOfferJoinPolicy();
}


