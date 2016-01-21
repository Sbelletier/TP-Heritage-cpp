/*************************************************************************
                           Intersection  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

/*//---------- R�alisation de la classe <Intersection> (fichier ${file_name}) --

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>
#include <vector>
#include <string>
//------------------------------------------------------ Include personnel
#include "Intersection.h"
//------------------------------------------------------------- Constantes
//c
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


//------------------------------------------------- Surcharge d'op�rateurs
Intersection & Intersection::operator = ( const Intersection & unIntersection )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
/*Intersection::Intersection ( const Intersection & unIntersection )
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

//----------------------------------------------------- M�thodes prot�g�es

//------------------------------------------------------- M�thodes priv�es*/
