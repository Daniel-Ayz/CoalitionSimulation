#include "SelectionPolicy.h"

MandatesSelectionPolicy::MandatesSelectionPolicy(){}

Party& MandatesSelectionPolicy::select(const std::vector<Party> parties)
{
// TO IMPLEMENT
}

SelectionPolicy* MandatesSelectionPolicy::clone() const
{
    return new MandatesSelectionPolicy();
}

EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy(){}

Party& EdgeWeightSelectionPolicy::select(const std::vector<Party> parties)
{
// TO IMPLEMENT

}

SelectionPolicy* EdgeWeightSelectionPolicy::clone() const
{
    return new EdgeWeightSelectionPolicy();
}