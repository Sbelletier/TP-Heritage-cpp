/*************************************************************************
                           Shape  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Shape> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Shape.h"


//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
void Shape::Move(int dx, int dy)
// Algorithme :
//
{
	for(int i=0; i<points.size(); i++)
	{
		points[i].move(dx, dy);
	}
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
Shape::Shape ( const Shape & unShape )
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


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
