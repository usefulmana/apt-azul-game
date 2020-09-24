#include "Tile.h"
#include <iostream>
#include "LinkedList.h"



class TileBag
{
    public:
        
        // Constructor/Deconstructor
        TileBag();
        ~TileBag();

        

        /**
         * Checks to see if tileBag is empty
         */
        bool isTileBagEmpty();
    
        /**
         * Helper method: Swap two tiles
         */
        void swap(Tile* a, Tile* b);
        
        /**
        * Shuffles tilebag
        */
        void shuffleTileBag(int n);

        /**
         * refills tile bag when no tiles remain
         */
        void refillTileBag();

        /**
         * Checks current amount of tiles in tile bag
         */
        int numberOfTilesInBag();

        /**
         * Displays contents of tilebag
         */
        void displayTileBag(); 
        /**
         * Turns filebag into string in save format.
         */
        std::string tileBagToString();

    private:
    
        // tileBag Vector
        LinkedList<Tile*> * tileBag;



        
};