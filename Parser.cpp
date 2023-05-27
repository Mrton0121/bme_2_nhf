//
// Created by gombi on 2023.05.15..
//
#include <iostream>
#include <fstream>
#include <string>
#include "Parser.h"
#include "edge.h"
#include <list>

using namespace std;

void Parser::Load() {
    cout << "Please provide the file path!\n"
            "It can be either a relative or absolute path. The file extension must be included!" << endl;
    cout << "Path: ";
    string path;
    cin >> path;
    ifstream input( path );
    if(input.fail()){
        cerr << "Couldn't open file!" << endl;
        system("pause");
        exit(176655/*@bme.hu*/);
    }
    else{
        for( std::string line; getline( input, line ); )
        {
            this->data->push(new string(line));
        }
        cout << "##### LOAD LOG #####" << endl;
        for(int i = 0; i < this->data->length(); i++){
            cout << i+1 << ": " << *this->data->elements()[i] << endl;
        }
    }
}

void Parser::Parse(TextureList *textures, Config *config) {
    cout << "##### PARSE LOG #####" << endl;
    list<NodeData> *nodes = new list<NodeData>;
    int i = 0;
    for(i = 0; i < this->data->length(); i++){
        string *line = this->data->elements()[i];
        if(*line == "" || line->find_first_of("#") == 0) continue;
        else{ //nem üres sor és nem komment
            if(line->find_first_of("*:") == 0){
                //csúcs
                string value = line->substr(line->find(":")+1,line->length()-1);
                NodeData temp = NodeData(value,config->getNodeC());
                Node *nTemp = new Node(temp);
                textures->push(nTemp);
                cout << "node: " << value << " - done" <<  endl;
                nodes->push_back(temp);
            }
            else if(line->find_first_of("(") == 0 && line->find_last_of(")") == line->length()-1){
                //hurokél
                string *value = new string(line->substr(line->find("(") + 1, line->find(")") - 1));
                for (const NodeData& obj : *nodes) {
                    if (*obj.getId() ==  *value) {
                        NodeData *temp = new NodeData(obj);
                        textures->push(new Edge(EdgeData(temp, config->getEdgeC()) ) );
                        delete temp;
                        break;
                    }
                }

                cout << "loop edge: " << *value  << " - done" << endl;
                delete value;
            }
            else if(line->find_first_of("[") == 0 && line->find_last_of("]") == line->length()-1){
                //irányított
                string *first = new string(line->substr(line->find("[")+1 ,line->find(",")-1));
                string *second = new string(line->substr(line->find(",")+1, line->find("]") - line->find(",") -1));
                cout << "###:" << *first << endl;
                cout << "###:" << *second << endl;
                //TODO változó id hossz
                NodeData *fN, *sN;
                for (const NodeData& obj : *nodes) {
                    if (*obj.getId() ==  *first) {
                        fN = new NodeData(obj);
                        break;
                    }
                }
                for (const NodeData& obj : *nodes) {
                    if (*obj.getId() ==  *second) {
                        sN = new NodeData(obj);
                        break;
                    }
                }
                textures->push(new Edge(EdgeData(fN,sN,DIRECTED,config->getEdgeC())));
                cout << "directed edge: " << *first << "->" << *second  << " - done"<< endl;
                delete first;
                delete second;
                delete fN;
                delete sN;
            }
            else if(line->find_first_of("{") == 0 && line->find_last_of("}") == line->length()-1){
                //sima
                string *first = new string(line->substr(line->find("{")+1 ,line->find(",")-1));
                string *second = new string(line->substr(line->find(",")+1, line->find("}") - line->find(",") -1));
                NodeData *fN, *sN;
                for (const NodeData& obj : *nodes) {
                    if (*obj.getId() ==  *first) {
                        fN = new NodeData(obj);
                        break;
                    }
                }
                for (const NodeData& obj : *nodes) {
                    if (*obj.getId() ==  *second) {
                        sN = new NodeData(obj);
                        break;
                    }
                }
                textures->push(new Edge(EdgeData(fN,sN,SIMPLE,config->getEdgeC())));
                cout << "edge: " << *first << "--" << *second << " - done"<< endl;
                delete first;
                delete second;
                delete fN;
                delete sN;
            }
        }
    }
    delete nodes;
}