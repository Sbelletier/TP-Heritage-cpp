/*************************************************************************
                           Intersection  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Réalisation de la classe <Intersection> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <vector>
#include <string>
//------------------------------------------------------ Include personnel
#include "Intersection.h"
#include "MultiShape.h"
//------------------------------------------------------------- Constantes

//---------------------------------------------------- Variables de classe

//----------------------------------------------------------- Types privés


//----------------------------------------------------------------- PUBLIC
//-------------------------------------------------------- Fonctions amies

//----------------------------------------------------- Méthodes publiques
// type Intersection::Méthode ( liste de paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
bool Intersection::Contains(const Point &p)
//Algorithme :
{
    for(int i=0;i<shapes.size();i++)
    {
        if(!shapes[i].Contains(p))
        {
            return false;
        }
    }
    return true;
}


//------------------------------------------------- Surcharge d'opérateurs
Intersection & Intersection::operator = ( const Intersection & unIntersection )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Intersection::Intersection ( const Intersection & unIntersection )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Intersection>" << endl;
#endif
} //----- Fin de Intersection (constructeur de copie)


Intersection::Intersection ( )
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
} //----- Fin de ~Intersection


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//------------------------------------------------------- Méthodes privées
