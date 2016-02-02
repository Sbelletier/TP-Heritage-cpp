/*************************************************************************
                           MultiShape  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <MultiShape> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>

//------------------------------------------------------ Include personnel
#include "MultiShape.h"
using namespace std;
#include "string.h"
#include <sstream>
#include <map>
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
string MultiShape::print()
{
	string p="#\n";
	for(int i=0; i<shapes.size(); i++)
	{
		p+=shapes[i]->print();
	}
	p="\n"+type+" "+name;
	return p;
}

void MultiShape::Move(int dx, int dy)
// Algorithme :
//
{
	for(int i=0; i<shapes.size(); i++)
	{
		shapes[i]->Move(dx, dy);
	}

}


//----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs



//-------------------------------------------- Constructeurs - destructeur
MultiShape::MultiShape ( const MultiShape & unMultiShape ):Shape(unMultiShape.name)
// Algorithme :
//
{
	for(int i=0; i<unMultiShape.shapes.size(); i++)
	{
		shapes.push_back(unMultiShape.shapes[i]);
	}
#ifdef MAP
    cout << "Appel au constructeur de copie de <MultiShape>" << endl;
#endif
} //----- Fin de MultiShape (constructeur de copie)


MultiShape::MultiShape (std::string aName,  vector<Shape*> aShapeVec ):Shape(aName)
// Algorithme :
//
{
	for(int i=0; i<aShapeVec.size(); i++)
	{
		shapes.push_back(aShapeVec[i]);
	}
#ifdef MAP
    cout << "Appel au constructeur de <MultiShape>" << endl;
#endif
} //----- Fin de MultiShape


MultiShape::~MultiShape ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <MultiShape>" << endl;
#endif
} //----- Fin de ~MultiShape


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
