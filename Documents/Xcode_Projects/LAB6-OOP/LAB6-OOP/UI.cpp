//
//  UI.cpp
//  LAB6-OOP
//
//  Created by Dragos Mihai Prodan on 17/04/2018.
//  Copyright © 2018 Dragos Mihai Prodan. All rights reserved.
//

#include "UI.hpp"




void UI::run(){
    //Adauga obiecte
    std::vector<ActiuneUndo*> UNDO;
    char n[]="EuroTravel",d[]="Europe",t[]="Camp";
    int p=11;
    oferta est{n,d,t,p};
    s.add(est);
    char nume1[]="FrancTravel",dest1[]="France",tip1[]="Trip";
    int pret1=11;
    oferta of1{nume1, dest1, tip1, pret1};
    char nume2[]="UKTravel",dest2[]="UK",tip2[]="Trip";
    int pret2=5;
    oferta of2{nume2, dest2, tip2, pret2};
    char nume3[]="RomaniaTravel",dest3[]="Romania",tip3[]="Trip";
    int pret3=7;
    oferta of3{nume3, dest3, tip3, pret3};
    char nume4[]="SyriaTravel",dest4[]="Syria",tip4[]="Camp";
    int pret4=1;
    oferta of4{nume4, dest4, tip4, pret4};
    s.add(of1); s.add(of2); s.add(of3); s.add(of4);
    while (1) {
        meniu();
        unsigned var = citireint();
        
        if (var == 11) {
            break;
        }
        if (var == 1) {
            char nume[20], destinatie[20], tip[20];
            int pret;
            std::cout<<"Denumire: ";
            citirechar(nume);
            std::cout<<"Destinarie: ";
            citirechar(destinatie);
            std::cout<<"Tip: ";
            citirechar(tip);
            std::cout<<"Pret: ";
            pret = citireint();
            oferta a{nume, destinatie, tip, pret};
            s.add(a);
            
            UndoAdauga elem{a};
            ActiuneUndo* el;
            el = &elem;
            UNDO.push_back(el);
            //std::cout<<el->getElement().getPret();
            std::cout<<std::endl<<"Lista undo are: "<<UNDO.size()<<" elemente."<<std::endl;
            }
        if (var == 2) {
            char nume[20], destinatie[20], tip[20];
            int pret;
            std::cout<<"Denumire: ";
            citirechar(nume);
            std::cout<<"Destinarie: ";
            citirechar(destinatie);
            std::cout<<"Tip: ";
            citirechar(tip);
            std::cout<<"Pret: ";
            pret = citireint();
            oferta a{nume, destinatie, tip, pret};
            s.del(a);
            
            UndoSterge elem{a};
            ActiuneUndo* el;
            el = &elem;
            UNDO.push_back(el);
            std::cout<<std::endl<<"Lista undo are: "<<UNDO.size()<<" elemente."<<std::endl;
        }
        if (var == 3) {
            char nume[20], destinatie[20], tip[20];
            int pret;
            std::cout<<"Obiectul care vrei sa il modifici: ";
            std::cout<<"Denumire: ";
            citirechar(nume);
            std::cout<<"Destinarie: ";
            citirechar(destinatie);
            std::cout<<"Tip: ";
            citirechar(tip);
            std::cout<<"Pret: ";
            pret = citireint();
            oferta a{nume, destinatie, tip, pret};
            
            std::cout<<"Obiectul modificat: ";
            std::cout<<"Denumire: ";
            citirechar(nume);
            std::cout<<"Destinarie: ";
            citirechar(destinatie);
            std::cout<<"Tip: ";
            citirechar(tip);
            std::cout<<"Pret: ";
            pret = citireint();
            oferta b{nume, destinatie, tip, pret};
            s.cng(a, b);
            
            UndoModifica elem{a};
            ActiuneUndo* el;
            el = &elem;
            UNDO.push_back(el);
            std::cout<<std::endl<<"Lista undo are: "<<UNDO.size()<<" elemente."<<std::endl;
        }
        
        if (var == 4) {
            std::string x;
            s.rta(x);
            std::cout<<x;
        }
        if (var == 5) {
            std::string x;
            char nume[20];
            //char destinatie[20], tip[20];
            //int pret;
            std::cout<<"Denumire: ";
            citirechar(nume);
            /*std::cout<<"Destinarie: ";
            citirechar(destinatie);
            std::cout<<"Tip: ";
            citirechar(tip);
            std::cout<<"Pret: ";
            pret = citireint();
            oferta b{nume, destinatie, tip, pret};*/
            s.rfi(x, nume);
        }
        if (var == 6) {
            char dest[20];
            std::string x;
            std::cout<<"Introdu destinatia: ";
            std::cin>>dest;
            s.fld(x, dest);
        }
        if (var == 7) {
            unsigned int pret;
            std::string x;
            std::cout<<"Introdu pret: ";
            std::cin>>pret;
            s.flp(x, pret);
            std::cout<<x;
        }
        if (var == 8) {
            std::string x;
            s.std(x);
            std::cout<<x;
        }
        if (var == 9) {
            std::string x;
            s.sde(x);
            std::cout<<x;
        }
        if (var == 10) {
            std::string x;
            s.stp(x);
            std::cout<<x;
        }
        if (var == 12) {
            int cate;
            std::cout<<"Cate oferte: ";
            std::cin>>cate;
            sc.randomCos(cate, s.returnRepo().returnVector());
            std::cout<<"Oferte existente: "<<sc.sizeCos();
        }
        if (var == 13) {
            int id;
            std::cout<<"Id oferta: ";
            std::cin>>id;
            sc.adauga(id, s.returnRepo().returnVector());
            std::cout<<"Oferte existente: "<<sc.sizeCos();
        }
        if (var == 14) {
            sc.sterge();
            std::cout<<"Oferte existente: "<<sc.sizeCos();
        }
        
        if (var == 15) {
            sc.fileCos();
        }
        
        if (var == 16) {
            std::cout<<s.returnRepo().returnVector().back().getPret();
            s.setRepo(UNDO.back()->doUndo(s.returnRepo()));
            UNDO.pop_back();
            std::cout<<std::endl<<"Lista undo are: "<<UNDO.size()<<" elemente."<<std::endl;
        }
        
        
        for(Errore e : this->s.getErrors()){
            std::cout<<e.getMessage();
        }
        for(Errore e : this->sc.returnErrors()){
            std::cout<<e.getMessage();
        }
        s.clearErrors();
        sc.clearErrors();
        
        
    }
}

void UI::meniu(){
    std::printf("\n1. Adauga\n2. Sterge\n3. Modifica\n4. Afisare\n5. Cautare\n6. Filtrare destinatie\n7. Filtrare pret\n8. Sortare denumire\n9. Sortare destinatie\n10. Sortare pret\n11. Exit\n12. Cos Random\n13. Adauga in cos\n14. Sterge cosul\n");
}

int UI::citireint(){
    int a;
    //char x;
    //char* c = &x;
    std::cout<<"Introud un numar: ";
    std::cin>>a;
    //a = std::atoi(c);
    return a;
}

void UI::citirechar(char aux[20]){
    std::cout<<"Introdu un text: ";
    std::cin>>aux;
}




