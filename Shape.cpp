/*************************************************************************
                           Shape  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Shape> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>

//------------------------------------------------------ Include personnel
#include "Shape.h"
using namespace std;
#include "string.h"
#include <sstream>
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques


string & Shape::getName()
{
	return name;
}

//----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
Shape::Shape ( const Shape & unShape )
    :name(unShape.name), type(unShape.type)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Shape>" << endl;
#endif
} //----- Fin de Shape (constructeur de copie)


Shape::Shape ( string aName ):name(aName)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Shape>" << endl;
#endif
} //----- Fin de Shape


Shape::~Shape ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Shape>" << endl;
#endif
} //----- Fin de ~Shape

string Shape::to_string(int a)
{
	std::ostringstream ss;
	ss << a;
	return ss.str();
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
