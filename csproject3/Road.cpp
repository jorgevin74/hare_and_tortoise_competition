//Name: Jorge Auquilla
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: PROJECT 3, TASK C

//This program begins to focus on the road constructors and then it would 
//be a similar process to how everything was done in the perevious tasks where tortoise and
//the hare files were done, then we would create a cpp file where we would need to 
//fill in all of the functions that were created and be able to test them all to see if they
//run properly

#include "Road.hpp"
#include <iostream>
using namespace std;

/////////////////////////////////
////                         ///
////   code starts below!    ////
////                         ////
/////////////////////////////////

//initializes blocks to be 70 with empty characters
Road::Road(){
    for(int i = 0; i < 70; i++){
        blocks.push_back(' ');
    }
}

// returns the length of the road
Road::Road(int length){
    if(length < 0){
        length = 70;
    }
    for(int i = 0; i < length; i++){
        blocks.push_back(' ');
    }
}

//marks the indexes with the proper characters
void Road::mark(int index, char ch){
    if(index < blocks.size() && index >= 0){
        blocks[index] = ch;
    }
}

//displays the entire blocks vector
void Road::display() const{

    for(int i = 0; i < blocks.size(); i++){
        cout << blocks[i];
    }
    cout << endl;
}
//returns the length of the vector blocks
int Road::length() const{
    return blocks.size();
}

       

