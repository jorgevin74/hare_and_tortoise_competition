//Name : Jorge Auquilla
//Course: CSCI 135 
//Assignment : Project 3 Task B
//Instructor : Tong Yi

//This program is very similar to project 3, task a which would allow us to
//take the code from the previous assignment and adjust it so that it would
//work for the tortoise instead of the hare
//also bringing in a new hpp file that allows us to use the new 
//functions available for the tortoise





#include "Tortoise.hpp"
#include <iostream>
#include <vector>
using namespace std;


/////////////////////////////
//                         //
//   code starts below!    //
//                         //
/////////////////////////////



Tortoise::Tortoise(){
    Tortoise::position = 0;
    Tortoise::patterns = {3,3,3,3,3,-6,-6,1,1,1};
}

Tortoise::Tortoise(int* arr, int size, int position){
    for(int i = 0; i < size; i++){
        patterns.push_back(arr[i]);
    }
    Tortoise::position = position;
}

Tortoise::Tortoise(vector<int> patterns, int position){
    Tortoise::position = position;
    Tortoise::patterns = patterns;
}


void Tortoise::move(){
    //randomizes a number from [0. size of patterns)
    int randnum = rand() % (Tortoise::patterns.size());

//updates the position of the Hare after the number is randomized
    Tortoise::position = Tortoise::position + patterns[randnum];  

    if(position < 0){
        position = 0;
    }
}

int Tortoise::getPosition() const{
    return Tortoise::position;
}

void Tortoise::setPosition(int position){
    Tortoise::position = position;
}



