/*************************************************************************
                           Union  -  description
                             -------------------
<<<<<<< HEAD
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Union> (fichier ${file_name}) ------
#if ! defined ( Union_H )
#define Union_H

//--------------------------------------------------- Interfaces utilis�es
#include "Point.h"
#include "MultiShape.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Union>
//
//
//------------------------------------------------------------------------

class Union : public MultiShape
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques

	virtual bool Contains(const Point & p);
    // Mode d'emploi :
    //
    // Contrat :
    //
	virtual Shape* deepCopy();

//------------------------------------------------- Surcharge d'op�rateurs
    Union & operator = ( const Union & unUnion );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Union ( const Union & unUnion );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Union ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Union (std::string aName, std::vector<Shape*> vect);
        // Mode d'emploi :
        //
        // Contrat :
        //

    virtual ~Union ( );
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

//----------------------------------------- Types d�pendants de <Union>

#endif // Union_H
