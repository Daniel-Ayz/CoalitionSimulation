#pragma once

class Party;
class Simulation;
class SelectionPolicy {
    public:
        virtual Party& select() = 0;
};

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
        Party& select();
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
   public:
        Party& select();
};