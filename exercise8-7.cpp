#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int findWinner(int votes[]);
void printResults(string candidates[], int votes[]);
double calculatePercentage(int votes[], int vote);

const int numberOfCandidates = 5;

int main()
{
    
    string candidates[numberOfCandidates];
    int votes[numberOfCandidates];

    
    cout << "Enter 5 candidates followed by number of votes recieved: ";
    for (int i = 0; i < numberOfCandidates; i++) {
        cin >> candidates[i] >> votes[i];
    }
    printResults(candidates, votes);
    cout << "The Winner of the Election is " << candidates[findWinner(votes)] << endl;
    return 0;
}

double calculatePercentage(int votes[], int vote){
    int sumOfVotes = 0;
    
    for (int i = 0; i < numberOfCandidates; i++) {
        sumOfVotes += votes[i];
    }
    
    double percentage = static_cast<double>(vote) / static_cast<double>(sumOfVotes);

    return percentage*100;
}


void printResults(string candidates[], int votes[]){
    cout << "Candidate Votes Received % of Total Votes" << endl;
    cout << fixed << showpoint << setprecision(2) << endl;
    for (int i = 0; i < numberOfCandidates; i++) {
        
        cout << candidates[i] << setw(15) << votes[i] << setw(15);
        double percentage = calculatePercentage(votes, votes[i]);
        
        cout << percentage << endl;
        
    }
}

int findWinner(int votes[]){
    int winner = 0;
    for (int i = 0; i < numberOfCandidates; i++) {
        if (votes[winner] <= votes[i])
            winner = i;
    }
    return winner;
}
