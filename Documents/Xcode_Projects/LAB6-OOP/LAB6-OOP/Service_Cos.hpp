//
//  Service_Cos.hpp
//  LAB6-OOP
//
//  Created by Dragos Mihai Prodan on 02/05/2018.
//  Copyright © 2018 Dragos Mihai Prodan. All rights reserved.
//

#ifndef Service_Cos_hpp
#define Service_Cos_hpp

#include <stdio.h>
#include "Cos.hpp"
#include "Exceptii.cpp"
#include <fstream>

class Service_Cos {
    class cos c;
    std::vector<Errore> Errors;
    
public:
    int sizeCos(){
        return c.sizeCos();
    }
    
    void adauga(int id, std::vector<oferta> a){
        try {
            if (id < 0) {
                throw TypeErrore("Nu exista oferte cu id negativ\n");
            }
            if (id > a.size()) {
                throw TypeErrore("Nu exista acea oferta.\n");
            }
            c.adaugaCos(a[id]);
        } catch (TypeErrore err) {
            Errors.push_back(err);
        }
    }
    void sterge(){
        c.stergeCos();
    }
    void randomCos(const int cate, const std::vector<oferta> vec){
        try {
            if (cate < 1) {
                throw ValidationErrore("Numarul nu poate fi mai mic de 1.\n");
            }
            c.genereazaCos(cate, vec);
        } catch (ValidationErrore err) {
            Errors.push_back(err);
        }
    }
    const std::vector<Errore> returnErrors(){
        return Errors;
    }
    void clearErrors(){
        Errors.clear();
    }
    
    void fileCos(){
        std::ofstream fout;
        fout.open("cos.csv");
        for (oferta el : c.returnVector()) {
            char x[20];
            el.getDestinatie(x);
            fout<<x<<";";
            el.getNume(x);
            fout<<x<<";";
            el.getTip(x);
            fout<<x<<";";
            fout<<el.getPret();
            fout<<std::endl;
        }
        fout.close();
    }
};

#endif /* Service_Cos_hpp */
