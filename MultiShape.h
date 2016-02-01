/*************************************************************************
                           MultiShape  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <MultiShape> (fichier ${file_name}) ------
#if ! defined ( MULTISHAPE_H )
#define MULTISHAPE_H

//--------------------------------------------------- Interfaces utilisées
#include "Shape.h"
#include <vector>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <MultiShape>
//
//
//------------------------------------------------------------------------

class MultiShape : public Shape
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    MultiShape & operator = ( const MultiShape & unMultiShape );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    MultiShape ( const MultiShape & unMultiShape );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    MultiShape ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~MultiShape ( );
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
vector<Shape*> shapes;

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <MultiShape>

#endif // MULTISHAPE_H
