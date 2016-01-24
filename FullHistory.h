/*************************************************************************
                           FullHistory  -  description
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <FullHistory> (fichier ${file_name}) ------
#if ! defined ( FULLHISTORY_H )
#define FULLHISTORY_H

//--------------------------------------------------- Interfaces utilis�es
#include "Shape.h"
#include "History.h"
#include <map>
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <FullHistory>
//
//
//------------------------------------------------------------------------

class FullHistory : public History
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
    // type M�thode ( liste de param�tres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    virtual History* Cancel(map<string, Shape*> & model);//cancel the action done in this history entry
    //Returns the history entry generated by the canceling (goes from undo to redo or from redo to undo)
    virtual void Clean();//Definitely deletes the target

//------------------------------------------------- Surcharge d'op�rateurs
    FullHistory & operator = ( const FullHistory & unFullHistory );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    FullHistory ( const FullHistory & unFullHistory );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    FullHistory ( string type, map<string, Shape*> & model );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~FullHistory ( );
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
string command;//Kept for generalisation purposes
map<string, Shape*> prevModel;


private:
//------------------------------------------------------- Attributs priv�s

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes priv�es

//----------------------------------------------------------- Types priv�s

};

//----------------------------------------- Types d�pendants de <FullHistory>

#endif // FULLHISTORY_H
