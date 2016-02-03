/*************************************************************************
                           Union  -  description
                             -------------------
<<<<<<< HEAD
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Union> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Union.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
bool Union::Contains(const Point & p)
// Algorithme :
//
{
	bool contains=false;
	int i=0;
	while(!contains && i<shapes.size())
	{
		if(shapes[i]->Contains(p))
		{
			contains=true;
		}
		i++;
	}
	return contains;
}
Shape* Union::deepCopy()
{
	Shape* s=new Union(*this);
	return s;
}
//----- Fin de M�thode




//-------------------------------------------- Constructeurs - destructeur

Union::Union ( const Union & unUnion ):MultiShape(unUnion)
{
	type="OR";
}
Union::Union (std::string aName, std::vector<Shape*> vect):MultiShape(aName, vect)
// Algorithme :
//
{
	type="OR";
#ifdef MAP
    cout << "Appel au constructeur de <Union>" << endl;
#endif


} //----- Fin de Union


Union::~Union ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Union>" << endl;
#endif
} //----- Fin de ~Union


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es


