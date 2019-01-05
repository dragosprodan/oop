//
//  Cos.hpp
//  LAB6-OOP
//
//  Created by Dragos Mihai Prodan on 02/05/2018.
//  Copyright © 2018 Dragos Mihai Prodan. All rights reserved.
//

#ifndef Cos_hpp
#define Cos_hpp

#include <stdio.h>
#include <vector>
#include "Domain.hpp"
#include <algorithm>
#include <random>
#include <chrono>

//struct m{
//    char  a[20];
//};



class cos {
    //m a1 {"DubaiTravel"}, a2 {"SwidenTravel"}, a3 {"CanadaTravel"}, a4 {"PolandTravel"}, a5{"GermanyTravel"}, a6{"GermanyTravel"}, a7{"HollandTravel"}, a8{"ItalyTravel"}, a9{"TurkeyTravel"};
    //m b1 {"Dubai"}, b2 {"Swiden"}, b3 {"Canada"}, b4 {"Poland"}, b5{"Germany"}, b6{"Germany"}, b7{"Holland"}, b8{"Italy"}, b9{"Turkey"};
    //m c1{"Trip"}, c2{"Camp"}, c3{"Concert"};
    
    //std::vector<m> numeRandom {a1,a2,a3,a4,a5,a6,a7,a8,a9};
    //std::vector<m> tipRandom  {c1,c2,c3,c1,c2,c3,c1,c2,c3};
    //std::vector<m> locatie    {b1,b2,b3,b4,b5,b6,b7,b8,b9};
    std::vector<oferta> vct {};
    
public:
    void adaugaCos(const oferta& var);
    void stergeCos();
    void genereazaCos(const int cate, const std::vector<oferta> vec);
    unsigned long sizeCos(){
        return this->vct.size();
    }
    std::vector<oferta> returnVector(){
        return this->vct;
    }
    
};

#endif /* Cos_hpp */
