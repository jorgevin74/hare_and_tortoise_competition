//Name : Jorge Auquilla
//Course: CSCI 135 
//Assignment : Project 3 Task A
//Instructor : Tong Yi

//This program is the Hare.cpp the add on sort to say for Hare.hpp where you can see that Hare.hpp
//is included so we are able to use the construtors inside of the class Hare, now what this file does is fill in what
//goes inside each of the constructor functions and be able to do as what is asked of them
//and the comments alongside the code displays what each function does and what they return



#include "Hare.hpp"
#include <iostream>
#include <vector>
using namespace std;


/////////////////////////////
//                         //
//   code starts below!    //
//                         //
/////////////////////////////


Hare::Hare(){
    Hare::position = 0;
    Hare::patterns = {0,0,9,9,-12,1,1,1,-2,-2};
}

// this sets creates a new hare where we are able to declare the position and the vector for the Hare
Hare::Hare(std::vector<int> patterns, int position){
    Hare::position = position;
    Hare::patterns = patterns;
}

// creates new hare and uses the array to push back inside of the vector that was created in the private class
Hare::Hare(int* arr, int size, int position){
    for(int i = 0; i < size; i++){
        patterns.push_back(arr[i]);
    }
    Hare::position = position;
}

//moves the position of the hare randomly from [0, size_of_patterns]
void Hare::move(){

    //randomizes a number from [0. size of patterns)
    int randnum = rand() % (Hare::patterns.size());

//updates the position of the Hare after the number is randomized
    Hare::position = Hare::position + patterns[randnum];  

    if(position < 0){
        position = 0;
    }
}

// returns an integer which is the position of where the Hare currently is
int Hare::getPosition() const{
    return Hare::position; // grabs the position of the hare that was privately declared and can be used inside of the main function to recieve the current position
}

// void doesn't return anything but rather this changes position that was set inside class to a different one that the user desires
void Hare::setPosition(int position){
    Hare::position = position; // makes it so class position changes to user position that was inputed  
}



