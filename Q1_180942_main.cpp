#include <iostream>
#include "Q1_180942_header.h"
#include <fstream>
using namespace std;
int main()
{
	CricketTeam team1;
	team1.print_team();
	CricketTeam team2("Q1_180942_file.txt");
	team2.print_team();
	team2.latest_score();
	int result=team1.compare(team2);
	cout<<result;
	team1.inputScore(500);
	return 0;
}