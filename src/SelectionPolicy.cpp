#include "SelectionPolicy.h"
#include "Party.h"
#include "Graph.h"

MandatesSelectionPolicy::MandatesSelectionPolicy(){}

Party& MandatesSelectionPolicy::select(const Graph& graph)
{
    Party max = parties[0]; 
    for(Party party : parties)
    {
        if(party.getMandates() > max.getMandates())
        {
            max = party;
        }
    }
    return max;
}

SelectionPolicy* MandatesSelectionPolicy::clone() const
{
    return new MandatesSelectionPolicy();
}

EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy(){}

Party& EdgeWeightSelectionPolicy::select(const Graph& grath)
{

}

SelectionPolicy* EdgeWeightSelectionPolicy::clone() const
{
    return new EdgeWeightSelectionPolicy();
}