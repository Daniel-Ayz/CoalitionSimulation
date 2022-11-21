#pragma once

#include <vector>

class Party;
class Simulation;
class SelectionPolicy {
    public:
        virtual SelectionPolicy* clone() const = 0;
        virtual Party& select(const Graph& graph, vector<Party>& partiesToOffer, int partyId) = 0;
};


class MandatesSelectionPolicy: public SelectionPolicy{
    public:
        MandatesSelectionPolicy();
        Party& select(const Graph& graph, vector<Party>& partiesToOffer, int partyId);
        SelectionPolicy* clone() const;
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
   public:
        EdgeWeightSelectionPolicy();
        Party& select(const Graph& graph, vector<Party>& partiesToOffer, int partyId);
        SelectionPolicy* clone() const;
};