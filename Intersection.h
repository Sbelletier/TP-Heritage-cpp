/*************************************************************************
                           Intersection  -  description
                             -------------------
<<<<<<< HEAD
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Intersection> (fichier ${file_name}) ------
#if ! defined ( INTERSECTION_H )
#define INTERSECTION_H

//--------------------------------------------------- Interfaces utilis�es
#include "Point.h"
#include "MultiShape.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Intersection>
//
//
//------------------------------------------------------------------------

class Intersection : public MultiShape
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques

	virtual bool Contains(const Point & p);
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'op�rateurs
    Intersection & operator = ( const Intersection & unIntersection );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Intersection ( const Intersection & unIntersection );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Intersection ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Intersection (std::string aName, std::vector<Shape*> vect);
        // Mode d'emploi :
        //
        // Contrat :
        //

    virtual ~Intersection ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s

private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};


#endif // INTERSECTION_H
