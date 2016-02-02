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
#include <ostream>
#include <cstdlib>
#include <exception>
#include <new>
#include <stack>

//------------------------------------------------------ Include personnel
#include "Point.h"
#include "SingleShape.h"
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

string list(map<string, Shape*> & mapShapes)
{
	map<string, Shape*>::iterator it;
	string list="";
	for(it=mapShapes.begin(); it!=mapShapes.end(); it++)
	{
		list+=it->second->print();

	}
	return list;
}
string* treatInput(string input);
void exportModel(string fileName, map<string, Shape*> & mapShapes);//OPTION SI COUT
void importModel(string fileName, map<string, Shape*> & mapShapes);
//void fillMultiShape(MultiShape & toFill, fstream & aStream);//used by import, potentially in a recursive way
map<string, Shape*> mapShapes;
map<string, Shape*>::iterator it;
map<string, Shape*>::iterator wipe;
stack<History*> undo;
stack<History*> redo;
History* currHistory;
//------------------------------------------------------ Main
int main(int argc, char **argv)
{
	//------------------------------------------------------ Declaration des variables


	//History


	string loop = "1";
	string input;

	//------------------------------------------------------ Input
	while( loop=="1" )
	{
		vector<string> splittedInput;
		getline(cin, input);
		string * ret=treatInput(input);
		loop=ret[0];
		cout<<ret[1];
		delete[] ret;
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
string* treatInput(string input)
{

	string* ret=new string[2];
	ret[0]="1";
	ret[1]="";
	vector<string> splittedInput;
	int index= input.find(' ');
	while( index!=-1 )
	{
	splittedInput.push_back(input.substr( 0, input.find(' ') ) );
	input=input.substr(input.find(' ')+1);
	index= input.find(' ');
	}
	splittedInput.push_back(input);

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

			if ( splittedInput[0] == "EXIT" )
			{
				ret[0]="0";

				ret[1]="BYE\n";
			}
			else if ( splittedInput[0] == "CLEAR\r\n" )
			{
				it = mapShapes.begin();

				while( it != mapShapes.end() )
				{
					wipe = it++;
					delete wipe->second;
				}
				currHistory = new FullHistory("delete",mapShapes);
                undo.push(currHistory);
				mapShapes.clear();
				ret[1]="OK\n";
			}
			else if ( splittedInput[0] == "DELETE" )
			{
				string name = splittedInput[1];
				currHistory = new SingleHistory( "delete", mapShapes.find(name)->second );
                undo.push(currHistory);
				mapShapes.erase(name);
				ret[1]="OK\n";
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
                currHistory = new SingleHistory("create", s);
                undo.push(currHistory);
				ret[1]="OK\n";
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
                currHistory = new SingleHistory("create", s);
                undo.push(currHistory);
				ret[1]="OK\n";
			}

			else if( splittedInput[0] == "PC" )
			{
				int size=splittedInput.size()-2;
				int p[size];
				for(int i = 0; i<size; i++)
				{
					p[i]=atoi(splittedInput[i+2].c_str());
				}
				if(size>4 && Polygone::convex(p,size))
				{
				    Polygone* s = new Polygone(splittedInput[1] ,p, size);
					mapShapes.insert(pair<string,Shape*>(splittedInput[1], s));
					currHistory = new SingleHistory("create", s);
                    undo.push(currHistory);
					ret[1]="OK\n";
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

					//vec.push_back( new Shape( *(mapShapes[nameShape]) ) );
				}
				Union* s = new Union(name,vec);
				mapShapes.insert(pair<string,Shape*>(name, s));
				currHistory = new SingleHistory("create", s);
                undo.push(currHistory);
				cout<<"OK"<<endl;

			}
			else if( splittedInput[0] == "OI" )
			{
				int size = splittedInput.size();
				vector<Shape*> vec;
				string nameShape;
				string name = splittedInput[1];
				bool fab=true;
				int i=0;
				int k=0;
				while(k<splittedInput.size() && fab)
				{
					if(mapShapes.find(splittedInput[k])==mapShapes.end())
					{
						nameShape = splittedInput[i];
						//vec.push_back( new Shape( *(mapShapes[nameShape]) ) );
					}
					else
					{
						fab=false;
						ret[1]="ERR";
					}
					k++;
				}
				Intersection* s = new Intersection(name,vec);
				mapShapes.insert(pair<string, Shape*>( name, s ) );
				currHistory = new SingleHistory("create", s);
                undo.push(currHistory);
				cout<<"OK"<<endl;

			}


			else if( splittedInput[0] == "HIT")
			{
				string name = splittedInput[1];
				int x = atoi(splittedInput[2].c_str());
				int y = atoi(splittedInput[3].c_str());
				if(mapShapes.find(name)==mapShapes.end())
				{
					ret[1]="NO\n";
				}
				else
				{
					if( mapShapes[name]->Contains(Point(x, y)))
					{
						ret[1]="YES\n";
					}
					else
					{
						ret[1]="NO\n";
					}
				}
				//delete p;
			}
			else if( splittedInput[0] == "MOVE")
			{
				string name = splittedInput[1];
				int dx = atoi(splittedInput[2].c_str());
				int dy = atoi(splittedInput[3].c_str());

				//mapShapes[name]->Move(dx, dy);

				ret[1]="OK\n";
			}

			else if(splittedInput[0] == "LIST")
			{
				string a=list(mapShapes);
				cout<<a;
			}

			else if (splittedInput[0]=="SAVE")
			{
				ofstream fichier(splittedInput[1], ios::out);//j'ai modifié cette ligne parce que load et save spécifient le fichier où effectuer l'opération
				fichier << list(mapShapes);
			}
			else if(splittedInput[0]=="LOAD")
			{
				string input;
				currHistory = new FullHistory("create",mapShapes);
                undo.push(currHistory);
				ifstream read(splittedInput[1]);//j'ai modifié cette ligne parce que load et save spécifient le fichier où effectuer l'opération
				while (getline(read, input))
				{
					treatInput(input);
				}


			}
	}

	return ret;
}
