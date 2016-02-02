/*************************************************************************
                           Shape  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Shape> (fichier ${file_name}) ------
#if ! defined ( Shape_H )
#define Shape_H




//--------------------------------------------------- Interfaces utilisées
#include <vector>
#include "Point.h"
#include <string>
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

   virtual void Move(int dx, int dy)=0;

    // Mode d'emploi :
    //
    // Contrat :
    //

   std::string to_string(int a);
   // Mode d'emploi :
       //
       // Contrat :
       //

   virtual Shape* deepCopy()=0;
   virtual std::string print()=0;
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
std::string type;

private:
//------------------------------------------------------- Attributs privés


//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Shape>

#endif // Shape_H
