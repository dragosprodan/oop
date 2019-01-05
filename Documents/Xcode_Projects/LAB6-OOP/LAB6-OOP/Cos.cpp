//
//  Cos.cpp
//  LAB6-OOP
//
//  Created by Dragos Mihai Prodan on 02/05/2018.
//  Copyright © 2018 Dragos Mihai Prodan. All rights reserved.
//

#include "Cos.hpp"


void cos::adaugaCos(const oferta& var){
    this->vct.push_back(var);
};
void cos::stergeCos(){
    /*for (unsigned i = 0; i<this->vct.size(); i++) {
        char aux[20], aux2[20];
        this->vct[i].getNume(aux);
        var.getNume(aux2);
        if (strcmp(aux, aux2) == 0) {
            this->vct.erase(vct.begin()+i);
        }*/
    this->vct.clear();
}
void cos::genereazaCos(const int cate, std::vector<oferta> vec){
    std::mt19937 mt{ std::random_device{}() };
    std::uniform_int_distribution<> dist(0, 5);
    //oferta a {this->numeRandom[dist(mt)].a, this->locatie[dist(mt)].a, this->tipRandom[dist(mt)].a, rndNr};
    for (int i =0; i<cate; i++) {
        int rndNr = dist(mt);
        this->adaugaCos(vec[rndNr]);
    }
    
    
}
