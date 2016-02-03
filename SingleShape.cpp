/*************************************************************************
                           SingleShape  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <SingleShape> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>

//------------------------------------------------------ Include personnel
#include "SingleShape.h"
using namespace std;
#include "string.h"
#include <sstream>
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
string SingleShape::print()
{
	string p=type+" "+name;
	for(int i=0; i<points.size(); i++)
	{
		p+=" "+to_string(points[i].x)+" "+to_string(points[i].y);
	}
	p+='\r\n';
	return p;
}

void SingleShape::Move(int dx, int dy)
// Algorithme :
//
{
	for(int i=0; i<points.size(); i++)
	{
		points[i].move(dx, dy);
	}
}

string & SingleShape::getName()
{
	return name;
}

//----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
SingleShape::SingleShape ( const SingleShape & unSingleShape ):Shape(unSingleShape)
// Algorithme :
//
{
	for(int i=0; i<unSingleShape.points.size(); i++)
	{
		points.push_back(unSingleShape.points[i]);
	}
#ifdef MAP
    cout << "Appel au constructeur de copie de <SingleShape>" << endl;
#endif
} //----- Fin de SingleShape (constructeur de copie)


SingleShape::SingleShape ( string aName ):Shape(aName)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <SingleShape>" << endl;
#endif
} //----- Fin de SingleShape


SingleShape::~SingleShape ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <SingleShape>" << endl;
#endif
} //----- Fin de ~SingleShape


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
