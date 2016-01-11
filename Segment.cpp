/*************************************************************************
                           Segment  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Segment> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Segment.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques

virtual void contains(const Point & p)
// Algorithme :
//
{
	if( !(p.x>points[0].x && p.x>points[1].x) && !(p.x < points[0].x && p.x < points[1].x))
	{
		float coeff=(point[0].y-point[1].y)/(point[0].x-point[1].x);
		int b=point[0].y-coeff*point[0].x;
		return (p.x*coeff + b == p.y);
	}
	
	return false;
	
} //----- Fin de Méthode


virtual void intersectPoint(const Segment & s)
// Algorithme :
//
{
	if( !(p.x>points[0].x && p.x>points[1].x) && !(p.x < points[0].x && p.x < points[1].x))
	{
		float coeff=(point[0].y-point[1].y)/(point[0].x-point[1].x);
		int b=point[0].y-coeff*point[0].x;
		return (p.x*coeff + b == p.y);
	}
	
	return false;
	
} //----- Fin de Méthode

//------------------------------------------------- Surcharge d'opérateurs
Segment & Segment::operator = ( const Segment & unSegment )
// Algorithme :
//
{
	
	return *this;
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Segment::Segment ( const Segment & unSegment )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Segment>" << endl;
#endif
} //----- Fin de Segment (constructeur de copie)


Segment::Segment ( string aName, int x1, int y1, int x2, int y2 )
	:Shape(aName)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Segment>" << endl;
#endif

	points.push_back( Point( x1, y1 ));
	points.push_back( Point( x2, y2 ));
	
	
} //----- Fin de Segment


Segment::~Segment ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Segment>" << endl;
#endif
//delete [] points;
} //----- Fin de ~Segment


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
