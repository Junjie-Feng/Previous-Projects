// Name : Junjie Feng
// Course : 16:332:503:01 , Programming Financial
// Title : In-Class 3 
//Date of Submission: 09/21/2015

#include<iostream>
#include<cmath>
#include <iomanip>
#include <conio.h>
using namespace std;

int managevote(const int[], int[], int, int);

int main()
{
	const int votenumber = 20, candidatenumber = 5;//constant integers variable declaration.
	int vote[votenumber], i, candidate[candidatenumber] = { 0 };//integer tpye variable & array declaration
	cout << "This program is used to  tallies up the number of votes each candidate received and pronounces a winner" << endl << endl;
	cout << "please enter number 1--" << candidatenumber << " represent the Candidate 1--" << candidatenumber << " respectively:" << endl;//prompt
	for (i = 0; i <= votenumber - 1; i++)
	{
		cout << "\nvoter " << i + 1 << " : ";//prompt
		cin >> vote[i];
		if (vote[i] > 5 || vote[i] < 1)// if the vote is over the range 1--5, the vote is invalid
			cout << "This is a invalid vote. This vote will not be counted." << endl;
	}

	cout << "\nThe next apprentice is Candidate_" << managevote(vote, candidate, votenumber, candidatenumber) << "!! Congratulation!! " << endl << endl
		<< "And here is the full result of this poll" << endl
		<< setw(14) << "Candidate Name" << setw(8) << "Votes" << endl;
	for (i = 0; i <= candidatenumber - 1; i++)
		cout << setw(13) << "Candidate_" << i + 1 << setw(8) << candidate[i] << endl;//display the result of the poll
	return 0; // show the successful termination of the program
}//end main

 //managevote function is to finding out the winner of the poll
int managevote(const int vote[], int candidate[], int votenumber, int candidatenumber)
{
	int i, j = 0, max = 0, winner;
	for (i = 0; i <= votenumber - 1; i++)//for loop is counting the vote
		candidate[vote[i] - 1]++;
	for (i = 0; i <= candidatenumber - 1; i++)//for loop is searching the candidate who get the maximum votes 
	{
		if (candidate[i] >= max)
		{
			max = candidate[i];
			winner = i + 1;
		}
	}
	for (i = 0; i <= candidatenumber - 1; i++)//for loop is checking whether there is more than one candidate get the maximum votes
	{
		if (max == candidate[i])
			j++;
	}
	if (j == 1)//if there is only one get the maximum votes, this one is winner, otherwise we need another poll
		return winner;
	else
	{
		cout << "\nWe need to conduct another poll because some candidates all got the maximum number of votes.\n" << endl
			<< "And here is the full result of this poll" << endl
			<< setw(14) << "Candidate Name" << setw(8) << "Votes" << endl;
		for (i = 0; i <= candidatenumber - 1; i++)
			cout << setw(13) << "Candidate_" << i + 1 << setw(8) << candidate[i] << endl;//display the result of the poll
		exit(0);
	}
}
