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
#include <set>

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

string list(map<string, Shape*> & mapShapes);
void treatsharp(ifstream & fichier, map<string, Shape*> & mapShapes);
string* treatInput(string input, map<string, Shape*> & mapMult, map<string, Shape*> & mapShapes);
vector<Shape*> createdShape;
map<string, Shape*> Shapes;
stack<History*> undo;
stack<History*> redo;
History* currHistory;
//------------------------------------------------------ Main
int main(int argc, char **argv)
{
	string loop = "1";
	string input;
	while( loop=="1" )
	{
		vector<string> splittedInput;
		getline(cin, input);
		string * ret=treatInput(input, Shapes, Shapes);
		loop=ret[0];
		cout<<ret[1];
		delete[] ret;
	}//end of the loop

	//memory cleaning
	//erasing the contents of the model
	for(int i=0; i<createdShape.size(); i++)
	{
		if(createdShape[i]!=0)
		{
			delete createdShape[i];
		}
	}
	//erasing the history
	while ( !redo.empty() )
	{
		delete redo.top();
		redo.pop();
	}
	while ( !undo.empty() )
	{
		delete undo.top();
		undo.pop();
	}


	return 0;
}

//------------------------------------------------------ Definition des fonctions
string* treatInput(string input, map<string, Shape*> & mapMult, map<string, Shape*> & mapShapes)
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
	if(splittedInput[0]=="R" || splittedInput[0]=="S" || splittedInput[0]=="P" || splittedInput[0]=="OR" || splittedInput[0]=="LOAD" || splittedInput[0]=="OI")
	{
		while ( !redo.empty() )
		{
			delete redo.top();
			redo.pop();
		}
	}

	if( splittedInput[0] == "UNDO" )
	{
		if( !undo.empty() )
		{
			currHistory = undo.top();
			redo.push(currHistory->Cancel(mapShapes)) ;
			undo.pop();
			delete currHistory;
			ret[1]="OK\n";
		}
		else
		{
			ret[1]="#NOTHING TO UNDO\n";
		}
	}
	else if(splittedInput[0] == "LIST")
	{
		string a=list(mapShapes);
		ret[1]=a;
	}


	else if (splittedInput[0] == "REDO")
	{
		if( !redo.empty() )
		{
			currHistory = redo.top();
			undo.push( currHistory->Cancel(mapShapes) );
			redo.pop();
			delete currHistory;
			ret[1]="OK\n";
		}
		else
		{
			ret[1]="#NOTHING TO REDO\n";
		}
	}



	else if ( splittedInput[0] == "EXIT" )
	{
		ret[0]="0";

		ret[1]="BYE\r\n";
	}

	else
	{

		if ( splittedInput[0] == "CLEAR" )
		{
			currHistory = new FullHistory("delete",mapShapes);
			undo.push(currHistory);
			mapShapes.clear();
			ret[1]="OK\n";
		}
		else if ( splittedInput[0] == "DELETE" )
		{

			bool del=true;
			int p=1;
			while(p<splittedInput.size() && del)
			{
				if(mapShapes.find(splittedInput[p])==mapShapes.end())
				{
					del=false;
				}
				p++;
			}
			if(del)
			{
				ret[1]="OK\n";
				currHistory = new FullHistory("create", mapShapes);
				undo.push(currHistory);
				for(int i=0; i<splittedInput.size(); i++)
				{
					if(mapShapes.find(splittedInput[i])!=mapShapes.end())
					{
						mapShapes.erase(splittedInput[i]);
					}
				}
			}
			else
			{
				ret[1]="ERR\n";
			}
		}
		else if( splittedInput[0] == "S" )
		{
			if(splittedInput.size()!=6)
			{
				ret[1]="ERR\n";
			}
			else
			{
				string name =splittedInput[1];

				int p[4];
				p[0] = atoi(splittedInput[2].c_str());
				p[1]= atoi(splittedInput[3].c_str());
				p[2] = atoi(splittedInput[4].c_str());
				p[3] = atoi(splittedInput[5].c_str());
				Segment* s= new Segment(name,p);
				createdShape.push_back(s);
				mapShapes.insert(pair<string,Shape*>(name, s));
				currHistory = new SingleHistory("create", s);
				undo.push(currHistory);
				ret[1]="OK\n";
			}
		}

		else if( splittedInput[0] == "R" )
		{
			if(splittedInput.size()!=6)
			{
				ret[1]="ERR\n";
			}
			else
			{
				string name =splittedInput[1];

				int p[4];
				p[0] = atoi(splittedInput[2].c_str());
				p[1]= atoi(splittedInput[3].c_str());
				p[2] = atoi(splittedInput[4].c_str());
				p[3] = atoi(splittedInput[5].c_str());
				Rectangle* s= new Rectangle(name,p);
				mapShapes.insert(pair<string,Shape*>(name, s));
				createdShape.push_back(s);
				currHistory = new SingleHistory("create", s);
				undo.push(currHistory);
				ret[1]="OK\n";
			}
		}

		else if( splittedInput[0] == "PC" )
		{
			if(splittedInput.size()%2!=0)
			{
				ret[1]="ERR\n";
			}
			else
			{
				int size=splittedInput.size()-2;
				int p[size];
				for(int i = 0; i<size; i++)
				{
					p[i]=atoi(splittedInput[i+2].c_str());
				}
				if(size>5 && Polygone::convex(p,size))
				{
					Polygone* s = new Polygone(splittedInput[1] ,p, size);
					createdShape.push_back(s);
					mapShapes.insert(pair<string,Shape*>(splittedInput[1], s));
					currHistory = new SingleHistory("create", s);
					undo.push(currHistory);
					ret[1]="OK\n";
				}
				else
				{
					ret[1]="ERR\n";
				}
			}
		}

		else if( splittedInput[0] == "OR" )
		{
			if(splittedInput.size()>2)
			{
				int size = splittedInput.size();
				vector<Shape*> vec;
				string name = splittedInput[1];
				bool fab=true;
				int k=2;
				while(k<splittedInput.size() && fab)
				{
					if(mapMult.find(splittedInput[k])==mapMult.end())
					{
						fab=false;
						ret[1]="ERR\n";
					}
					k++;
				}

				if(fab)
				{
					for(int i=2; i<splittedInput.size(); i++)
					{
						vec.push_back( (mapMult[splittedInput[i]])->deepCopy());
					}
					Union* s = new Union(name,vec);
					createdShape.push_back(s);
					mapShapes.insert(pair<string,Shape*>(name, s));
					currHistory = new SingleHistory("create", s);
					undo.push(currHistory);
					ret[1]="OK\n";
				}
			}

			else
			{
				ret[1]="ERR\n";
			}

		}
		else if( splittedInput[0] == "OI" )
		{
			if(splittedInput.size()>2)
			{
				int size = splittedInput.size();
				vector<Shape*> vec;
				string name = splittedInput[1];
				bool fab=true;
				int k=2;
				while(k<splittedInput.size() && fab)
				{
					if(mapMult.find(splittedInput[k])==mapMult.end())
					{
						fab=false;
						ret[1]="ERR\n";
					}
					k++;
				}

				if(fab)
				{
					for(int i=2; i<splittedInput.size(); i++)
					{
						vec.push_back( (mapMult[splittedInput[i]])->deepCopy());
					}
					Intersection* s = new Intersection(name,vec);
					createdShape.push_back(s);
					mapShapes.insert(pair<string,Shape*>(name, s));
					currHistory = new SingleHistory("create", s);
					undo.push(currHistory);
					ret[1]="OK\n";

				}
			}
			else
			{
				ret[1]="ERR\n";
			}

		}


		else if( splittedInput[0] == "HIT")
		{
			string name = splittedInput[1];
			int x = atoi(splittedInput[2].c_str());
			int y = atoi(splittedInput[3].c_str());
			if(mapShapes.find(name)==mapShapes.end())
			{
				ret[1]="ERR\n";
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

			mapShapes[name]->Move(dx, dy);

			ret[1]="OK\n";
		}


		else if (splittedInput[0]=="SAVE")
		{
			if(splittedInput.size()==2)
			{
				ofstream fichier(splittedInput[1].c_str(), ios::out);//j'ai modifié cette ligne parce que load et save spécifient le fichier où effectuer l'opération
				fichier << list(mapShapes);
				ret[1]="OK\n";
			}
			else
			{
				ret[1]="ERR\n";
			}
		}
		else if(splittedInput[0]=="LOAD")
		{
			currHistory = new FullHistory("create",mapShapes);
			undo.push(currHistory);

			if(splittedInput.size()>0)
			{
				string input;
				ifstream fichier(splittedInput[1].c_str(), ios::in); //j'ai modifié cette ligne parce que load et save spécifient le fichier où effectuer l'opération
				int i=0;
				while (getline(fichier, input))
				{
					if(input=="#")
					{

						treatsharp(fichier, mapShapes);
					}
					else
					{
						string * t=treatInput(input,mapShapes, mapShapes);
						delete[] t;
					}
					delete undo.top();
					undo.pop();

				}
				ret[1]="OK\n";

			}

			else
			{
				ret[1]="ERR\n";
			}
		}
	}

	return ret;
}
void treatsharp(ifstream & fichier, map<string, Shape*> & mapShapes)
{
	map<string, Shape*> mapMulti;
	string in;
	getline(fichier, in);
	while(in!="\\")
	{
		if(in=="#")
		{
			treatsharp(fichier, mapMulti);
		}
		string* t=treatInput(in, mapMulti, mapMulti);
		delete undo.top();
		undo.pop();
		delete[] t;
		getline(fichier, in);
	}
	getline(fichier, in);
	string* t=treatInput(in, mapMulti, mapShapes);
	delete[] t;

}
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
