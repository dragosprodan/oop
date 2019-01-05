//
//  Domain.hpp
//  LAB6-OOP
//
//  Created by Dragos Mihai Prodan on 13/04/2018.
//  Copyright © 2018 Dragos Mihai Prodan. All rights reserved.
//

#ifndef Domain_hpp
#define Domain_hpp

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

class oferta {
    char nume[20], destinatie[20], tip[20];
    int pret;
    
public:
    //Constructors
    oferta();
    oferta(char num[20], char des[20], char tp[20], int pt);
    oferta(const oferta &x);
    
    //oferta(std::string num, std::string des, std::string tp, int pret);
    
    //Get pret
    int& getPret(void);
    //Get nume
    void getNume(char nume[20]);
    //Get destinatie
    void getDestinatie(char dest[20]);
    //Get tip
    void getTip(char tip[20]);
    
    //Set pret
    void setPret(int pret);
    //Set nume
    void setNume(char nume[20]);
    //Set destinatie
    void setDestinatie(char dest[20]);
    //Set tip
    void setTip(char tip[20]);
    
    bool operator == (const oferta& sec) const;
};

#endif /* Domain_hpp */
