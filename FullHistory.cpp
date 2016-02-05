/*************************************************************************
                           FullHistory  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <FullHistory> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <map>

//------------------------------------------------------ Include personnel
#include "FullHistory.h"
#include "Shape.h"
#include "History.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type FullHistory::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode
History* FullHistory::Cancel(map<string,Shape*> & model)
{
	map<string,Shape*>::iterator it;
	FullHistory* opposite= new FullHistory("full", model);
	model=prevModel;
    return opposite;
}


//-------------------------------------------- Constructeurs - destructeur
FullHistory::FullHistory ( const FullHistory & unFullHistory ):History(unFullHistory.command)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <FullHistory>" << endl;
#endif
    //throw bad_function_call;//a history entry shouldn't be copied
} //----- Fin de FullHistory (constructeur de copie)


FullHistory::FullHistory (string type, map<string,Shape*> & model )
    :History(type)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <FullHistory>" << endl;
#endif
    map<string,Shape*>::iterator it;
    for(it=model.begin(); it!=model.end(); it++)
    {
    	prevModel.insert(pair<string, Shape*>(it->first,it->second));
    }
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

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
