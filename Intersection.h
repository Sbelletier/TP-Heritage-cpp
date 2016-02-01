/*************************************************************************
                           Intersection  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Intersection> (fichier ${file_name}) ------
#if ! defined ( INTERSECTION_H )
#define INTERSECTION_H

//--------------------------------------------------- Interfaces utilis�es
#include "Shape.h"
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
    std::string const type = "Intersection";
    // type M�thode ( liste de param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual bool Contains(const Point & p);
    virtual void Move(int dx, int dy);



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

//----------------------------------------- Types d�pendants de <Intersection>

#endif // INTERSECTION_H
