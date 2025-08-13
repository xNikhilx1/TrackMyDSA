// TrackMyDSA - Created by Nikhil
#include <bits/stdc++.h>
using namespace std;

struct Problem
{
    string title;
    string topic;
    string difficulty;
    bool isSolved;
    string notes;
};

vector<Problem> problems;

void loadData()
{
    ifstream file("data.txt");
    Problem p;
    while (getline(file, p.title))
    {
        getline(file, p.topic);
        getline(file, p.difficulty);
        file >> p.isSolved;
        file.ignore();
        getline(file, p.notes);
        problems.push_back(p);
    }
    file.close();
}

void saveData()
{
    ofstream file("data.txt");
    for (auto &p : problems)
    {
        file << p.title << "\n"
             << p.topic << "\n"
             << p.difficulty << "\n"
             << p.isSolved << "\n"
             << p.notes << "\n";
    }
time_t now = time(0);
file << "Last Updated: " << ctime(&now) << "\n";

    file.close();
}

void addProblem()
{
    Problem p;
    cin.ignore();
    cout << "Title: ";
    getline(cin, p.title);
    cout << "Topic: ";
    getline(cin, p.topic);
    cout << "Difficulty (Easy/Medium/Hard): ";
    getline(cin, p.difficulty);
    p.isSolved = false;
    cout << "Notes: ";
    getline(cin, p.notes);
    problems.push_back(p);
    saveData();
    cout << "Added!\n";
}

void viewProblems()
{
    if (problems.empty())
    {
        cout << "No problems found.\n";
        return;
    }
    for (int i = 0; i < problems.size(); ++i)
    {
        cout << "\n[" << i + 1 << "] " << problems[i].title
             << " | " << problems[i].topic
             << " | " << problems[i].difficulty
             << " | " << (problems[i].isSolved ? "Solved" : "Unsolved")
             << "\nNotes: " << problems[i].notes << "\n";
    }
}

void markAsSolved()
{
    int idx;
    viewProblems();
    cout << "\nEnter problem number to mark as solved: ";
    cin >> idx;
    if (idx >= 1 && idx <= problems.size())
    {
        problems[idx - 1].isSolved = true;
        saveData();
        cout << "Marked as solved.\n";
    }
    else
    {
        cout << "Invalid index.\n";
    }
}

void filterByTopic()
{
    string topic;
    cin.ignore();
    cout << "Enter topic: ";
    getline(cin, topic);
    bool found = false;
    for (auto &p : problems)
    {
        if (p.topic == topic)
        {
            cout << p.title << " | " << p.difficulty
                 << " | " << (p.isSolved ? "Solved" : "Unsolved") << "\n";
            found = true;
        }
    }
    if (!found)
        cout << "No problems found in this topic.\n";
}

void showStats()
{
    int total = problems.size(), solved = 0;
    for (auto &p : problems)
        if (p.isSolved)
            solved++;
    cout << "Total: " << total << " | Solved: " << solved
         << " | Unsolved: " << total - solved << "\n";
}

int main()
{
    loadData();
    int choice;
    do
    {
        cout << "\n====== TrackMyDSA ======\n";
        cout << "1. Add Problem\n";
        cout << "2. View Problems\n";
        cout << "3. Mark as Solved\n";
        cout << "4. Filter by Topic\n";
        cout << "5. Show Stats\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addProblem();
            break;
        case 2:
            viewProblems();
            break;
        case 3:
            markAsSolved();
            break;
        case 4:
            filterByTopic();
            break;
        case 5:
            showStats();
            break;
        }
    } while (choice != 6);

    cout << "Thanks for using TrackMyDSA!\n";
    return 0;
}
