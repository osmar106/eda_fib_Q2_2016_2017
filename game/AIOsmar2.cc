#include "Player.hh"

#include <cmath>

using namespace std;

/**
 * Write the name of your player and save this file
 * with a name matching the format "AIyourname.cc".
 */
#define PLAYER_NAME Osmar2


struct PLAYER_NAME : public Player {

    /**
     * Factory: returns a new instance of this class.
     * Do not modify this function.
     */
    static Player* factory () {
        return new PLAYER_NAME;
    }


    /**
     * Attributes for your player can be defined here.
     */     
    //vector<int> my_awesome_vector_of_integers;


    /**
     * Play method.
     * 
     * This method will be invoked once per each round.
     * You have to read the board and place your actions
     * for this round.
     */
    void play () {
		
        vector<int> my_bikes = bikes(me());
        for (int i = 0; i < (int)my_bikes.size(); ++i) {
			
			const Bike& my_bike = bike(my_bikes[i]);
			bool ghost = false;
			
			// Do something only if this bike is alive
			if (!my_bike.alive) {
				continue;
			}
			
			//Only turbo bikes can move at odd rounds
			if (round() % 2 && my_bike.turbo_duration <= 0) {
				continue;
			}
			
			// Find all empty neighbours
			vector<int> neighbours = vertex(my_bike.vertex).neighbours;
			vector< pair<int, int>> empty_neighbours;
			for (int j = 0; j < (int)neighbours.size(); ++j) {
				int id = neighbours[j];
				if (vertex(id).wall == -1) {
					pair<int, int> par1;
					par1.first = id;
					par1.second = 0;

					
					vector<int> neighbours2 = vertex(id).neighbours;

					if(vertex(id).bonus == Ghost) par1.second = 32;
					if(vertex(id).bonus == Turbo) par1.second = -6;
					if(vertex(id).bonus == Points) par1.second = 10;

					for (int k = 0; k < (int)neighbours2.size(); ++k){
						int id2 = neighbours2[k];
						if (vertex(id2).wall == -1){
							pair<int, int> par2;
							par2.first = id2;
							par2.second = 0;

							vector<int> neighbours3 = vertex(id2).neighbours;
							for (int l = 0; l < (int)neighbours3.size(); ++l){
								int id3 = neighbours3[l];
								if (vertex(id3).wall == -1){
									++par2.second;
								}
							}
						par1.second += par2.second;		
						}
					}
					empty_neighbours.push_back(par1);
				}
			}
			
			// Create an empty movement
			Movement movement(my_bike.id);
			
			// Set next_vertex to a random empty neighbour, if any, or to a random neighbour otherwise
			if (!empty_neighbours.empty()) {
				int id4 = (int)empty_neighbours.size()/2;
				for (int m = 0; m <(int)empty_neighbours.size(); ++m){
					if (empty_neighbours[m].second > empty_neighbours[id4].second)
						id4 = m;
				}
				movement.next_vertex = empty_neighbours[id4].first;
			} else {
				movement.next_vertex = neighbours[ rand() % (int)neighbours.size() ];
				ghost = true;
			}
			
			// Use bonus randomly when we have one
			if (my_bike.bonus != None) {
				if(my_bike.bonus == Ghost and ghost) movement.use_bonus = true;
				else if (my_bike.bonus == Turbo and round() > 100) movement.use_bonus = true;
				else if(my_bike.bonus == Points) movement.use_bonus = true;
				else movement.use_bonus = false;
			}
			
			// Command the movement
            command(movement);
			
        }
        
    }

};



/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);

