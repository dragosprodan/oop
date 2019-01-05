//
//  Service.cpp
//  LAB6-OOP
//
//  Created by Dragos Mihai Prodan on 13/04/2018.
//  Copyright © 2018 Dragos Mihai Prodan. All rights reserved.
//

#include "Service.hpp"

void Service::add(oferta a){
    try {
        if (a.getPret() <= 0) {
            throw ValidationErrore("Pret prea mic.\n");
        }
        int i=0;
        while (1) {
            if (this->r.returnareid(i).getPret() != 0) {
                if (a == r.returnareid(i)) {
                    throw ValidationErrore("Oferta deja exista.\n");
                }
                i++;
            } else {
                break;
            }
        }
        this->r.adauga(a);
    } catch (ValidationErrore err) {
        Err.push_back(err);
    }
}

void Service::del(oferta a){
    this->r.sterge(a);
}

void Service::cng(oferta a, oferta b){
    this->r.sterge(a);
    this->r.adauga(b);
}

void Service::rta(std::string &oferte){
    /*unsigned i =0;
    while (1) {
        if (this->r.returnareid(i).getPret() != 0) {
            char nume[20];
            this->r.returnareid(i).getNume(nume);
            oferte.std::string::append(nume);
            oferte.std::string::append(", ");
            this->r.returnareid(i).getDestinatie(nume);
            oferte.std::string::append(nume);
            oferte.std::string::append(", ");
            this->r.returnareid(i).getTip(nume);
            oferte.std::string::append(nume);
            oferte.std::string::append(", ");
            int x = this->r.returnareid(i).getPret();
            std::string aux = std::to_string(x);
            oferte.std::string::append(aux);
            oferte.std::string::append("\n");
            
            i++;
        } else {
            break;
        }
    }*/
    
    for (oferta el : this->returnRepo().returnVector()){
        char nume[20];
        el.getNume(nume);
        oferte.std::string::append(nume);
        oferte.std::string::append(", ");
        el.getDestinatie(nume);
        oferte.std::string::append(nume);
        oferte.std::string::append(", ");
        el.getTip(nume);
        oferte.std::string::append(nume);
        oferte.std::string::append(", ");
        int x = el.getPret();
        std::string aux = std::to_string(x);
        oferte.std::string::append(aux);
        oferte.std::string::append("\n");
    }
}

void Service::fld(std::string &oferte, char dest[20]){
    unsigned i =0;
    while (1) {
        if (this->r.returnareid(i).getPret() != 0) {
            char aux[20];
            this->r.returnareid(i).getDestinatie(aux);
            if (strcmp(aux, dest) == 0) {
                char nume[20];
                this->r.returnareid(i).getNume(nume);
                oferte.std::string::append(nume);
                oferte.std::string::append(", ");
                this->r.returnareid(i).getDestinatie(nume);
                oferte.std::string::append(nume);
                oferte.std::string::append(", ");
                this->r.returnareid(i).getTip(nume);
                oferte.std::string::append(nume);
                oferte.std::string::append(", ");
                int x = this->r.returnareid(i).getPret();
                std::string aux = std::to_string(x);
                oferte.std::string::append(aux);
                oferte.std::string::append("\n");
                aux = "";
            }
            i++;
        } else {
            break;
        }
    }
}

void Service::flp(std::string &oferte, unsigned pret){
    unsigned i =0;
    while (1) {
        if (this->r.returnareid(i).getPret() != 0) {
            int aux;
            aux = this->r.returnareid(i).getPret();
            if (aux  <= pret) {
                char nume[20];
                this->r.returnareid(i).getNume(nume);
                oferte.std::string::append(nume);
                oferte.std::string::append(", ");
                this->r.returnareid(i).getDestinatie(nume);
                oferte.std::string::append(nume);
                oferte.std::string::append(", ");
                this->r.returnareid(i).getTip(nume);
                oferte.std::string::append(nume);
                oferte.std::string::append(", ");
                int x = this->r.returnareid(i).getPret();
                std::string aux = std::to_string(x);
                oferte.std::string::append(aux);
                oferte.std::string::append("\n");
                aux = "";
            }
            i++;
        } else {
            break;
        }
    }
}

