#include "../include/SelectionPolicy.h"
#include "../include/Party.h"
#include "../include/Graph.h"

MandatesSelectionPolicy::MandatesSelectionPolicy(){}

Party& MandatesSelectionPolicy::select(const Graph& graph, std::vector<Party>& partiesToOffer, int partyId)
{
    int maxIndex = -1;
    int maxMandates = 0;
    for(unsigned int i=0;i<partiesToOffer.size();i++){
        if(partiesToOffer[i].getMandates()>maxMandates){
            maxIndex = i;
            maxMandates = partiesToOffer[i].getMandates();
        }
    }
    return partiesToOffer[maxIndex];
}

SelectionPolicy* MandatesSelectionPolicy::clone() const
{
    return new MandatesSelectionPolicy();
}

EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy(){}

Party& EdgeWeightSelectionPolicy::select(const Graph& graph, std::vector<Party>& partiesToOffer, int partyId)
{
    int maxIndex = -1;
    int maxWeight = 0;
    for(unsigned int i=0;i<partiesToOffer.size();i++){
        if(graph.getEdgeWeight(partiesToOffer[i].getId(),partyId)>maxWeight){
            maxIndex = i;
            maxWeight = graph.getEdgeWeight(partiesToOffer[i].getId(),partyId);
        }
    }
    return partiesToOffer[maxIndex];
}

SelectionPolicy* EdgeWeightSelectionPolicy::clone() const
{
    return new EdgeWeightSelectionPolicy();
}