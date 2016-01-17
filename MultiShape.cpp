/*************************************************************************
                           MultiShape  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- R�alisation de la classe <MultiShape> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
//essai git ds
//------------------------------------------------------ Include personnel
#include "MultiShape.h"

//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types priv�s


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- M�thodes publiques
// type MultiShape::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

void MultiShape::move(int dx, int dy)
//Algorithme :
{
    for(int i=0; i<shapes.size(); i++)
    {
        shapes[i].move( dx, dy );
    }
}//----- Fin de Move

//------------------------------------------------- Surcharge d'op�rateurs
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

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