void Service::std(std::string &oferte){
    char aux[]="aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
    unsigned i = 0, j = 0;
    for (j = 0; j < 52; j++) {
        while (1) {
            if (this->r.returnareid(i).getPret() != 0) {
                char aux2[20];
                this->r.returnareid(i).getDestinatie(aux2);
                if (aux2[0] == aux[j]) {
                    char nume[20];
                    this->r.returnareid(i).getNume(nume);
                    oferte.std::string::append(nume);
                    oferte.std::string::append(", ");
                    this->r.returnareid(i).getDestinatie(nume);
                    oferte.std::string::append(nume);
                    oferte.std::string::append(", ");
                    this->r.returnareid(i).getTip(nume);
                    oferte.std::string::append(nume);
                    oferte.std::string::append(", ");
                    int x = this->r.returnareid(i).getPret();
                    std::string aux = std::to_string(x);
                    oferte.std::string::append(aux);
                    oferte.std::string::append("\n");
                    aux = "";
                }
                i++;
            } else {
                break;
            }
        }
        i=0;
    }
}

void Service::stp(std::string &oferte){
    unsigned i=0;
    while (1) {
        if (r.returnareid(i).getPret() != 0) {
            i++;
        } else {
            break;
        }
    }
    unsigned len = i, k=0;
    int min= 999999, auxmin=0;
    
    for (i=0; i< len; i++) {
        for (unsigned j=0; j< len; j++) {
            if (r.returnareid(j).getPret() < min && r.returnareid(j).getPret() > auxmin) {
                min = r.returnareid(j).getPret();
                k=j;
            }
        }
        
        char nume[20];
        this->r.returnareid(k).getNume(nume);
        oferte.std::string::append(nume);
        oferte.std::string::append(", ");
        this->r.returnareid(k).getDestinatie(nume);
        oferte.std::string::append(nume);
        oferte.std::string::append(", ");
        this->r.returnareid(k).getTip(nume);
        oferte.std::string::append(nume);
        oferte.std::string::append(", ");
        int x = this->r.returnareid(i).getPret();
        std::string aux = std::to_string(x);
        oferte.std::string::append(aux);
        oferte.std::string::append("\n");
        aux = "";
        
        auxmin = min;
    }
}

void Service::rfi(std::string &oferte, char x[20]){
    char nume[20];
    this->r.returnare(x).getNume(nume);
    oferte.std::string::append(nume);
    oferte.std::string::append(", ");
    this->r.returnare(x).getDestinatie(nume);
    oferte.std::string::append(nume);
    oferte.std::string::append(", ");
    this->r.returnare(x).getTip(nume);
    oferte.std::string::append(nume);
    oferte.std::string::append(", ");
    int y = this->r.returnare(x).getPret();
    std::string aux = std::to_string(y);
    oferte.std::string::append(aux);
    oferte.std::string::append("\n");
    //aux = "";
}

void Service::sde(std::string &oferte){
    char aux[]="aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
    unsigned i = 0, j = 0;
    for (j = 0; j < 52; j++) {
        while (1) {
            if (this->r.returnareid(i).getPret() != 0) {
                char aux2[20];
                this->r.returnareid(i).getNume(aux2);
                if (aux2[0] == aux[j]) {
                    char nume[20];
                    this->r.returnareid(i).getNume(nume);
                    oferte.std::string::append(nume);
                    oferte.std::string::append(", ");
                    this->r.returnareid(i).getDestinatie(nume);
                    oferte.std::string::append(nume);
                    oferte.std::string::append(", ");
                    this->r.returnareid(i).getTip(nume);
                    oferte.std::string::append(nume);
                    oferte.std::string::append(", ");
                    int x = this->r.returnareid(i).getPret();
                    std::string aux = std::to_string(x);
                    oferte.std::string::append(aux);
                    oferte.std::string::append("\n");
                    aux = "";
                }
                i++;
            } else {
                break;
            }
        }
        i=0;
    }
}




