#pragma once
#include <vector>
class Agent;
class JoinPolicy {
    public:
        virtual int select(const std::vector<int[]> offers) = 0; 
        virtual JoinPolicy* clone() const = 0;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        MandatesJoinPolicy();
        int select(const std::vector<int[]> offers);
        JoinPolicy* clone() const;
};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        LastOfferJoinPolicy();
        int select(const std::vector<int[]> offers);
        JoinPolicy* clone() const;
};

