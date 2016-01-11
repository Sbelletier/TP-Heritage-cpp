/*************************************************************************
                           Point  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Point> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Point.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Point::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Point::move(int dx, int dy)
// Algorithme :
{
	x += dx;
	y += dy;
	return;
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
Point & Point::operator = ( const Point & aPoint )
// Algorithme :
//
{
	x = aPoint.x;
	y = aPoint.y;
	return *this;
} //----- Fin de operator =


bool Point::operator == ( const Point & aPoint )
// Algorithme :
//
{
	return( x == aPoint.x && y == aPoint.y );
} //----- Fin de operator ==
  

//-------------------------------------------- Constructeurs - destructeur
Point::Point ( const Point & aPoint )
	:x(aPoint.x),y(aPoint.y)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Point>" << endl;
#endif
} //----- Fin de Point (constructeur de copie)


Point::Point ( int aX, int aY )
	:x(aX), y(aY)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Point>" << endl;
#endif
} //----- Fin de Point


Point::~Point ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Point>" << endl;
#endif
} //----- Fin de ~Point


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
