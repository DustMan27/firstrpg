#include <iostream>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>
#include <limits>
using namespace std;
//above defines the libraries required and the std:: prefix for outputs


int battle_command = 9; //9 is the default value as zero is when the command loop is termianted.
int battle_attack = 0;
int player_damage = 0;
int player_atk = 0;
int battle_initiator = rand() % 100;
int enemy_picker = 5;
int player_hp = 0;
int player_maxhp = 0;
int player_spd = 0;
int player_def = 0;
int player_sp = 50;
int player_con = 0;
int player_level = 1;
int player_xp = 0;
int player_level_target = 100;
double hit_chance;
string player_name;
bool player_setup = false;
int player_class = 0;
string class_name = "unknown";



//Function prompting the user to press any key.
void PressEnter(){
    cout << "Press Any Key To Continue." << endl;
    system("read");
    }
//The level up system. Stats grow exponentially, but so does the experience required to get to the next level.
void level_up(){
    if (player_xp > player_level_target){
        player_level = player_level + 1;
        player_maxhp = player_maxhp*1.2;
        player_hp = player_maxhp;
        player_atk = player_atk*1.25;
        player_con = player_con*1.25;
        cout << "You level up, you are now level " << player_level << "!" << endl;
        cout << "To confirm, your stats are now as follows" << endl << "Name: " << player_name << endl << "HP: " << player_hp << "/" << player_maxhp << endl << "ATK: " << player_atk << endl << "CON:" << player_con << endl << "DEF: " << player_def << endl << "SPD: " << player_spd << endl;
        cout << "That's great, let's carry on." << endl;
        PressEnter();
        player_level_target = player_level_target*2.5;
    }
    //code here
}
//Outputs the users stats at the start.
void classmaker(){
    cout << "You're stats are as follows." << endl;
    cout << "Class: " << class_name << endl;
    cout << "HP:" << player_hp << "/" << player_maxhp << endl;
    cout << "ATK:" << player_atk << endl;
    cout << "SPD:" << player_spd << endl;
    cout << "DEF:" << player_def << endl;
    cout << "CON:" << player_con << endl;
    }
//Kills the code running.
void gameover(){
    cout << "You are dead. Game over." << endl;
    PressEnter();
    exit(0);
    }
//Battle System. This requires incorporation of character speed and defense to make more variance in results.
void battle(string monster_name, int monster_hp, int monster_atk, int xp_reward, int monster_spd){ //Declare the values of the functions variables within the code.
            cout << monster_name << " Appeared!" << endl;
            while (monster_hp > 0 && battle_command != 0){
                cout << "What would you like to do?" << endl << "1. Attack" << endl << "2. Heal" << endl << "3. Escape" << endl;
                cin >> battle_command;
                if (battle_command != 1 && battle_command != 2 && battle_command != 3 && battle_command != 9){
                    cout << "Wrong input, try again" << endl;
                    battle_command = 9;
                }
                if (battle_command == 1){
                    cout << "You attack the enemy!" << endl;
                    //damage is + or - 10% of atk. therefore: battle_attack = rand()% (player_atk*0.10) + player_atk
                    //v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014
                    hit_chance = (player_spd/monster_spd);
                    if (hit_chance >= 1.0){
                        battle_attack = rand() % player_atk*0.1 + player_atk;
                        cout << "You do " << battle_attack << " amount of damage!" << endl;
                        monster_hp = monster_hp - battle_attack;
                        cout << monster_name << " now has " << monster_hp << " HP!" << endl;
                        PressEnter();
                    }
                    if (hit_chance <= 0.99){
                        cout << "You swing at the enemy, but they dodge easily." << endl;
                        PressEnter();
                        }
                    if (monster_hp >= 1){
                        player_damage = (rand() % 1 + monster_atk) - player_def/2;
                        if (player_damage << 0){
                            player_damage = 0;
                        }
                        cout << monster_name << " attacks you, and does " << player_damage << " damage!" << endl;
                        player_hp = player_hp - player_damage;
                        cout << "You now have " << player_hp << "/" << player_maxhp << "HP." << endl;
                        PressEnter();
                    }
                    if (monster_hp <= 0){
                        cout << "Victory!" << endl;
                        cout << "You gain " << xp_reward << "XP!" << endl;
                        PressEnter();
                        player_xp = player_xp + xp_reward;
                        level_up();
                        battle_initiator = 0;
                        enemy_picker = 0;
                    }
                    battle_command = 9;
                    if (player_hp <= 0){
                        gameover();
                    }
                }
                if (battle_command == 2){
                    cout << "HP was at " << player_hp << "!" << endl;
                    player_hp = player_hp + (rand() % 1 + player_con*1.25);
                    if (player_hp > player_maxhp){
                        player_hp = player_maxhp;
                    }
                    cout << "HP is now at: " << player_hp << "/" << player_maxhp << endl;
                    PressEnter();
                    if (monster_hp >= 1){
                        player_damage = (rand() % 1 + monster_atk) - player_def/2;
                        if (player_damage << 0){
                            player_damage = 0;
                        }
                        cout << monster_name << " attacks you, and does " << player_damage << " damage!" << endl;
                        player_hp = player_hp - player_damage;
                        cout << "You now have " << player_hp << "/" << player_maxhp << "HP." << endl;
                        PressEnter();
                        battle_command = 9;
                    if (player_hp <= 0){
                        gameover();
                    }
                    }
                }
                if (monster_hp <= 0){
                    cout << "Victory!" << endl;
                    cout << "You gain " << xp_reward << "XP!" << endl;
                    player_xp = player_xp + xp_reward;
                    level_up();
                    battle_initiator = 0;
                    enemy_picker = 0;
                }
                if (battle_command == 3){
                    cout << "You ran away!" << endl;
                    PressEnter();
                    level_up();
                    battle_initiator = 0;
                    enemy_picker = 0;
                    monster_hp = 0;s
                }
        }
    }

