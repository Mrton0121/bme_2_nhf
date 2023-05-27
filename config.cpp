//
// Created by gombi on 2023.05.25..
//

#include "config.h"
#include "string"
#include "iostream"
#include "fstream"
#include <list>

using namespace std;

Config::Config(const char* path){
    ifstream input( path );
    list<string> *tempList = new list<string>;
    if(input.fail()){
        cerr << "Couldn't open config file!" << endl;
        system("pause");
        exit(176655/*@bme.hu*/);
    }
    else{
        for( std::string line; getline( input, line ); )
        {
            tempList->push_back(line);
        }
    }
    //node:
    string *tempN = new string(tempList->front().substr(tempList->front().find(":") + 1, tempList->front().length()));
    tempList->pop_front();
    //edge:
    string *tempE = new string(tempList->front().substr(tempList->front().find(":")+1,tempList->front().length()));
    tempList->pop_front();
    //background
    string *tempB = new string(tempList->front().substr(tempList->front().find(":")+1,tempList->front().length()));
    tempList->pop_front();
    this->nodeColor = {(uint8_t)stoi(tempN->substr(0,tempN->find(","))),
                       (uint8_t)stoi(tempN->substr(tempN->find(",")+1,tempN->find_last_of(",")-1)),
                       (uint8_t)stoi(tempN->substr(tempN->find_last_of(",")+1,tempN->length()-1)),
                       100};

    this->edgeColor =  {(uint8_t)stoi(tempE->substr(0,tempE->find(","))),
                        (uint8_t)stoi(tempE->substr(tempE->find(",")+1,tempE->find_last_of(",")-1)),
                        (uint8_t)stoi(tempE->substr(tempE->find_last_of(",")+1,tempE->length()-1)),
                        100};

    this->backgroundColor =  {(uint8_t)stoi(tempB->substr(0,tempB->find(","))),
                              (uint8_t)stoi(tempB->substr(tempB->find(",")+1,tempB->find_last_of(",")-1)),
                              (uint8_t)stoi(tempB->substr(tempB->find_last_of(",")+1,tempB->length()-1)),
                            100};

    delete tempN;
    delete tempE;
    delete tempB;
    delete tempList;
}
