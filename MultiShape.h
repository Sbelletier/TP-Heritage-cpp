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
#include "shape.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Role de la classe <MultiShape>
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

    MultiShape (std::string aName );
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
std::string name;
std::vector<Shape> shapes;

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

//----------------------------------------- Types d�pendants de <MultiShape>

#endif // MULTISHAPE_H
#ifndef MULTISHAPE_H_INCLUDED
#define MULTISHAPE_H_INCLUDED



#endif // MULTISHAPE_H_INCLUDED
