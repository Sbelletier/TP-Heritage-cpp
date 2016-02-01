/*************************************************************************
                           Union  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Union> (fichier ${file_name}) ------
#if ! defined ( UNION_H )
#define UNION_H

//--------------------------------------------------- Interfaces utilis�es
#include "Shape.h"
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
    std::string const type = "Union";
    // type M�thode ( liste de param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual bool Contains(const Point & p);
    virtual void Move(int dx, int dy);

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

    Union ( string aName, vector<Shape*> aVector );
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

#endif // UNION_H
