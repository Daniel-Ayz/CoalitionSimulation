#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Graph;
class Party;
class Simulation;
class SelectionPolicy {
    public:
        virtual SelectionPolicy* clone() const = 0;
        virtual int select(const Graph& graph, std::vector<int> partiesToOffer, int partyId) = 0;
        virtual ~SelectionPolicy() = default;
};


class MandatesSelectionPolicy: public SelectionPolicy{
    public:
        MandatesSelectionPolicy();
        int select(const Graph& graph, std::vector<int> partiesToOffer, int partyId);
        SelectionPolicy* clone() const;
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
   public:
        EdgeWeightSelectionPolicy();
        int select(const Graph& graph, std::vector<int> partiesToOffer, int partyId);
        SelectionPolicy* clone() const;
};