/*************************************************************************
                           Intersection  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Intersection> (fichier ${file_name}) ------
#if ! defined ( INTERSECTION_H )
#define INTERSECTION_H

//--------------------------------------------------- Interfaces utilisées
#include "Shape.h"
#include "MultiShape.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Intersection>
//
//
//------------------------------------------------------------------------

class Intersection : public MultiShape
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    std::string const type = "Intersection";
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual bool Contains(const Point & p);
    virtual void Move(int dx, int dy);



//------------------------------------------------- Surcharge d'opérateurs
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

    Intersection ( string aName, vector<Shape*> aVector );
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
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Intersection>

#endif // INTERSECTION_H
