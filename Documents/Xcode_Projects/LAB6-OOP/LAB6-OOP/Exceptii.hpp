//
//  Exceptii.hpp
//  LAB6-OOP
//
//  Created by Dragos Mihai Prodan on 02/05/2018.
//  Copyright © 2018 Dragos Mihai Prodan. All rights reserved.
//

#ifndef Exceptii_hpp
#define Exceptii_hpp

#include <stdio.h>
#include <string>

class Errore {
    std::string message;
    
public:
    Errore(std::string data){
        this->message = data;
    }
    const std::string getMessage() const {
        return this->message;
    }
};

class ValidationErrore: public Errore {
public:
    ValidationErrore(std::string data) : Errore(data){}
};

class TypeErrore: public Errore {
public:
    TypeErrore(std::string data) : Errore(data){}
};

#endif /* Exceptii_hpp */
