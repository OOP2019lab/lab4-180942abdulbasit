#include <iostream>
#include <string>
using namespace std;

class CricketTeam
{
string * membernames;
int no_of_members;
char *teamName;
int Scoreinlast10matches[10];
int rank;
string captain;
public:
	CricketTeam();
	CricketTeam(string, int);
	CricketTeam(string);
	void set_Captain(string);
	void set_Rank(int);
	void set_teamName(string);
	void set_no_of_members(int);
	string get_Captain();
	int get_Rank();
	string get_teamName();
	int get_no_of_members();
	void inputTeamMember(string );
	void inputScore(int);
	float avg_score();
	void latest_score();
	void print_team();
	bool compare(CricketTeam);
	void input();
	~CricketTeam();
};
