#pragma once

#include <iostream>
#include <vector>
using namespace std;
#include "Coalition.h"
class coalition;
class Agent;
class Simulation;
class JoinPolicy {
    public:
        virtual int select(std::vector<int>& coalitions,Simulation& sim) = 0; 
        virtual JoinPolicy* clone() const = 0;
        virtual ~JoinPolicy() = default;
};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        MandatesJoinPolicy();
        int select(std::vector<int>& coalitions,Simulation& sim);
        JoinPolicy* clone() const;
};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        LastOfferJoinPolicy();
        int select(std::vector<int>& coalitions,Simulation& sim);
        JoinPolicy* clone() const;
};

