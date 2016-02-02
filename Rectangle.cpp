/*************************************************************************
                           Rectangle  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Rectangle> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Rectangle.h"
#include "SingleShape.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
bool Rectangle::Contains(const Point & p)
// Algorithme :
//
{
	return ( ((p.x<=points[0].x && p.x>=points[1].x) ||  (p.x>=points[0].x && p.x<=points[1].x))     &&     ((p.y<=points[0].y && p.y>=points[1].y) ||  (p.y>=points[0].y && p.y<=points[1].y) ));

} //----- Fin de M�thode

Shape* Rectangle::deepCopy()
{
	Shape* s=new Rectangle(*this);
	return s;
}



//-------------------------------------------- Constructeurs - destructeur
Rectangle::Rectangle ( const Rectangle & unRectangle ):SingleShape(unRectangle)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle (constructeur de copie)


Rectangle::Rectangle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Rectangle>" << endl;
#endif
} //----- Fin de Rectangle
Rectangle::Rectangle ( std::string aName, int* aPoints):SingleShape(aName)
// Algorithme :
//
{
	type="R";
	points.push_back( Point( aPoints[0], aPoints[1] ));
	points.push_back( Point( aPoints[2], aPoints[3] ));
#ifdef MAP
    cout << "Appel au constructeur de <Rectangle>" << endl;
#endif


} //----- Fin de Rectangle


Rectangle::~Rectangle ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Rectangle>" << endl;
#endif
} //----- Fin de ~Rectangle


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
