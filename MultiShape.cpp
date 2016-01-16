/*************************************************************************
                           MultiShape  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <MultiShape> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "MultiShape.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type MultiShape::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void MultiShape::move(int dx, int dy)
//Algorithme :
{
    for(int i=0; i<shapes.size(); i++)
    {
        shapes[i].move( dx, dy );
    }
}//----- Fin de Move

//------------------------------------------------- Surcharge d'opérateurs
MultiShape & MultiShape::operator = ( const MultiShape & unMultiShape )
// Algorithme :
//
{

} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
MultiShape::MultiShape ( const MultiShape & unMultiShape )
    :name(unMultiShape.name)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <MultiShape>" << endl;
#endif
    for(int i=0; i<MultiShape.shapes.size(); i++)
    {
        shapes.push_back(Shape(MultiShape.shapes[i]));
    }
} //----- Fin de MultiShape (constructeur de copie)


MultiShape::MultiShape ( string aName, vector<Shape> aShapeVec )
    :name(aName)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <MultiShape>" << endl;
#endif
    for(int i=0; i<aShapeVec.size(); i++)
    {
        shapes.push_back(Shape(aShapeVec[i]));
    }
} //----- Fin de MultiShape


MultiShape::MultiShape ( string aName )
    :name(aName)
// Algorithme :
//
{
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
