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

bool Segment::Contains(const Point & p)
// Algorithme :
//
{
	if( !(p.x>points[0].x && p.x>points[1].x) && !(p.x < points[0].x && p.x < points[1].x))
	{
		float coeff=(points[0].y-points[1].y)/(points[0].x-points[1].x);
		int b=points[0].y-coeff*points[0].x;
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
Segment::Segment ( const Segment & unSegment ):Shape(unSegment.name)
// Algorithme :
//
{
	points.push_back(unSegment.points[1]);
	points.push_back(unSegment.points[2]);

#ifdef MAP
    cout << "Appel au constructeur de copie de <Segment>" << endl;
#endif
} //----- Fin de Segment (constructeur de copie)


Segment::Segment ( string aName, int* aPoints )
	:Shape(aName)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Segment>" << endl;
#endif

	points.push_back( Point( aPoints[0], aPoints[1] ));
	points.push_back( Point( aPoints[2], aPoints[3] ));


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
