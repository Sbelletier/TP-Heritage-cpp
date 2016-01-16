/*************************************************************************
                           MultiShape  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <MultiShape> (fichier ${file_name}) ------
#if ! defined ( MULTISHAPE_H )
#define MULTISHAPE_H
#include "Shape.h"
#include <vector>
//--------------------------------------------------- Interfaces utilisées

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
    void move(int dx, int dy);
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

    MultiShape (string aName );
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
string name;
vector<Shape> shapes;

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

//----------------------------------------- Types dépendants de <MultiShape>

#endif // MULTISHAPE_H
#ifndef MULTISHAPE_H_INCLUDED
#define MULTISHAPE_H_INCLUDED



#endif // MULTISHAPE_H_INCLUDED
