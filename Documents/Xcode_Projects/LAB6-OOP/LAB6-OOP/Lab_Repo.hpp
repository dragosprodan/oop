//
//  main.cpp
//  RepoGeneral
//
//  Created by Dragos Mihai Prodan on 10/05/2018.
//  Copyright © 2018 Dragos Mihai Prodan. All rights reserved.
//

#include <iostream>
#include <vector>

class Errore2 {
    std::string message;
    
public:
    Errore2(std::string data){
        this->message = data;
    }
    const std::string getMessage() const {
        return this->message;
    }
};

class ValidationErrore2: public Errore2 {
public:
    ValidationErrore2(std::string data) : Errore2(data){}
};


template <typename DataType>
struct element {
    DataType el;
    unsigned int id;
};

template <typename TemplateObject>
class Repo2 {
    std::vector<element<TemplateObject>> vct;
public:
    
    virtual void adauga(element<TemplateObject> a) =0;
    /*{
     this->vct.push_back(a);
     }*/
    
    virtual void sterge(element<TemplateObject> a) =0;
    /*{
     int i=0;
     for (element<TemplateObject> el : vct) {
     if (el == a) {
     this->vct.erase(vct.begin()+i-1);
     }
     i++;
     }
     }*/
    
    virtual void modifica(element<TemplateObject> a, element<TemplateObject> b) =0;
    /*{
     this->sterge(a);
     this->adauga(b);
     }*/
    
    //virtual element<TemplateObject> returnare(char nume[20]) =0;
    virtual element<TemplateObject> returnareid(unsigned id) =0;
    //virtual std::vector<element<TemplateObject>> returnVector() =0;
    /*{
     return this->vct;
     }*/
    
};

template <typename TemplateObject>
class RepoDict: public Repo2<TemplateObject> {
    std::vector<element<TemplateObject>> vct;
    double probabilitate;
public:
    RepoDict(double prob){
        this->probabilitate=prob;
    }
    
    void adauga(element<TemplateObject> a) override{
        double rndNR = ((double)rand()/ (RAND_MAX));
        if (rndNR < probabilitate) {
            throw ValidationErrore2("Luck errore");
        }
        this->vct.push_back(a);
    }
    void sterge(element<TemplateObject> a)override{
        int i=0;
        for (element<TemplateObject> el : vct){
            if (el.el == a.el) {
                this->vct.erase(vct.begin()+i-1);
            }
            i++;
        }
    }
    void modifica(element<TemplateObject> a, element<TemplateObject> b) override{
        this->sterge(a);
        this->adauga(b);
    }
    element<TemplateObject> returnareid(unsigned id) override{
        return this->vct[id];
    }
};





/*int main() {
    RepoDict<int> a(1);
    element<int> x{10,1};
    try {
        a.adauga(x);
    } catch (ValidationErrore err) {
        std::cout<<err.getMessage()<<std::endl;
    }
    
    try {
        a.adauga(x);
        std::cout<<a.returnareid(1).el<<" ID: "<<a.returnareid(1).id<<std::endl;
    } catch (ValidationErrore err) {
        std::cout<<err.getMessage()<<std::endl;
    }
    
}*/

