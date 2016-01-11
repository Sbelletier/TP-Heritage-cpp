/*************************************************************************
                           Point  -  description
                             -------------------
    début                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//---------- Interface de la classe <Point> (fichier ${file_name}) ------
#if ! defined ( POINT_H )
#define POINT_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes 

//------------------------------------------------------------------ Types 

//------------------------------------------------------------------------ 
// Rôle de la classe <Point>
//
//
//------------------------------------------------------------------------ 

class Point 
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

//------------------------------------------------- Surcharge d'opérateurs
    Point & operator = ( const Point & aPoint );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    bool operator == ( const Point & aPoint );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    /*
    Point & operator < ( const Point & aPoint );
    // Mode d'emploi :
    //
    // Contrat :
    //
    */


//-------------------------------------------- Constructeurs - destructeur
    Point ( const Point & aPoint );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Point ( int aX=0, int aY=0 );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Point ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE 

protected:
//----------------------------------------------------- Méthodes protégées

private:
//------------------------------------------------------- Méthodes privées

public:
//----------------------------------------------------- Attributs publics
int x;
int y;

protected:
//----------------------------------------------------- Attributs protégés

private:
//------------------------------------------------------- Attributs privés

//---------------------------------------------------------- Classes amies

//-------------------------------------------------------- Classes privées

//----------------------------------------------------------- Types privés

};

//----------------------------------------- Types dépendants de <Point>

#endif // POINT_H
