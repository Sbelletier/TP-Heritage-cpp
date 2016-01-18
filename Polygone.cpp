/*************************************************************************
                           Polygone  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <Polygone> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <string>
#include <vector>
//------------------------------------------------------ Include personnel
#include "Polygone.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
bool Polygone::Contains(const Point & p)
// Algorithme :
//
{
	bool right=false;
	bool left=false;
	bool up=false;
	bool down=false;
	int i=0;
	while(i<points.size() && (!right || !left || !up || !down))
	{
		if(!right && points[i]<p.x)
		{
			right=true;
		}

		if(!left && points[i]>p.x)
		{
			left=true;
		}

		if(!up && points[i]>p.y)
		{
			up=true;
		}
		if(!down && points[i]<p.y)
		{
			down=true;
		}
		i++;
	}
	if(i==points.size())
	{
		return false;
	}
	return true;
} //----- Fin de M�thode



//-------------------------------------------- Constructeurs - destructeur
Polygone::Polygone ( const Polygone & unPolygone )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Polygone>" << endl;
#endif
} //----- Fin de Polygone (constructeur de copie)


Polygone::Polygone ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Polygone>" << endl;
#endif
} //----- Fin de Polygone


Polygone::~Polygone ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Polygone>" << endl;
#endif
} //----- Fin de ~Polygone

Polygone::Polygone (string aName, const vector<int> & vectInt ):Shape(aName)
{
	for(int i=0; i<vectInt.size(); i+=2)
	{
		points.push_back(Point(vectInt[i], vectInt[i+1]));
	}
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
