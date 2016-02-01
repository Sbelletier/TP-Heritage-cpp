/*************************************************************************
                           SingleHistory  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <SingleHistory> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <map>
//------------------------------------------------------ Include personnel
#include "SingleHistory.h"
#include "Shape.h"
#include "History.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type SingleHistory::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode
History* SingleHistory::Cancel(map<string, Shape*> & model)
//Algorithm :
{
    SingleHistory* opposite;
    if ( command == "delete")
    {
        model.insert(pair<string, Shape*>(target->getName(),target));
        opposite = new SingleHistory("create",target);
    }
    else if ( command == "create" )
    {
        model.erase(target->getName());
        opposite = new SingleHistory("delete",target);
    }
    return opposite;
}

void SingleHistory::Clean()
{
    delete target;
}


//------------------------------------------------- Surcharge d'op�rateurs
/*
SingleHistory & SingleHistory::operator = ( const SingleHistory & unSingleHistory )
// Algorithme :
//
{
    throw bad_function_call;//a history entry shouldn't be copied. it should be moved by reference or address
} //----- Fin de operator =
*/

//-------------------------------------------- Constructeurs - destructeur
SingleHistory::SingleHistory ( const SingleHistory & unSingleHistory )
    :History( unSingleHistory.command)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <SingleHistory>" << endl;
#endif
   // throw bad_function_call;//a history entry shouldn't be copied.
} //----- Fin de SingleHistory (constructeur de copie)


SingleHistory::SingleHistory (string type, Shape* atarget )
    :History(type)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <SingleHistory>" << endl;
#endif
    target = atarget;
} //----- Fin de SingleHistory


SingleHistory::~SingleHistory ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <SingleHistory>" << endl;
#endif
} //----- Fin de ~SingleHistory


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
