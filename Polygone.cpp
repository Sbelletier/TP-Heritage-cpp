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
#include "Segment.h"
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
			int produitV=(p.x-points[i].x)*(points[i+1].y-points[i].y)-(p.y-points[i].y)*(points[i+1].x-points[i].x);
			cout<<"qs "<<produitV<<endl;
			int seg[]={points[i].x, points[i].y, points[i+1].x,points[i+1].y};
			Segment s=Segment("",seg);
			if(produitV<0 || (produitV==0 && !s.Contains(p)))
			{
				contains=false;
			}
			i++;
		}
		int produitV=(p.x-points[i].x)*(points[0].y-points[i].y)-(p.y-points[i].y)*(points[0].x-points[i].x);
		int seg[]={points[i].x, points[i].y, points[i+1].x,points[i+1].y};
		Segment s=Segment("",seg);
		if(produitV<0 ||  (produitV==0 && !s.Contains(p)))
		{
			contains=false;
		}
	}
	else
	{
		while (contains && i<points.size()-1)
		{
			int produitV=(p.x-points[i].x)*(points[i+1].y-points[i].y)-(p.y-points[i].y)*(points[i+1].x-points[i].x);
			int seg[]={points[i].x, points[i].y, points[i+1].x,points[i+1].y};
			Segment s=Segment("",seg);
			cout<<"qs "<<produitV<<endl;
			if( (produitV>0 && !s.Contains(p)))
			{
				contains=false;
			}
			i++;
		}

		int produitV=(p.x-points[i].x)*(points[0].y-points[i].y)-(p.y-points[i].y)*(points[0].x-points[i].x);
		int seg[]={points[i].x, points[i].y, points[0].x,points[0].y};
		Segment s=Segment("",seg);
		if( (produitV>0 && !s.Contains(p)))
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
