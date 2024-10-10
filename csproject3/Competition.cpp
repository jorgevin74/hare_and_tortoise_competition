//Name: Jorge Auquilla
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: PROJECT 3, TASK D
//This program finalizes everything we have been building up to with the past couple of tasks in this project
//This uses the functions created in previous assignments and then uses them to be able to fully finish the competition / game
// below is the play function where we see the race come to fruition

#include "Competition.hpp"
#include "Hare.hpp"
#include "Tortoise.hpp"
#include "Road.hpp"
using namespace std;
#include <iostream>


/////////////////////////////////
////                         ///
////   code starts below!    ////
////                         ////
/////////////////////////////////


Competition::Competition() : rabbit(), tor(), lane() {


    
}


Competition::Competition(Hare coney, Tortoise cooter, int length) : rabbit(coney), tor(cooter), lane(length) {

}

void Competition::play(){    

    //finds and initializes the last block of the road
    int lastBlock = lane.length() - 1;
    //declares the variable round and sets it to be 1 to represent the amount of rounds in the competitio
    int round = 1;
    
    //this is saying that as long as neither rabbit or tortoise reaches the end, they both can continue playing
    while(rabbit.getPosition() < lastBlock && tor.getPosition() < lastBlock){
        // moves the rabbit 
        rabbit.move();
        //if the rabbits position is smaller than the index of the first block of lane, then places the rabbit to the first block of lane
        if(rabbit.getPosition() < 0){
            //this sets rabbit to be the first block
            rabbit.setPosition(0);
        }
        //if the rabbit's position is larger than the last block, then set it's position to be the last block
        else if(rabbit.getPosition() > lastBlock){
            //this sets the position of the rabbit to be the last block
            rabbit.setPosition(lastBlock);
        }
        //leavbes a mark 'H' on it's corresponding block
        lane.mark(rabbit.getPosition(), 'H');

        //moves the tortoise
        tor.move();
        //if the tortoise's position is smaller than the first index, make it set it's position to the first block
        if(tor.getPosition() < 0){
            //sets the position to be the first block 
            tor.setPosition(0);
        }
        // otherwise, if the tortoises position is greater than the last block, set it's position to be the last block
        else if(tor.getPosition() > lastBlock){
            // sets the position to be the last block
            tor.setPosition(lastBlock);
        }
        // leaves a mark 'T' on it's corresponding block
        lane.mark(tor.getPosition(), 'T');

        //prints out the round number 
        cout << "Round   " << round << ": ";
        //displays the values of each element of lane
        lane.display();

        //if both the rabbit and the tortoise have the same position, then it prints out a statement saying the hare was bitten by the tortoise
        if(rabbit.getPosition() == tor.getPosition()){
            cout << "Ouch. Tortoise bites hare." << endl;       
        }
        // cleans the marks left by the round that was current 
        for(int i = 0; i <= lastBlock; i++){
            lane.mark(i, ' ');
        }
        //increases the round by 1
        round++;
        //does it all over again until one of them crosses the finish line or both do
    }

    // if both cross the finish line, it is a tie
    if(rabbit.getPosition() >= lastBlock && tor.getPosition() >= lastBlock) {
        cout << "It's a tie!" << endl;
    }
    // if the rabbit crosses the finish line, then it wins
    else if(rabbit.getPosition() >= lastBlock){
        cout << "The Hare Wins!" << endl;
    }
    // otherwise the tortoise wins if the previous functions aren't met
    else{
        cout << "The Tortoise Wins!" << endl;
    }
    //ends the play function
}