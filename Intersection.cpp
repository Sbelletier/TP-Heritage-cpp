/*************************************************************************
                           Intersection  -  description
                             -------------------
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
// type Intersection::M�thode ( liste de param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode


bool Intersection::Contains(const Point & p)
{
    for( i = 0; i < shapes.size(); i++ )
    {
        if ( !shapes->Contains(p) )
        {
            return false;
        }
    }
    return true;
}

void Intersection::Move(int dx, int dy)
{
    for( i = 0; i < shapes.size(); i++ )
    {
        shapes[i]->move(dx, dy);
    }
}


//------------------------------------------------- Surcharge d'op�rateurs
Intersection & Intersection::operator = ( const Intersection & unIntersection )
// Algorithme :
//
{

} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Intersection::Intersection ( const Intersection & unIntersection ):Shape(unIntersection.name)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Intersection>" << endl;
#endif
    delete[] shapes;
    for( i = 0; i < unIntersection.shapes.size(); i++)
    {
        if ( unIntersection.shapes[i]->type == "Segment" )
        {
            shapes.push_back( new Segment( *(unIntersection.shapes[i]) ) );
        }
        else if (unIntersection.shapes[i]->type == "Union")
        {
            shapes.push_back( new Union( *(unIntersection.shapes[i]) ));
        }
        else if (unIntersection.shapes[i]->type == "Intersection")
        {
            shapes.push_back( new Intersection( *(unIntersection.shapes[i]) ) );
        }
        else if (unIntersection.shapes[i]->type == "Polygon")
        {
            shapes.push_back( new Polygone( *(unIntersection.shapes[i]) ) );
        }
        else if (unIntersection.shapes[i]->type == "Rectangle")
        {
            shapes.push_back( new Rectangle( *(unIntersection.shapes[i]) ) );
        }
    }
} //----- Fin de Intersection (constructeur de copie)


Intersection::Intersection ( string aName, vector<Shape*> aVector )
    :Shape(aName), shapes(aVector)
// Algorithme :
//
{
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
    delete [] shapes;
} //----- Fin de ~Intersection


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es
