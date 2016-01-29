/*************************************************************************
                           Module main
                             -------------------
    d�but                : ${date}
    copyright            : (C) ${year} par ${user}
*************************************************************************/

//c
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

//------------------------------------------------------ Include personnel
#include "Point.h"
#include "Shape.h"
#include "Segment.h"
#include "Polygone.h"
#include "Rectangle.h"
	//#include "MultiShape.h"
		//#include "Intersection.h"
		//#include "Union.h"

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
	//infinite loop variables
	bool loop = true;
	string input;

	//------------------------------------------------------ Input
	while( loop )
	{
		vector<string> splittedInput;
		getline(cin, input);
		int index= input.find(' ');
		while( index!=-1 )
		{
				splittedInput.push_back(input.substr( 0, input.find(' ') ) );
				input=input.substr(input.find(' ')+1);
				index= input.find(' ');
		}
		splittedInput.push_back(input);

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

				cout << "OK" << endl;
			}
			else if ( splittedInput[0] == "DELETE" )
			{
				string name = splittedInput[1];
				mapShapes.erase(name);

				cout << "OK" << endl;
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
				int size=splittedInput.size()-2;
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

			else if(splittedInput[0] == "LIST")
			{
				string a=list(mapShapes);
				cout<<a;
			}
			else
			{
				//TODO: Change that to an error message
				for(unsigned int i = 0; i < splittedInput.size(); i++)
				{
					//cout << splittedInput[i] << endl;
				}
			}



	}//end of the loop

	//memory cleaning
	//erasing the contents of the model
	it = mapShapes.begin();
	while( it != mapShapes.end() )
	{
		wipe = it++;
		delete wipe->second;
	}


	return 0;
}

//------------------------------------------------------ Definition des fonctions
