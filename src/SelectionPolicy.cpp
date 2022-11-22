#include "../include/SelectionPolicy.h"
#include "../include/Party.h"
#include "../include/Graph.h"

MandatesSelectionPolicy::MandatesSelectionPolicy(){}

int MandatesSelectionPolicy::select(const Graph& graph, std::vector<int> partiesToOffer, int partyId)
{
    int maxPartyId = -1;
    int maxMandates = 0;
    for(unsigned int i=0;i<partiesToOffer.size();i++){
        if(graph.getParty(partiesToOffer[i]).getMandates()>maxMandates){
            maxPartyId = i;
            maxMandates = graph.getParty(partiesToOffer[i]).getMandates();
        }
    }
    return maxPartyId;
}

SelectionPolicy* MandatesSelectionPolicy::clone() const
{
    return new MandatesSelectionPolicy();
}

EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy(){}

int EdgeWeightSelectionPolicy::select(const Graph& graph, std::vector<int> partiesToOffer, int partyId)
{
    int maxPartyId = -1;
    int maxWeight = 0;
    for(unsigned int i=0;i<partiesToOffer.size();i++){
        if(graph.getEdgeWeight(partiesToOffer[i],partyId)>maxWeight){
            maxPartyId = i;
            maxWeight = graph.getEdgeWeight(partiesToOffer[i],partyId);
        }
    }
    return maxPartyId;
}

SelectionPolicy* EdgeWeightSelectionPolicy::clone() const
{
    return new EdgeWeightSelectionPolicy();
}