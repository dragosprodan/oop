//
//  Repo.cpp
//  LAB6-OOP
//
//  Created by Dragos Mihai Prodan on 13/04/2018.
//  Copyright © 2018 Dragos Mihai Prodan. All rights reserved.
//

#include "Repo.hpp"




void Repo::adauga(oferta a){
    this->vct.push_back(a);
}
/*
bool apartine(oferta a){
    char aux[20], aux2[20];
    a.getNume(aux2);
    if (strcmp(aux, aux2) == 0){
        return true;
    }
    return false;
}
 */

//void Repo::stergel(oferta a){
//    std::vector<oferta>::iterator it = std::find_if(vct.begin(), vct.end(), [a](oferta b) -> bool {if(a == b) return true; else return false;});
//    this->vct.erase(it);
//}

void Repo::modifica(oferta a, oferta b){
    this->sterge(a);
    this->adauga(b);
}

oferta& Repo::returnare(char nume[20]){
    for (unsigned i = 0; i<this->vct.size(); i++) {
        char aux[20];
        this->vct[i].getNume(aux);
        if (strcmp(nume, aux) == 0) {
            return this->vct[i];
        }
    }
    oferta a;
    return a;
}

oferta& Repo::returnareid(unsigned id){
    if (id > vct.size()) {
        oferta a;
        return a;
    }
    return this->vct[id];
}
void Repo::sterge(oferta a){
    /*for (unsigned i = 0; i<this->vct.size(); i++) {
        char aux[20], aux2[20];
        this->vct[i].getNume(aux);
        a.getNume(aux2);
        if (strcmp(aux, aux2) == 0) {
            //vct[i].setPret(NULL);
            this->vct.erase(vct.begin()+i);
        }
    }*/
    char aux[20], aux2[20];
    a.getNume(aux2);
    int i=0;
    for (oferta el : vct) {
        el.getNume(aux);
        i++;
        if (strcmp(aux, aux2) == 0) {
            this->vct.erase(vct.begin()+i-1);
        }
    }
    
}

