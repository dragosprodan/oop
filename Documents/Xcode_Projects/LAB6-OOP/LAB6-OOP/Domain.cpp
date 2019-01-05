//
//  Domain.cpp
//  LAB6-OOP
//
//  Created by Dragos Mihai Prodan on 13/04/2018.
//  Copyright © 2018 Dragos Mihai Prodan. All rights reserved.
//

#include "Domain.hpp"
#include <iostream>
#include <string>

oferta::oferta(char num[20], char des[20], char tp[20], int pt){
    strcpy(nume, num);
    strcpy(destinatie, des);
    strcpy(tip, tp);
    pret = pt;
}

oferta::oferta(const oferta &x){
    strcpy(nume, x.nume);
    strcpy(destinatie, x.destinatie);
    strcpy(tip, x.tip);
    pret= x.pret;
    //std::cout<<"ok ";
}

oferta::oferta(){
    pret = 0;
}

int& oferta::getPret(){
    return this->pret;
}

void oferta::getNume(char nume[20]){
    strcpy(nume, this->nume);
}

void oferta::getDestinatie(char dest[20]){
    strcpy(dest, this->destinatie);
}

void oferta::getTip(char tp[20]){
    strcpy(tp, this->tip);
}

void oferta::setPret(int pret){
    this->pret = pret;
}

void oferta::setNume(char nume[20]){
    strcpy(this->nume, nume);
}

void oferta::setDestinatie(char dest[20]){
    strcpy(this->destinatie, dest);
}

void oferta::setTip(char tp[20]){
    strcpy(this->tip, tp);
}

bool oferta::operator==(const oferta& sec) const{
    //char verificare[20], verificare2[20];
    /*
    if (this->pret == sec.pret) {
        return false;
    }
    */
    if (strcmp(this->nume, sec.nume) != 0) {
        return false;
    }
    /*
    if (strcmp(this->destinatie, sec.destinatie) == 0) {
        return false;
    }
    if (strcmp(this->tip, sec.tip) == 0) {
        return false;
    }
    */
    return true;
}


