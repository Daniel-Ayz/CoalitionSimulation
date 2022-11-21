#include "../include/SelectionPolicy.h"
#include "../include/Party.h"
#include "../include/Graph.h"

MandatesSelectionPolicy::MandatesSelectionPolicy(){}

Party& MandatesSelectionPolicy::select(const Graph& graph, vector<Party>& partiesToOffer, int partyId)
{
    int maxIndex = -1;
    int maxMandates = 0;
    for(int i=0;i<partiesToOffer.size();i++){
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

Party& EdgeWeightSelectionPolicy::select(const Graph& graph, vector<Party>& partiesToOffer, int partyId)
{

}

SelectionPolicy* EdgeWeightSelectionPolicy::clone() const
{
    return new EdgeWeightSelectionPolicy();
}