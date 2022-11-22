#pragma once

#include <iostream>
#include <vector>
using namespace std;
#include "Coalition.h"
class coalition;
class Agent;
class JoinPolicy {
    public:
        virtual Coalition& select(std::vector<Coalition>& coalitions) = 0; 
        virtual JoinPolicy* clone() const = 0;
        virtual ~JoinPolicy() = default;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        MandatesJoinPolicy();
        Coalition& select(std::vector<Coalition>& coalitions);
        JoinPolicy* clone() const;
};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        LastOfferJoinPolicy();
        Coalition& select(std::vector<Coalition>& coalitions);
        JoinPolicy* clone() const;
};

