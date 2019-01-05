//
//  Repo.hpp
//  LAB6-OOP
//
//  Created by Dragos Mihai Prodan on 13/04/2018.
//  Copyright © 2018 Dragos Mihai Prodan. All rights reserved.
//

#ifndef Repo_hpp
#define Repo_hpp

#include <stdio.h>
#include "Domain.hpp"
#include <vector>
//#include "Vector.hpp"

class Repo {
    std::vector<oferta> vct {};
    
public:
    Repo(){
        oferta a{"AmericaTravel", "America", "Trip", 22};
        vct.push_back(a);
    }
    //Add object a to repo
    void adauga(oferta a);
    //Del object a from repo
    void sterge(oferta a);
    //Modify object a from repo
    void modifica(oferta a, oferta b);
    //Return a object with name nume
    oferta& returnare(char nume[20]);
    //Return a object with index id
    oferta& returnareid(unsigned id);
    
    void stergel(oferta a);
    
    std::vector<oferta> returnVector(){
        return this->vct;
    }
};

#endif /* Repo_hpp */
