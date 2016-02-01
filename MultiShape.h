/*************************************************************************
                           MultiShape  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <MultiShape> (fichier ${file_name}) ------
#if ! defined ( MULTISHAPE_H )
#define MULTISHAPE_H

//--------------------------------------------------- Interfaces utilis�es
#include "Shape.h"
#include <vector>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <MultiShape>
//
//
//------------------------------------------------------------------------

class MultiShape : public Shape
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste de param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'op�rateurs
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
//----------------------------------------------------- M�thodes prot�g�es

private:
//------------------------------------------------------- M�thodes priv�es

protected:
//----------------------------------------------------- Attributs prot�g�s
vector<Shape*> shapes;

private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <MultiShape>

#endif // MULTISHAPE_H
