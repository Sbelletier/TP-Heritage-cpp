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
string Shape::print()
{
	string p=type+" "+name;
	for(int i=0; i<points.size(); i++)
	{
		p+=" "+to_string(points[i].x)+" "+to_string(points[i].y);
	}
	p+="\r\n";
	return p;
}

void Shape::Move(int dx, int dy)
// Algorithme :
//
{
	for(int i=0; i<points.size(); i++)
	{
		points[i].move(dx, dy);
	}
}

string & Shape::getName()
{
	return name;
}

//----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
Shape::Shape ( const Shape & unShape )
    :name(unShape.name), points(unShape.points)
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
