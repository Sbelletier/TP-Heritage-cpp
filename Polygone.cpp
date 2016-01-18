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
	bool contains=true;
	int i=0;
	int sign=0;
	bool s=false;
	while (sign==0)
	{
		sign=(p.x-points[i].x)*(points[i+1].y-points[i].y)-(p.y-points[i].y)*(points[i+1].x-points[i].x);
		i++;
	}
	i=0;
	if(sign>0)
	{
		s=true;
	}
	if(s)
	{
		while (contains && i<points.size()-1)
		{
			cout<<"s"<<(p.x-points[i].x)*(points[i+1].y-points[i].y)-(p.y-points[i].y)*(points[i+1].x-points[i].x)<<endl;
			if( (p.x-points[i].x)*(points[i+1].y-points[i].y)-(p.y-points[i].y)*(points[i+1].x-points[i].x)<=0)
			{
				contains=false;
			}
			i++;
		}
		if( (p.x-points[i].x)*(points[0].y-points[i].y)-(p.y-points[i].y)*(points[0].x-points[i].x)<=0)
		{
			contains=false;
		}
	}
	else
	{
		while (contains && i<points.size()-1)
		{
			cout<<"s"<<(p.x-points[i].x)*(points[i+1].y-points[i].y)-(p.y-points[i].y)*(points[i+1].x-points[i].x)<<endl;
			if( ((p.x-points[i].x)*(points[i+1].y-points[i].y)-(p.y-points[i].y)*(points[i+1].x-points[i].x))>=0)
			{
				contains=false;
			}
			i++;
		}

		if( ((p.x-points[i].x)*(points[0].y-points[i].y)-(p.y-points[i].y)*(points[0].x-points[i].x))>=0)
		{
			contains=false;
		}
	}
	return contains;
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
