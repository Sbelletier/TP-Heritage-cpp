/*************************************************************************
                           History  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <History> (fichier ${file_name}) ------
#if ! defined ( HISTORY_H )
#define HISTORY_H
//
//--------------------------------------------------- Interfaces utilis�es
#include "Shape.h"
#include <map>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <History>
//
//
//------------------------------------------------------------------------

class History
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste de param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual History* Cancel(map<string, Shape*> & model)=0;//Cancels the action
    //Returns the history entry generated by the canceling (goes from undo to redo or from redo to undo)
    virtual void Clean()=0;//Definitely deletes the target

//------------------------------------------------- Surcharge d'op�rateurs
    History & operator = ( const History & unHistory );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    History ( const History & unHistory )
    {

    }
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    History ( )
    {

    }
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~History ( )
    {

    }
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

//----------------------------------------- Types d�pendants de <History>

#endif // HISTORY_H
