#include <iostream>
#include "Q1_180942_header.h"
#include <cstring>
#include <fstream>
using namespace std;

CricketTeam:: CricketTeam()
{
	membernames=nullptr;
	no_of_members=0;
	teamName=nullptr;
	for(int i=0; i<10; i++)
		Scoreinlast10matches[i]=0;
	rank=0;
	captain="";
}
CricketTeam:: CricketTeam(string name, int members)
{
	membernames=nullptr;
	if(members>0 && members<12)
		no_of_members=members;
	else 
		no_of_members=0;
	teamName=nullptr;
	int len=name.length();
	teamName=new char[len+1];
	strcpy(teamName,name.c_str());
	for(int i=0; i<10; i++)
		Scoreinlast10matches[i]=-1;
	rank=0;
	captain="";
}
CricketTeam::CricketTeam(string filename)
{
	ifstream fin;
	string data;
	int num;
	fin.open(filename);
	if (fin.is_open())
	{
		while(!fin.eof())
		{
			getline(fin,data,':');
			getline(fin,data);
			int len=data.length();
			teamName=new char[len+1];
			strcpy(teamName,data.c_str());
			getline(fin,data,':');
			fin>>num;
			if(num>0 && num<12)
				no_of_members=num;
			else 
				no_of_members=0;
			membernames=new string[no_of_members];
			for(int i=0; i<no_of_members; i++)
			{
				getline(fin,data);
				membernames[i]=data;
			}
			getline(fin,data,':');
			fin>>num;
			if (num>0)
				rank=num;
			else 
				rank=0;
			getline(fin,data,':');
			getline(fin,data);
			captain=data;
			getline(fin,data,':');
			for(int i=0; i<10; i++)
			{
				getline(fin,data,',');
				num= stoi(data);
				Scoreinlast10matches[i]=num;
			}
		}


	}
	else
		cout<<"File did not open"<<endl;
}
void CricketTeam::set_Captain(string name)
{
	captain=name;
}
void CricketTeam::set_Rank(int r)
{
	if (r>0)
		rank=r;
	else
		rank=0;
}
void CricketTeam:: set_teamName(string name)
{
	if(teamName!=nullptr)
	{
		delete teamName;
	}
	int len=name.length();
	teamName=nullptr;
	teamName=new char[len+1];
	strcpy(teamName,name.c_str());
}
void CricketTeam:: set_no_of_members(int n) 
{
	if(n>0 && n<12)
		no_of_members=n;
	else 
		no_of_members=0;
	membernames=new string[no_of_members];
}
string CricketTeam:: get_Captain()
{
	return captain;
}
int CricketTeam:: get_Rank()
{
	return rank;
}
string CricketTeam:: get_teamName()
{
	return teamName;
}
int CricketTeam:: get_no_of_members()
{
	return no_of_members;
}
void CricketTeam:: inputTeamMember(string name)
{
	bool arr_is_full=false;
	for (int i=0; i<no_of_members;i++)
		if (membernames[i]!="")
			arr_is_full=true;
		else
			arr_is_full=false;
	if (arr_is_full==false)
	{
		for (int i=0; i<no_of_members;i++)
		{
			if (membernames[i]=="")
			{
				membernames[i]=name;
			}
		}
	}
	else
		cout<<"No place for new team member"<<endl;
}
void CricketTeam:: inputScore(int num) 
{
	bool check=false;
	for (int i=0; i<10; i++)
	{
		if(Scoreinlast10matches[i]==-1)
			check=false;
		else
			check=true;
	}

	if (check==false)
	{
		if (num>=0)
		{
			for(int i=0; i<10; i++)
			{
				if(Scoreinlast10matches[i]==-1)
				{
					Scoreinlast10matches[i]=num;
					check=true;
				}
			}
		}
	}
	else
	{
		if (num>-1)
		{

			for(int i=0; i<9; i++)
				Scoreinlast10matches[i]=Scoreinlast10matches[i+1];
			Scoreinlast10matches[9]==num;
		}
	}
}
float CricketTeam:: avg_score() //calculate and prints average score of a team
{
	float sum=0;
	float avg=0;
	for(int i=0; i<10; i++)
	{
		sum=sum+Scoreinlast10matches[i];
	}
	avg=sum/10;
	if (avg>0)
		return avg;
	else
		return 0;
}
void CricketTeam:: latest_score()  //prints latest score
{
	if(teamName!=nullptr)
	{
		cout<<"Team Name: ";
		for(int i=0; teamName[i]!='\0';i++)
			cout<<teamName[i];
		cout<<endl;
	}
	cout<<"Captain: " <<captain<<endl;
	cout<<"Latest score: ";
	for(int i=9; i>=0;i--)
		if (Scoreinlast10matches[i]!=-1)
		{
			cout<<Scoreinlast10matches[i]<<endl;
			break;
		}
}
void CricketTeam:: print_team() //prints data of a team
{
	if(teamName!=nullptr)
	{
	cout<<"Team Name: ";
	for (int i=0; teamName[i]!='\0';i++)
		cout<<teamName[i];
	}
	else
		cout<<"No team name";
	cout<<endl;
	

	cout<<"Rank: "<<rank<<endl;
	cout<<"Captain: ";
	cout<<captain<<endl;
	if (membernames!=nullptr)
	{
	cout<<"No of members: "<< no_of_members<<endl;
	for (int i=0; i<no_of_members;i++)
		cout<<membernames[i];
	}
	else
		cout<<"No team members";
	cout<<endl;
	cout<<"Previous Scores: ";
	for (int i=0;i<10;i++)
		cout<<Scoreinlast10matches[i]<<" ";
	cout<<endl;
}
bool CricketTeam:: compare(CricketTeam other) // compare two teams average score and return 0 if 2nd team is better
{
	float a1=0, a2=0;
	a1=avg_score();
	a2=other.avg_score();
	if (a2>a1)
		return 0;
	else 
		return 1;
}
void CricketTeam:: input() //to take input from console or from file
{
	cout<<"Press 1 for input from console or 2 from file"<<endl;
	int n=0;
	cin>>n;
	if (n==2)
	{
		ifstream fin;
		string filename;
		string data;
		int num;
		cout<<"Enter file name: "<<endl;
		cin>>filename;
		fin.open(filename);
		if(!fin.is_open())
			cout<<"File did not open"<<endl;
		while(!fin.eof())
		{
			getline(fin,data,':');
			getline(fin,data);
			int len=data.length();
			teamName=new char[len+1];
			strcpy(teamName,data.c_str());
			getline(fin,data,':');
			fin>>num;
			if(num>0 && num<12)
				no_of_members=num;
			else 
				no_of_members=0;
			membernames=new string[no_of_members];
			for(int i=0; i<no_of_members; i++)
			{
				getline(fin,data);
				membernames[i]=data;
			}
			getline(fin,data,':');
			fin>>num;
			if (num>0)
				rank=num;
		}


	}
	else if (n==1)
	{
		string temp; 
		cout<<"Enter Team Name: "<<endl;
		cin>>temp;
		int len=temp.length();
		teamName=new char[len+1];
		strcpy(teamName,temp.c_str());
		cout<<"Enter Team rank: "<<endl;
		cin>>rank;
		cin.ignore();
		cout<<"Enter Captain Name: "<<endl;
		getline(cin,captain);
		cout<<"No of Team members: "<<endl;
		cin>>no_of_members;
		membernames=new string[no_of_members];
		cin.ignore();
		cout<<"Enter Names of members: "<<endl;
		for (int i=0; i<no_of_members;i++)
		{
			getline(cin,membernames[i]);
		}
		cout<<"Enter 10 previous scores: "<<endl;
		for(int i=0; i<10; i++)
			cin>>Scoreinlast10matches[i];
	}
	else 
		cout<<"Wrong input"<<endl;
}
CricketTeam:: ~CricketTeam()
{
	delete[] membernames;
	delete[] teamName;
}
