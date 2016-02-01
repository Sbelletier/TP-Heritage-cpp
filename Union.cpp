/*************************************************************************
                           Union  -  description
                             -------------------
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
// type Union::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


bool Union::Contains(const Point & p)
{
    for( i = 0; i < shapes.size(); i++ )
    {
        if ( shapes->Contains(p) )
        {
            return true;
        }
    }
    return false;
}

void Union::Move(int dx, int dy)
{
    for( i = 0; i < shapes.size(); i++ )
    {
        shapes[i]->move(dx, dy);
    }
}


//------------------------------------------------- Surcharge d'op�rateurs
Union & Union::operator = ( const Union & unUnion )
// Algorithme :
//
{

} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Union::Union ( const Union & unUnion ):Shape(unUnion.name)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Union>" << endl;
#endif
    delete[] shapes;
    for( i = 0; i < unUnion.shapes.size(); i++)
    {
        if ( unUnion.shapes[i]->type == "Segment" )
        {
            shapes.push_back( new Segment( *(unUnion.shapes[i]) ) );
        }
        else if (unUnion.shapes[i]->type == "Union")
        {
            shapes.push_back( new Union( *(unUnion.shapes[i]) ));
        }
        else if (unUnion.shapes[i]->type == "Intersection")
        {
            shapes.push_back( new Intersection( *(unUnion.shapes[i]) ) );
        }
        else if (unUnion.shapes[i]->type == "Polygon")
        {
            shapes.push_back( new Polygone( *(unUnion.shapes[i]) ) );
        }
        else if (unUnion.shapes[i]->type == "Rectangle")
        {
            shapes.push_back( new Rectangle( *(unUnion.shapes[i]) ) );
        }
    }
} //----- Fin de Union (constructeur de copie)


Union::Union ( string aName, vector<Shape*> aVector )
    :Shape(aName), shapes(aVector)
// Algorithme :
//
{
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
    delete [] shapes;
} //----- Fin de ~Union


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
