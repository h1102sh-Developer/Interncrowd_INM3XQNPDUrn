         /*   WEEK 1
      TASK 2: VOTING SYSTEM
       Name: Harsh Shuddhalwar
       InternCrowd ID:INM3XQNPDUrn
      Domain Name: C,C++ */
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
int main()
{
	int choice, i, N;
// Stores the names of candidates
	vector<string> candidates
		= { "A", "B", "C", "D", "E" };
	N = candidates.size();
	    cout<<"\n  Welcome to Election/Voting 2023 \n\n";
// Stores the votes of candidates
	vector<int> votes(N);
	do {
		cout << "1. Cast The Vote \n";
		cout << "2. Find Vote Count \n";
		cout << "3. Find Leading Candidate \n";
		cout << "0. Exit \n";
// Take input of options
cout << "\n Please Enter Your choice: ";
cin >> choice;
		cout << "\n";
// Switch Statement
		switch (choice) {
case 1: {
			int candidatechoice;
// Display the names of
			// all the candidates
			for (i = 0; i < N; i++)
				cout << i + 1 << "."
					<< candidates[i]
					<< "\n";
cout << "Choose your candidate: ";
// Taking user's vote
			cin >> candidatechoice;
			cout << "\n";
// Update the vote of the
			// chosen candidate
			votes[candidatechoice - 1]++;
			break;
		}
		case 2: {
			// Display the name and votes
			// of each
			// candidate
			for (i = 0; i < N; i++)
				cout << i + 1 << "."
					<< candidates[i] << " "
					<< votes[i] << "\n";
			break;}
		case 3: {
			int mx = 0;
			string winner;
			// Find the candidate with
			// maximum votes
			for (int i = 0; i < N; i++)
				if (votes[i] > mx) {
					mx = votes[i];
					winner = candidates[i];
				}
			int flag = 0;
			// Check whether there are
			// more than one candidates
			// with maximum votes
			for (int i = 0; i < N; i++)		
				if (votes[i] == mx
					&& winner != candidates[i]) {
				flag = 1;
				break;
				}
			if (!flag)
				cout << "The current winner is "
				<< winner << ".\n";
			else
				cout << "No clear winner\n";
		}
		default:
			"Select a correct option";
		}
	} while (choice != 0);
	getch();
}
 	

