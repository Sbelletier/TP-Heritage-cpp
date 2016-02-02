/*************************************************************************
                           Intersection  -  description
                             -------------------
<<<<<<< HEAD
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Intersection> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Intersection.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
bool Intersection::Contains(const Point & p)
// Algorithme :
//
{
	bool contains=true;
	int i=0;
	while(contains && i<shapes.size())
	{
		if(shapes[i]->Contains(p))
		{
			contains=false;
		}
		i++;
	}
	return contains;
} //----- Fin de M�thode




//-------------------------------------------- Constructeurs - destructeur


Intersection::Intersection (std::string aName, std::vector<Shape*> vect):MultiShape(aName, vect)
// Algorithme :
//
{
	type="OI";

#ifdef MAP
    cout << "Appel au constructeur de <Intersection>" << endl;
#endif


} //----- Fin de Intersection


Intersection::~Intersection ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Intersection>" << endl;
#endif
} //----- Fin de ~Intersection


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es


