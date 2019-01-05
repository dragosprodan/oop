//
//  Test.cpp
//  LAB6-OOP
//
//  Created by Dragos Mihai Prodan on 17/04/2018.
//  Copyright © 2018 Dragos Mihai Prodan. All rights reserved.
//

#include "Test.hpp"
#include "ActiuneUndo.hpp"

void testDomain(){
    char test[] = "TEST";
    char set[] = "SET";
    char val[20];
    oferta a{test, test, test, 1};
    
    assert(a.getPret() == 1);
    a.getNume(val);
    assert(!strcmp(val,test));
    a.getDestinatie(val);
    assert(!strcmp(val,test));
    a.getTip(val);
    assert(!strcmp(val,test));
    
    a.setPret(10);
    a.setNume(set);
    a.setDestinatie(set);
    a.setTip(set);
    
    assert(a.getPret() == 10);
    a.getNume(val);
    assert(!strcmp(val,set));
    a.getDestinatie(val);
    assert(!strcmp(val,set));
    a.getTip(val);
    assert(!strcmp(val,set));
    
    class cos c;
    c.adaugaCos(a);
    c.stergeCos();
    std::vector<oferta> v {a};
    c.genereazaCos(2, v);
    
    //Teste Exceptii
    try {
        throw Errore("Test");
    } catch (Errore err) {
        err.getMessage();
    }
    try {
        throw ValidationErrore("Test");
    } catch (ValidationErrore err) {
        err.getMessage();
    }
    try {
        throw TypeErrore("Test");
    } catch (TypeErrore err) {
        err.getMessage();
    }
    
}

void testRepo(){
    Repo r;
    char test[] = "TEST";
    char set[] = "SET";
    //char val[20];
    
    oferta a{test, test, test, 3};
    oferta b{set, test, test, 2};
    oferta c{set, test, test, 2};
    oferta d{set, test, test, 2};
    r.adauga(d);
    r.adauga(c);
    r.adauga(b);
    r.adauga(a);
    
    assert(r.returnare(test).getPret() == 3);
    assert(r.returnare(set).getPret() == 2);
    
    r.sterge(a);
    
    assert(r.returnare(test).getPret() == 0);
    
    oferta k{set, test, test, 2};
    r.modifica(a, k);
    assert(r.returnare(test).getPret() == 0);
    
    ActiuneUndo tessss;
    tessss.doUndo(r);
}

void testService(){
    Service s;
    char test[] = "TEST";
    char set[] = "SET";
    oferta a{test, test, test, 3};
    oferta ka{test, test, test, 3};
    s.add(ka);
    s.add(a);
    oferta b{set, test, test, 2};
    s.add(b);
    oferta c{set,set,set,10};
    
    
    std::string x;
    s.rta(x);
    //assert(x == "TEST, TEST, TEST, 3\nSET, TEST, TEST, 2\n");
    x.clear();
    s.fld(x, test);
    //assert(x == "TEST, TEST, TEST, 3\nSET, TEST, TEST, 2\n");
    x.clear();
    s.flp(x, 3);
    //assert(x == "TEST, TEST, TEST, 3\n");
    s.add(c);
    x.clear();
    s.std(x);
    //assert(x == "SET, SET, SET, 10\nTEST, TEST, TEST, 3\nSET, TEST, TEST, 2\n");
    x.clear();
    s.stp(x);
    x.clear();
    char p[] = "TEST";
    s.rfi(x, p);
    x.clear();
    s.sde(x);
    oferta d{set,set,set,20};
    s.cng(c, d);
    s.del(d);
    
    
    //Service Cos
    Service_Cos sc;
    sc.adauga(1, s.returnRepo().returnVector());
    sc.sterge();
    sc.returnErrors();
    sc.clearErrors();
    sc.randomCos(3, s.returnRepo().returnVector());
    sc.adauga(100, s.returnRepo().returnVector());
    sc.adauga(-10, s.returnRepo().returnVector());
    sc.randomCos(-10, s.returnRepo().returnVector());
    sc.returnErrors();
    sc.clearErrors();



    




}


























