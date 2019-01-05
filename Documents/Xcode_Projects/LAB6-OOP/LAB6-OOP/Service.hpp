//
//  Service.hpp
//  LAB6-OOP
//
//  Created by Dragos Mihai Prodan on 13/04/2018.
//  Copyright © 2018 Dragos Mihai Prodan. All rights reserved.
//

#ifndef Service_hpp
#define Service_hpp

#include <stdio.h>
#include "Domain.hpp"
#include "Repo.hpp"
#include "Exceptii.hpp"

class Service {
    Repo r;
    std::vector<Errore> Err;
    
public:
    //Add oferta class to repo
    void add(oferta a);
    //Del oferta class from repo
    void del(oferta a);
    //Change oferta class with one other from repo
    void cng(oferta a, oferta b);
    //Returns one string with all the objects data.
    void rta(std::string &oferte);
    //Return a string with all the object data that have the x name
    void rfi(std::string &oferte, char x[20]);
    //Return a string with all the object data that have the dest destinatie
    void fld(std::string &oferte, char dest[20]);
    //Return a string with all the object data that have the pret pret
    void flp(std::string &oferte, unsigned pret);
    //Return a string sorted by name
    void std(std::string &oferte);
    //Return a string sorted by destinatie
    void sde(std::string &oferte);
    //Return a string sorrted by pret
    void stp(std::string &oferte);
    
    Repo returnRepo(){
        return this->r;
    }
    
    void setRepo(Repo rep){
        this->r=rep;
    }
    
    std::vector<Errore> getErrors(){
        return this->Err;
    }
    
    void clearErrors(){
        Err.clear();
    }
};



#endif /* Service_hpp */
