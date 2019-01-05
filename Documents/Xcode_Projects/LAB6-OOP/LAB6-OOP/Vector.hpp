//
//  Vector.hpp
//  LAB6-OOP
//
//  Created by Dragos Mihai Prodan on 17/04/2018.
//  Copyright © 2018 Dragos Mihai Prodan. All rights reserved.
//

#ifndef Vector_hpp
#define Vector_hpp

#include <stdio.h>

template <typename DataType>
struct nod {
    DataType elem;
    struct nod* urmator;
};


template <typename DataType>
class Vector {
    struct nod<DataType>* start;
    int lungime;
    
public:
    //Constructor
    Vector(){
        this->start=new struct nod<DataType>;
        this->lungime = 0;
    }
    //Operator for []
    DataType& operator[](int index){
        struct nod<DataType>* aux = start;
        for (int i = 0;i < index; i++) {
            aux = aux->urmator;
        }
        return aux->elem;
    }
    
    //Add one object to the back
    void push_back(const DataType a){
        struct nod<DataType>* aux = start;
        int x= lungime;
        while (x > 1) {
            aux = aux->urmator;
            x--;
        }
        aux->elem = a;
        aux->urmator = new struct nod<DataType>;
        this->lungime++;
    }
    
    //Erase one object from the vector by index
    void erase(const unsigned int index){
        struct nod<DataType>* aux = start;
        if (index > 0) {
            for (int i = 0;i < index-1; i++) {
                aux = aux->urmator;
            }
        }
        struct nod<DataType>* gunoi = aux->urmator;
        aux->urmator = aux->urmator->urmator;
        free(gunoi);
        this->lungime--;
    }
    
    //Return the index for the first object in vector
    int begin(){
        return 0;
    }
    //Return the size of the vector
    int size(){
        return this->lungime;
    }
    
    //Destructor
    ~Vector(){
        int a =this->lungime, b =this->lungime;
        struct nod<DataType>* aux = this->start;
        for (int j = 0; j< a; j++) {
            for (int i=0; i<b; i++) {
                aux = aux->urmator;
            }
            b--;
            a--;
            //free(aux);
            //delete aux;
        }
        //delete this->start;
        //free(this->start);
    }
};

#endif /* Vector_hpp */
