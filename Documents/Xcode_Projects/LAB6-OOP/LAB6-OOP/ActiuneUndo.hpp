//
//  ActiuneUndo.hpp
//  LAB6-OOP
//
//  Created by Dragos Mihai Prodan on 09/05/2018.
//  Copyright © 2018 Dragos Mihai Prodan. All rights reserved.
//

#ifndef ActiuneUndo_hpp
#define ActiuneUndo_hpp

#include <stdio.h>
#include "Domain.hpp"
#include "Repo.hpp"


class ActiuneUndo {    
public:
    oferta el;
    //oferta getElement(){
    //    return this->el;
    //}
    
    virtual Repo doUndo(Repo r){
        return r;
    }
};

class UndoAdauga: public ActiuneUndo {
public:
    UndoAdauga(oferta element);
    Repo doUndo(Repo r){
        r.sterge(this->el);
        return r;
    }
};


class UndoSterge: public ActiuneUndo {
public:
    UndoSterge(oferta el);
    Repo doUndo(Repo r){
        r.adauga(this->el);
        return r;
    }
};

class UndoModifica: public ActiuneUndo {
public:
    UndoModifica(oferta el);
    Repo doUndo(Repo r){
        r.sterge(r.returnareid(r.returnVector().size()));
        r.adauga(this->el);
        return r;
    }
};
#endif /* ActiuneUndo_hpp */
