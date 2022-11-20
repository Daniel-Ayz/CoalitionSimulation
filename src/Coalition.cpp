#include "Coalition.h"

Coalition::Coalition(int partyId, int _mandates): coalitionId(partyId), mandatesSum(_mandates), partyIds() {
    partyIds.push_back(partyId);
}
int Coalition::getMandates() const{
    return mandatesSum;
}
int Coalition::getCoalitionId() const{
    return coalitionId;
}
const std::vector<int>& Coalition::getParties() const{
    return partyIds;
}
void Coalition::addParty(int partyId, int mandates){
    partyIds.push_back(partyId);
    mandatesSum = mandatesSum + mandates;
}

/*
int coalitionId;
std::vector<int> partyIds;
int mandatesSum;

}
*/