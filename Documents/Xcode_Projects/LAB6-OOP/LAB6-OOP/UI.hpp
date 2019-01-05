//
//  UI.hpp
//  LAB6-OOP
//
//  Created by Dragos Mihai Prodan on 17/04/2018.
//  Copyright © 2018 Dragos Mihai Prodan. All rights reserved.
//

#ifndef UI_hpp
#define UI_hpp

#include <iostream>
#include <stdio.h>
#include "Service.hpp"
#include "Service_Cos.hpp"
#include <string>
#include "ActiuneUndo.hpp"

class UI {
    Service s;
    Service_Cos sc;
    
public:
    void run();
    int citireint();
    void meniu();
    void citirechar(char aux[20]);
};

#endif /* UI_hpp */
