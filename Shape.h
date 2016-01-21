/*************************************************************************
                           Shape  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Shape> (fichier ${file_name}) ------
#if ! defined ( SHAPE_H )
#define SHAPE_H




//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include "Point.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types


//------------------------------------------------------------------------
// Rôle de la classe <Shape>
//
//
//------------------------------------------------------------------------

class Shape
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
   std::string const type="";

   void Move(int dx, int dy);

    // Mode d'emploi :
    //
    // Contrat :
    //




    virtual bool Contains(const Point & p)=0;
    // Mode d'emploi :
    //
    // Contrat :
    //



//------------------------------------------------- Surcharge d'opérateurs
    Shape & operator = ( const Shape & unShape );
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    virtual ~Shape ( );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------------------------ PRIVE

protected:

//-------------------------------------------- Constructeurs - destructeur
    Shape ( const Shape & unShape );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Shape (std::string aName="");
    // Mode d'emploi :
    //
    // Contrat :
    //



//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés
std::string name;
std::vector<Point> points;


private:
//------------------------------------------------------- Attributs privés


//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Shape>

#endif // SHAPE_H
