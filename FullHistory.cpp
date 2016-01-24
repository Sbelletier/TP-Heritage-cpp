/*************************************************************************
                           FullHistory  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <FullHistory> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <map>

//------------------------------------------------------ Include personnel
#include "FullHistory.h"
#include "Shape.h"
#include "History.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type FullHistory::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
History* FullHistory::Cancel(map<string,Shape*> & model)
{
    FullHistory* opposite;
    opposite = new FullHistory("full", model);
    model = prevModel;
    return opposite;
}

void FullHistory::Clean()
{
    map<string,Shape*>::iterator it = prevModel.begin();
    map<string,Shape*>::iterator wipe;
    while( it != prevModel.end() )
    {
        wipe = it++;
        delete wipe->second;
    }
    delete prevModel;
}


//------------------------------------------------- Surcharge d'opérateurs
FullHistory & FullHistory::operator = ( const FullHistory & unFullHistory )
// Algorithme :
//
{
    throw bad_function_call;//a history entry shouldn't be copied. it should be moved by reference or address
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
FullHistory::FullHistory ( const FullHistory & unFullHistory )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <FullHistory>" << endl;
#endif
    throw bad_function_call;//a history entry shouldn't be copied
} //----- Fin de FullHistory (constructeur de copie)


FullHistory::FullHistory (string type, map<string,Shape*> & model )
    :command(type), prevModel(model)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <FullHistory>" << endl;
#endif
} //----- Fin de FullHistory


FullHistory::~FullHistory ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <FullHistory>" << endl;
#endif
} //----- Fin de ~FullHistory


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
