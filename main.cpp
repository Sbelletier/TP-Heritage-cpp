/*************************************************************************
                           Module main
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/


//-------------------------------------------------------- Include syst�me
using namespace std;

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <cstdlib>
#include <exception>
#include <new>
#include <stack>

//------------------------------------------------------ Include personnel
#include "Point.h"
#include "Shape.h"
	#include "Segment.h"
	#include "MultiShape.h"
		#include "Intersection.h"
		#include "Union.h"
    #include "Polygone.h"
    #include "Rectangle.h"
#include "History.h"
    #include "SingleHistory.h"
    #include "FullHistory.h"

//------------------------------------------------------ Declaration des fonctions
void exportModel(string fileName, map<string, Shape*> & mapShapes);//OPTION SI COUT
void importModel(string fileName, map<string, Shape*> & mapShapes);
//void fillMultiShape(MultiShape & toFill, fstream & aStream);//used by import, potentially in a recursive way


//------------------------------------------------------ Main
int main(int argc, char **argv)
{
	//------------------------------------------------------ Declaration des variables
	map<string, Shape*> mapShapes;
	map<string, Shape*>::iterator it = mapShapes.begin();
	map<string, Shape*>::iterator wipe;
	//History
	stack<History*> undo;
	stack<History*> redo;
	//infinite loop variables
	bool loop = true;
	string input;

	//------------------------------------------------------ Input
	while( loop )
	{
	    History* currHistory;

	    //get the input and split it
		vector<string> splittedInput;
		getline(cin, input);
		//cout<<input<<endl;
		int index= input.find(' ');
		while( index!=-1 )
		{
				splittedInput.push_back(input.substr( 0, input.find(' ') ) );
				input=input.substr(input.find(' ')+1);
				index= input.find(' ');
		}
		splittedInput.push_back(input);
        //act accordingly
        if ( splittedInput[0] == "UNDO" || splittedInput[0] == "REDO" )//beginning of the decision blocks
        {
            if( splittedInput[0] == "UNDO" )
            {
                if( !undo.empty() )
                {
                    currHistory = undo.top();
                    redo.push( currHistory->Cancel(mapShapes) );
                    cout << "OK" << endl;
                }
                else
                {
                    cout << "NOTHING TO UNDO" << endl;
                }
            }
            else
            {
                if( !redo.empty() )
                {
                    currHistory = redo.top();
                    undo.push( currHistory->Cancel(mapShapes) );
                    cout << "OK" << endl;
                }
                else
                {
                    cout << "NOTHING TO REDO" << endl;
                }
            }
        }
        else
        {
                while ( !redo.empty() )
                {
                    redo.top()->Clean();//avoids memory leaks
                    redo.pop();
                }
                //now we check for the correct action to do
                if ( splittedInput[0] == "EXIT" )
                {
                    loop = false;

                    cout << "BYE" << endl;
                }
                else if ( splittedInput[0] == "CLEAR" )
                {
                    it = mapShapes.begin();

                    while( it != mapShapes.end() )
                    {
                        wipe = it++;
                        delete wipe->second;
                    }
                    mapShapes.clear();
                    //currHistory = new FullHistory("delete",mapShapes);
                    //undo.push(currHistory);
                    cout << "OK" << endl;
                }
                else if ( splittedInput[0] == "DELETE" )
                {
                    string name = splittedInput[1];
                    if (mapShapes.find(name) != mapShapes.end())
                    {
                        //currHistory = new SingleHistory( "delete", mapShapes.find(name)->second );
                        //undo.push(currHistory);
                        mapShapes.erase(name);
                        cout << "OK" << endl;
                    }
                    else
                    {
                        cout << "NOT FOUND" << endl;
                    }
                }
                else if( splittedInput[0] == "S" )
                {
                    string name =splittedInput[1];

                    int p[4];
                    p[0] = atoi(splittedInput[2].c_str());
                    p[1]= atoi(splittedInput[3].c_str());
                    p[2] = atoi(splittedInput[4].c_str());
                    p[3] = atoi(splittedInput[5].c_str());
                    Segment* s= new Segment(name,p);
                    mapShapes.insert(pair<string,Shape*>(name, s));
                    //currHistory = new SingleHistory("create", s);
                    //undo.push(currHistory);
                    cout << "OK" << endl;
                }
                else if( splittedInput[0] == "R" )
                {
                    string name =splittedInput[1];

                    int p[4];
                    p[0] = atoi(splittedInput[2].c_str());
                    p[1]= atoi(splittedInput[3].c_str());
                    p[2] = atoi(splittedInput[4].c_str());
                    p[3] = atoi(splittedInput[5].c_str());
                    Rectangle* s= new Rectangle(name,p);
                    mapShapes.insert(pair<string,Shape*>(name, s));

                    cout << "OK" << endl;
                }

                else if( splittedInput[0] == "PC" )
                {
                    int size = splittedInput.size()-2;
                    int p[size];
                    for(int i = 0; i<size; i++)
                    {
                        p[i]=atoi(splittedInput[i+2].c_str());
                    }
                    if(size>4 && Polygone::convex(p,size))
                    {
                        mapShapes.insert(pair<string,Shape*>(splittedInput[1], new Polygone(splittedInput[1] ,p, size)));
                        cout<<"OK"<<endl;
                    }
                    else
                    {
                    cerr<<"Polynome is not convex"<<endl;
                    }
                }
                else if( splittedInput[0] == "OR" )
                {
                    int size = splittedInput.size();
                    vector<Shape*> vec;
                    string nameShape;
                    string name = splittedInput[1];
                    for( int i = 2; i<size; i++)
                    {
                        nameShape = splittedInput[i];
                        vec.push_back( new Shape( *(mapShapes[nameShape]) ) );
                    }
                    mapShapes.insert(pair<string,Shape*>(name, new Union(name,vec)));
                    cout<<"OK"<<endl;

                }
                else if( splittedInput[0] == "OI" )
                {
                    int size = splittedInput.size();
                    vector<Shape*> vec;
                    string nameShape;
                    string name = splittedInput[1];
                    for( int i = 2; i<size; i++)
                    {
                        nameShape = splittedInput[i];
                        vec.push_back( new Shape( *(mapShapes[nameShape]) ) );
                    }
                    mapShapes.insert(pair<string, Shape*>( name, new Intersection(name,vec) ) );
                    cout<<"OK"<<endl;

                }
                else if( splittedInput[0] == "HIT")
                {
                    string name = splittedInput[1];
                    int x = atoi(splittedInput[2].c_str());
                    int y = atoi(splittedInput[3].c_str());
                    if(mapShapes.find(name)==mapShapes.end())
                    {
                        cout << "NO" << endl;
                    }
                    else
                    {
                        if( mapShapes[name]->Contains(Point(x, y)))
                        {
                            cout << "YES" << endl;
                        }
                        else
                        {
                            cout << "NO" << endl;
                        }
                    }
                    //delete p;
                }
                else if( splittedInput[0] == "MOVE")
                {
                    string name = splittedInput[1];
                    int dx = atoi(splittedInput[2].c_str());
                    int dy = atoi(splittedInput[3].c_str());

                    mapShapes[name]->Move(dx, dy);

                    cout << "OK" << endl;
                }
                else
                {
                    //TODO: Change that to an error message
                    for(unsigned int i = 0; i < splittedInput.size(); i++)
                    {
                        //cout << splittedInput[i] << endl;
                    }
                }
        }//end of the decision blocks



	}//end of the loop

	//memory cleaning
	//erasing the contents of the model
	it = mapShapes.begin();
	while( it != mapShapes.end() )
	{
		wipe = it++;
		delete wipe->second;
	}
	//erasing the history
	while ( !redo.empty() )
    {
        redo.top()->Clean();//avoids memory leaks
        redo.pop();
    }
    while ( !undo.empty() )
    {
        undo.top()->Clean();//avoids memory leaks
        undo.pop();
    }


	return 0;
}

//------------------------------------------------------ Definition des fonctions
