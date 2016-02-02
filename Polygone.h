/*************************************************************************
                           Polygone  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Polygone> (fichier ${file_name}) ------
#if ! defined ( POLYGONE_H )
#define POLYGONE_H

//--------------------------------------------------- Interfaces utilis�es
#include "Point.h"
#include "SingleShape.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Polygone>
//
//
//------------------------------------------------------------------------

class Polygone : public SingleShape
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques

    static bool convex(int p[], int size);
	virtual bool Contains(const Point & p);
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'op�rateurs
    Polygone & operator = ( const Polygone & unPolygone );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Polygone ( const Polygone & unPolygone );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Polygone ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    Polygone (std::string aName, int p[], int size );
        // Mode d'emploi :
        //
        // Contrat :
        //

    virtual ~Polygone ( );
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

//----------------------------------------- Types d�pendants de <Polygone>

#endif // POLYGONE_H
