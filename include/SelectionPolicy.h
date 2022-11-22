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
        virtual Party& select(const Graph& graph, std::vector<Party>& partiesToOffer, int partyId) = 0;
        virtual ~SelectionPolicy() = default;
};


class MandatesSelectionPolicy: public SelectionPolicy{
    public:
        MandatesSelectionPolicy();
        Party& select(const Graph& graph, std::vector<Party>& partiesToOffer, int partyId);
        SelectionPolicy* clone() const;
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
   public:
        EdgeWeightSelectionPolicy();
        Party& select(const Graph& graph, std::vector<Party>& partiesToOffer, int partyId);
        SelectionPolicy* clone() const;
};