int main(){
        while (player_setup == false){
        cout << "Please select your character name: ";
        cin >> player_name;
        cout << endl;
        cout << "Please select your class from the following. \n";
        cout << "1. Warrior\n 2. Mage\n  3. Rogue\n   4. Healer\n---------\n";
        cout << "Enter a number here: ";
        cin >> player_class;
        if (player_class == 1){
            player_con = 0;
            player_maxhp = 200;
            player_hp = 200;
            player_atk = 25;
            player_spd = 5;
            player_def = 25;
            class_name = "Warrior";
            classmaker();
            player_setup = true;
        }
        else if (player_class == 2){
            player_con = 33;
            player_maxhp = 80;
            player_hp = 80;
            player_atk = 12;
            player_spd = 5;
            player_def = 12;
            class_name = "Mage";
            classmaker();
            player_setup = true;
        }
        else if (player_class == 3){
            player_con = 0;
            player_maxhp = 120;
            player_hp = 120;
            player_atk = 14;
            player_spd = 22;
            player_def = 12;
            class_name = "Rogue";
            classmaker();
            player_setup = true;
        }
        else if (player_class == 4){
            player_con = 28;
            player_maxhp = 90;
            player_hp = 90;
            player_atk = 10;
            player_spd = 7;
            player_def = 10;
            class_name = "Healer";
            classmaker();
            player_setup = true;
        } else {
            cout << "Wrong input!";
            player_class = 0;
        }
    }
    char direction_input = 'X';
    int x_position = 0;
    int y_position = 0;
    //int battle_initiator = rand() % 100;
    int active_movement = 1;
    //int battle_command = 9; //9 is the deafult value as zero is when the command loop is termianted.
    //int player_damage = 0;
    //int battle_attack = 0;
    while (active_movement == 1){ //This is a loop which allows the user to continuously choose which direction to go. Only if an event occurs should this loop be broken for some other action.
        cout << "You are currently locateds at coordinates (" << x_position << "," << y_position << ")" << endl;
        cout << "Please enter if you would like to go up (W), down(S), left(A) or right.(D): ";
        cin >> direction_input;
        if (direction_input == 'w'){
            if (x_position >= 50){
            cout << "You can't go any further than this!" << endl;
            x_position = 50;
        } else {
            x_position = x_position + 1;
        }
        }
        if (direction_input == 's'){
            if (x_position <= -50){
                cout << "You can't go any further than this!" << endl;
                x_position = -50;
            } else {
                x_position = x_position - 1;
        }
        }
        if (direction_input == 'a'){
            if (y_position <= -50){
                cout << "You can't go any further than this!" << endl;
                y_position = -50;
            } else {
                y_position = y_position - 1;
        }
        }
        if (direction_input == 'd'){
            if (y_position >= 50){
                cout << "You can't go any further than this!" << endl;
                y_position = 50;
            } else {
                y_position = y_position +1;
        }
        }
        if (direction_input != 'a' && direction_input != 'w' && direction_input != 's' && direction_input != 'd'){
            cout << "Incorrect choice!" << endl;
            direction_input = 'X';
            PressEnter();
        }
        battle_initiator = rand() % 100; //Generates a number between 0 and 99
            if (battle_initiator > 75){ //If above 60 then it initiates this code.
                cout << "/nAn enemy appeared!" << endl;
                enemy_picker = rand() % 5 + 1;
                if (enemy_picker == 1){
                    battle("Rat", 5, 10, 15, 10);
                }
                if (enemy_picker == 2){
                    battle("Cat", 12, 7, 19, 8);
                }
                if (enemy_picker == 3){
                    battle ("Bat", 9, 6, 15, 22);
                }
                if (enemy_picker == 4){
                    battle ("Panther", 15, 9, 24, 33);
                }
                if (enemy_picker == 5){
                    battle ("Tiger", 20, 12, 15, 40);
                }
            }
    }
}
