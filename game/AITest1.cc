#include "Player.hh"
#include <cmath>
using namespace std;
#define PLAYER_NAME Test1
 
/* IMPLEMENTACIONS: (v5_2) Implementacio sense funcions auxiliars
        - Va al vei buit que tingui més veins buits. (profunditat 3)
                - Tractament bonus:
                        - Ghost +36 (hi anirà segur)
                        - Points +12 (probabilitat alta)
                        - Turbo -6 (menys probable)
                - Si hi ha empat entre veins amb mes veins, tira "recte" (no se sap).
        - Utilitza sempre els bonus
                - excepte el Turbo que ho fa si ronda >= 100.
                - el Ghost només si no te veins buits
                - Points sempre que el tingui
*/
struct PLAYER_NAME : public Player {
 
    static Player* factory () {return new PLAYER_NAME;} // NO MODIFICAR
 
 
    /** Attributes for your player can be defined here.    */    
    //vector<int> my_awesome_vector_of_integers;
   
      /** Play method. 1 cop per ronda. Llegir board i fer accions per la ronda. */
    void play () {
       
        vector<int> my_bikes = bikes(me());
        for (int i = 0; i < (int)my_bikes.size(); ++i) {
                       
                        const Bike& my_bike = bike(my_bikes[i]);
                                               
                        if (!my_bike.alive) {continue;} // NO MODIFICAR - Bike morta
                        if (round() % 2 && my_bike.turbo_duration <= 0) {continue;} // NO MODIFICAR - Turbo activador
                       
                        vector<int> neighbours = vertex(my_bike.vertex).neighbours;
                        vector< pair<int,int> > empty_neighbours;
                       
                        for (int j = 0; j < (int)neighbours.size(); ++j) {
                                int id = neighbours[j];
                                if (vertex(id).wall == -1) {
                                        pair<int,int> aux;
                                        aux.first = id;
                                        aux.second = 0;
                                       
                                        if (vertex(id).bonus == Points) aux.second = 12;
                                        if (vertex(id).bonus == Ghost) aux.second = 36;
                                        if (vertex(id).bonus == Turbo) aux.second = -6;
                                       
                                        vector<int> neighbours1 = vertex(id).neighbours;
                                        for (int l = 0; l < (int)neighbours1.size(); ++l) {
                                            int id1 = neighbours1[l];
                                            if (vertex(id1).wall == -1) {
                                                pair<int,int> aux2;
                                                aux2.first = id1;
                                                aux2.second = 0;
                                               
                                                /*if (vertex(id).bonus == Points) aux.second = 2;
                                                if (vertex(id).bonus == Ghost) aux.second = 6;
                                                if (vertex(id).bonus == Turbo) aux.second = -1;*/
                                               
                                                vector<int> neighbours2 = vertex(id1).neighbours;
                                                for (int m = 0; m < (int)neighbours2.size(); ++m) {
                                                    int id2 = neighbours2[m];
                                                    if (vertex(id2).wall == -1) {
                                                        ++aux2.second;
                                                    }
                                                }
                                                aux.second += aux2.second;
                                            }
                                        }
                                        empty_neighbours.push_back(aux);
                                }
                        }
                       
                        // Create an empty movement
                        Movement movement(my_bike.id);
                       
                        //
                        bool use_ghost = false;
                        if (!empty_neighbours.empty()) {
                            int max_pos = (int)empty_neighbours.size()/2;
                            for (int k = 0; k < (int)empty_neighbours.size(); ++k) {
                                if (empty_neighbours[k].second > empty_neighbours[max_pos].second) {
                                    max_pos = k;
                                }
                            } // max_id = vertex buit amb més veins buits
                            movement.next_vertex = empty_neighbours[max_pos].first;
                        }
                        else {
                            use_ghost = true;
                            movement.next_vertex = neighbours[ rand() % (int)neighbours.size() ];
                        }
                       
                        // Utilitza bonus sempre, excepte turbo, només si ronda >= 50.
                        if (my_bike.bonus != None) {
                                if (my_bike.bonus == Turbo and round() > 100) movement.use_bonus = true;
                                else if (my_bike.bonus == Ghost and use_ghost) movement.use_bonus = true;
                                else if (my_bike.bonus == Points) movement.use_bonus = true;
                                else movement.use_bonus = false;
                        }
                       
            command(movement); // Command the movement
        }
    }
};
 
 
 
/** Do not modify the following line. */
RegisterPlayer(PLAYER_NAME);