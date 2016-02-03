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
    FullHistory* opposite;
    opposite = new FullHistory("full", model);
    model = prevModel;
    return opposite;
}


//------------------------------------------------- Surcharge d'op�rateurs
FullHistory & FullHistory::operator = ( const FullHistory & unFullHistory )
// Algorithme :
//
{
    //throw bad_function_call;//a history entry shouldn't be copied. it should be moved by reference or address
} //----- Fin de operator =


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
    :History(type), prevModel(model)
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
    map<string,Shape*>::iterator it = prevModel.begin();
	map<string,Shape*>::iterator wipe;
	while( it != prevModel.end() )
	{
		wipe = it++;
		delete wipe->second;
		wipe->second=0;
	}
} //----- Fin de ~FullHistory


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
