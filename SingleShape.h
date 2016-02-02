/*************************************************************************
                           SingleShape  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <SingleShape> (fichier ${file_name}) ------
#if ! defined ( SINGLESHAPE_H )
#define SINGLESHAPE_H




//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include "Point.h"
#include "Shape.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types


//------------------------------------------------------------------------
// Rôle de la classe <SingleShape>
//
//
//------------------------------------------------------------------------

class SingleShape : public Shape
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

   virtual void Move(int dx, int dy);

    // Mode d'emploi :
    //
    // Contrat :
    //

   virtual std::string print();
   // Mode d'emploi :
      //
      // Contrat :
      //
   virtual bool Contains(const Point & p)=0;
    // Mode d'emploi :
    //
    // Contrat :
    //

    std::string & getName();
        // Mode d'emploi :
        //
        // Contrat :
        //


//------------------------------------------------- Surcharge d'opérateurs
    SingleShape & operator = ( const SingleShape & unSingleShape );
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
	virtual ~SingleShape ( );
	   // Mode d'emploi :
	   //
	   // Contrat :
	   //



//------------------------------------------------------------------ PRIVE

protected:


    SingleShape ( const SingleShape & unSingleShape );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    SingleShape (std::string aName="");
    // Mode d'emploi :
    //
    // Contrat :
    //



//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

protected:
//----------------------------------------------------- Attributs protégés

std::vector<Point> points;

private:
//------------------------------------------------------- Attributs privés


//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <SingleShape>

#endif // SINGLESHAPE_H
