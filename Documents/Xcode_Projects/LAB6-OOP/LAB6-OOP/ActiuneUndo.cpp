//
//  ActiuneUndo.cpp
//  LAB6-OOP
//
//  Created by Dragos Mihai Prodan on 09/05/2018.
//  Copyright © 2018 Dragos Mihai Prodan. All rights reserved.
//

#include "ActiuneUndo.hpp"

UndoAdauga::UndoAdauga(oferta element){
    this->el=element;
}

UndoSterge::UndoSterge(oferta elemente){
    this->el=elemente;
}

UndoModifica::UndoModifica(oferta elemente){
    this->el=elemente;
}
