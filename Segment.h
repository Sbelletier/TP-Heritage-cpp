/*************************************************************************
                           Segment  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Segment> (fichier ${file_name}) ------
#if ! defined ( SEGMENT_H )
#define SEGMENT_H

//--------------------------------------------------- Interfaces utilisées
#include "Shape.h"
#include "Point.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Segment>
//
//
//------------------------------------------------------------------------

class Segment : public Shape
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste de paramètres );

    virtual bool Contains(const Point & p);
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
    Segment & operator = ( const Segment & unSegment );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Segment ( const Segment & unSegment );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Segment (std::string aName, int* aPoints );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Segment ( );
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

//----------------------------------------- Types dépendants de <Segment>

#endif // SEGMENT_H

