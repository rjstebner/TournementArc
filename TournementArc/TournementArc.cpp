#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <thread>
#include <chrono>
#include <map>

// Function to generate a random number between min and max (inclusive)
int getRandomNumber(int min, int max) {
    static const double fraction = 1.0 / (RAND_MAX + 1.0);
    return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}

// Function to generate a random adjective-noun combination
std::string getTeamName() {
    // List of adjectives
    std::string adjectives[] = { "Red", "Happy", "Swift", "Bright", "Playful", "Funky", "Tiny", "Quick", "Lumbering", "Spicy", "Chilly", "Obnoxious", "Silent", "Bombastic", "Creeping", "Hard", "Soft", "Crummpled", "Feeble", "Silky", "Teal", "Purple", "Wet"};

    // List of nouns
    std::string nouns[] = { "Cats", "Suns", "Mountains", "Dragons", "Pandas", "Town", "City", "Moose", "Queens", "Trains", "P", "Dogs", "Flowers", "Tree", "Raptors", "Salmons", "Assassains", "Clouds", "Stars", "Moons", "Oceans", "Sands", "Rocks", "Mushrooms", "Donkeys" };

    int randomAdjectiveIndex = getRandomNumber(0, sizeof(adjectives) / sizeof(adjectives[0]) - 1);
    int randomNounIndex = getRandomNumber(0, sizeof(nouns) / sizeof(nouns[0]) - 1);

    return adjectives[randomAdjectiveIndex] + " " + nouns[randomNounIndex];
}


std::string runTournament(int numTeams) {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(0)));

    int remainingTeams = numTeams;

    // Arrays to store team names and numbers
    std::string* teamNames = new std::string[numTeams];
    int* teamNumbers = new int[numTeams];

    // Generate a random adjective-noun combination for each team
    for (int i = 0; i < numTeams; ++i) {
        teamNames[i] = getTeamName();
        teamNumbers[i] = getRandomNumber(1, 20);

        // Display the generated team name and number
        std::cout << "Team " << (i + 1) << ": " << teamNames[i] << " - Power Ranking : " << teamNumbers[i] << std::endl;
    }

    std::map<std::string, std::string> favoriteTeams;
    std::string teamName;
    std::string colorCodes[] = { "\033[35m", "\033[36m", "\033[96m", "\033[34m", "\033[94m", "\033[33m", "\033[93m", "\033[31m", "\033[91m", "\033[95m", "\033[32m", "\033[92m", "\033[37m", "\033[97m", "\033[30m", "\033[90m", };
    int colorIndex = 0;
    char addMore;

    do {
        std::cout << "\nEnter your favorite team: ";
        std::cin.ignore();
        std::getline(std::cin, teamName);

        favoriteTeams[teamName] = colorCodes[colorIndex % (sizeof(colorCodes) / sizeof(colorCodes[0]))];

        colorIndex++;

        std::cout << "Do you want to add more favorite teams? (y/n): ";
        std::cin >> addMore;
    } while (addMore == 'y' || addMore == 'Y');


    // Perform the duels
    int round = 1;
    while (remainingTeams > 1) {
        std::cout << "\nRound " << round << ":\n";
        std::this_thread::sleep_for(std::chrono::seconds(2));

        for (int i = 0; i < remainingTeams; i += 2) {
            // Get Scores
            int score1 = getRandomNumber(0, teamNumbers[i]);
            int score2 = getRandomNumber(0, teamNumbers[i + 1]);

            // Compare the numbers to determine the winner
            std::string team1 = (favoriteTeams.count(teamNames[i]) > 0) ? favoriteTeams[teamNames[i]] + teamNames[i] + "\033[0m" : teamNames[i];
            std::string team2 = (favoriteTeams.count(teamNames[i + 1]) > 0) ? favoriteTeams[teamNames[i + 1]] + teamNames[i + 1] + "\033[0m" : teamNames[i + 1];


            if (score1 > score2) {
                std::cout << team1 << " vs " << team2 << "\n";
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << " - Winner: " << team1 << " Final Score " << score1 << " - " << score2 << "\n";
                std::this_thread::sleep_for(std::chrono::seconds(1));

                teamNames[i / 2] = teamNames[i];
                teamNumbers[i / 2] = teamNumbers[i];
            }
            else if (score1 < score2) {
                std::cout << team1 << " vs " << team2 << "\n";
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << " - Winner: " << team2 << " Final Score " << score1 << " - " << score2 << "\n";
                std::this_thread::sleep_for(std::chrono::seconds(1));

                teamNames[i / 2] = teamNames[i + 1];
                teamNumbers[i / 2] = teamNumbers[i + 1];
            }
            else {
                int coinFlip = getRandomNumber(0, 1);
                if (coinFlip == 0) {
                    std::cout << team1 << " vs " << team2 << "\n ";
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    std::cout << " - Winner: " << team1 << " Final Score (Overtime) " << score1 + 1 << " - " << score2 << "\n";
                    std::this_thread::sleep_for(std::chrono::seconds(1));

                    teamNames[i / 2] = teamNames[i];
                    teamNumbers[i / 2] = teamNumbers[i];
                }
                else {
                    std::cout << team1 << " vs " << team2 << "\n";
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                    std::cout << " - Winner: " << team2 << " Final Score (Overtime) " << score1 << " - " << score2 + 1 << "\n";
                    std::this_thread::sleep_for(std::chrono::seconds(1));

                    teamNames[i / 2] = teamNames[i + 1];
                    teamNumbers[i / 2] = teamNumbers[i + 1];
                }
            }
        }
        remainingTeams /= 2;
        round++;
    }

    // Display the overall winner
    std::cout << "\nOverall Winner: "
        << ((favoriteTeams.count(teamNames[0]) > 0)
            ? favoriteTeams[teamNames[0]] + teamNames[0] + "\033[0m"
            : teamNames[0])
        << "\n";
    std::string winner;
    winner = teamNames[0];    
    // Clean up dynamic memory
    delete[] teamNames;
    delete[] teamNumbers;

    return winner;
}
#include <fstream> // Include this at the top of your file

int main() {
    int numTeams;
    while (true) {
        std::cout << "Enter the number of teams (2, 4, 8, 16, 32, or 64): ";
        std::cin >> numTeams;
        if (numTeams == 2 || numTeams == 4 || numTeams == 8 || numTeams == 16 || numTeams == 32 || numTeams == 64) {
            break;
        }
        std::cout << "Invalid number of teams. Please enter a number from the list.\n";
    }
    std::string winner = runTournament(numTeams);

    // Open a file in append mode
    std::ofstream outFile("winner.txt", std::ios::app);

    // Check if the file is open
    if (!outFile) {
        std::cerr << "Failed to open the file.\n";
        return 1;
    }

    // Get the current date and time
    std::time_t t = std::time(0);
    std::tm now;
    localtime_s(&now, &t);
    outFile << "-----------------\n"
        << "Date: " << (now.tm_year + 1900) << '-'
        << (now.tm_mon + 1) << '-'
        << now.tm_mday << "\n"
        << "Time: " << now.tm_hour << ":"
        << now.tm_min << ":"
        << now.tm_sec << "\n"
        << "The winner of the tournament is: " << winner << "\n"
        << "-----------------\n"
        << "\n";

    // Close the file
    outFile.close();

    return 0;
}