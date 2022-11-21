#pragma once
#include <vector>

class Coalition
{
    public:
        Coalition(int partyId, int mandatesSum);
        int getMandates() const;
        int getCoalitionId() const;
        const std::vector<int>& getParties() const;
        void addParty(int partyId, int mandates);
    private:
        int coalitionId;
        std::vector<int> partyIds;
        int mandatesSum;

};