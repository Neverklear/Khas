#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

// -----------------------
// Card and Deck Functions
// -----------------------

struct Card {
    string rank;  // "J", "Q", "K", "A", or "2"-"10"
    string suit;  // e.g., "Hearts", "Spades", etc.
};

vector<Card> createDeck() {
    vector<Card> deck;
    vector<string> suits = { "Spades", "Hearts", "Diamonds", "Clubs" };
    vector<string> ranks = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };

    for (const auto& suit : suits) {
        for (const auto& rank : ranks) {
            deck.push_back({ rank, suit });
        }
    }
    return deck;
}

void shuffleDeck(vector<Card>& deck) {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(deck.begin(), deck.end(), default_random_engine(seed));
}

Card drawCard(vector<Card>& deck) {
    if (deck.empty()) {
        cout << "Deck is empty! Need to reshuffle.\n";
        exit(1);
    }
    Card card = deck.back();
    deck.pop_back();
    return card;
}

// Clears the console screen (Windows version)
void clearScreen() {
    system("CLS");
}

// Waits for the player to press Enter
void waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
}

// -----------------------
// Character Classes & Logic
// -----------------------

enum RaceType {
    ELVES,
    DARK_ELVES,
    KINDER,
    DWARF,
    GULLY_DWARF,
    WHITE_ROBES,
    RED_ROBES,
    HEROES_OF_THE_LANCE,
    ENEMIES_OF_THE_LANCE
};

string raceToString(RaceType race) {
    switch (race) {
    case ELVES: return "Elves";
    case DARK_ELVES: return "Dark Elves";
    case KINDER: return "Kinder";
    case DWARF: return "Dwarf";
    case GULLY_DWARF: return "Gully Dwarf";
    case WHITE_ROBES: return "White Robes";
    case RED_ROBES: return "Red Robes";
    case HEROES_OF_THE_LANCE: return "Heroes of the Lance";
    case ENEMIES_OF_THE_LANCE: return "Enemies of the Lance";
    default: return "Unknown";
    }
}

struct Character {
    string name;
    RaceType race;
    string alignment;   // "Good", "Neutral", or "Evil"
    string backstory;

    // Attributes affecting combat and movement
    int HP;
    int MP;
    int attackPower;
    int defensePower;
    int magicPower;
    int magicDefense;
    int speed;
    int evasion;
    int agility;

    // Display all character information
    void displayInfo() {
        cout << "--------------------------\n";
        cout << "Name: " << name << "\n";
        cout << "Race: " << raceToString(race) << "\n";
        cout << "Alignment: " << alignment << "\n";
        cout << "Backstory: " << backstory << "\n";
        cout << "HP: " << HP << "  MP: " << MP << "\n";
        cout << "Attack: " << attackPower << "  Defense: " << defensePower << "\n";
        cout << "Magic: " << magicPower << "  Magic Defense: " << magicDefense << "\n";
        cout << "Speed: " << speed << "  Evasion: " << evasion << "  Agility: " << agility << "\n";
        cout << "--------------------------\n";
    }

    // Applies effects of a Magic Card (J, Q, or K) based on race
    void applyMagicCard(const Card& card) {
        if (card.rank == "J" || card.rank == "Q" || card.rank == "K") {
            cout << name << " uses the magic card " << card.rank << " of " << card.suit << ".\n";
            // Example: White Robes get a boost to magic power; Enemies of the Lance gain extra attack.
            if (race == WHITE_ROBES) {
                cout << "The mystic energies empower your healing arts!\n";
                magicPower += 5;
            }
            else if (race == ENEMIES_OF_THE_LANCE) {
                cout << "Dark energies surge, enhancing your offensive strikes!\n";
                attackPower += 3;
            }
            // Additional race-specific logic can be added here.
        }
    }

    // Applies the effect of a God Card (Ace) based on moral alignment.
    void applyGodCard(const Card& card) {
        if (card.rank == "A") {
            cout << name << " invokes divine intervention with the Ace of " << card.suit << "!\n";
            if (alignment == "Good") {
                cout << "A surge of healing energy restores your vitality.\n";
                HP += 10;
            }
            else if (alignment == "Neutral") {
                cout << "A balanced force enhances your resilience.\n";
                defensePower += 2;
            }
            else if (alignment == "Evil") {
                cout << "Dark energies empower your strikes.\n";
                attackPower += 5;
            }
        }
    }
};

Character createCharacter(string name, RaceType race) {
    if (race == ELVES) {
        return Character{
            name, race, "Good",
            "Elves are graceful and wise, attuned to nature and the mystical arts.",
            120, 80, 15, 10, 12, 12, 14, 10, 12
        };
    }
    else if (race == DARK_ELVES) {
        return Character{
            name, race, "Evil",
            "Dark Elves are mysterious and treacherous, masters of stealth and subterfuge.",
            110, 70, 18, 8, 15, 10, 16, 12, 14
        };
    }
    else if (race == KINDER) {
        return Character{
            name, race, "Good",
            "Kinder are noble warriors with strong hearts and a commitment to honor.",
            130, 60, 20, 12, 10, 14, 12, 14, 10
        };
    }
    else if (race == DWARF) {
        return Character{
            name, race, "Good",
            "Dwarves are sturdy and steadfast, known for their skill in battle and craftsmanship.",
            150, 50, 18, 15, 8, 16, 10, 10, 8
        };
    }
    else if (race == GULLY_DWARF) {
        return Character{
            name, race, "Neutral",
            "Gully Dwarves are cunning survivors, resourceful in the hidden corners of the world.",
            100, 60, 12, 10, 14, 12, 12, 14, 12
        };
    }
    else if (race == WHITE_ROBES) {
        return Character{
            name, race, "Good",
            "White Robes are mystics and healers, devoted to preserving life and balance.",
            110, 90, 10, 8, 20, 18, 12, 12, 14
        };
    }
    else if (race == RED_ROBES) {
        return Character{
            name, race, "Neutral",
            "Red Robes are fierce and passionate, blending magical might with physical prowess.",
            115, 85, 17, 12, 17, 14, 14, 14, 12
        };
    }
    else if (race == HEROES_OF_THE_LANCE) {
        return Character{
            name, race, "Good",
            "Heroes of the Lance embody courage and virtue, champions in the face of darkness.",
            140, 70, 20, 18, 15, 15, 16, 12, 14
        };
    }
    else if (race == ENEMIES_OF_THE_LANCE) {
        return Character{
            name, race, "Evil",
            "Enemies of the Lance wield dark powers and forbidden knowledge to further their aims.",
            120, 75, 22, 10, 18, 10, 16, 14, 16
        };
    }
    // Default character
    return Character{ name, ELVES, "Neutral", "A mysterious being.", 100, 100, 10, 10, 10, 10, 10, 10, 10 };
}

// -----------------------
// Main Game Framework
// -----------------------

int main() {
    // Intro text & game mode selection
    cout << "Welcome to Khas! (In ASCII)\n";
    cout << "Are you new to the world of Dragonlance?\n";
    cout << "Would you like to hear the story of the world of Krynn?\n\n";
    cout << "Select a game mode:\n";
    cout << "1. Versus Mode (vs Computer)\n";
    cout << "2. Storyline Mode\n";
    cout << "3. 2 Player Battle Mode\n";
    cout << "Enter your choice: ";

    int gameMode;
    cin >> gameMode;
    cin.ignore();  // Flush newline

    string player1Name, player2Name;
    int player1CharChoice, player2CharChoice;
    Character player1Character, player2Character;

    // Branch based on game mode
    if (gameMode == 1) { // Versus Mode: Player vs Computer
        cout << "\nEnter your name: ";
        getline(cin, player1Name);
        player2Name = "Computer";

        cout << "\n" << player1Name << ", please choose your character set:\n";
        cout << "1. Elves\n2. Dark Elves\n3. Kinder\n4. Dwarf\n5. Gully Dwarf\n";
        cout << "6. White Robes\n7. Red Robes\n8. Heroes of the Lance\n9. Enemies of the Lance\n";
        cout << "For a detailed breakdown on each character set, enter 0: ";
        cin >> player1CharChoice;
        cin.ignore();
        if (player1CharChoice == 0) {
            cout << "\nDisplaying detailed breakdown of character sets...\n";
            // (Implement detailed breakdown if desired.)
        }
        else {
            cout << "\nYou selected option " << player1CharChoice << " for " << player1Name << ".\n";
        }
        RaceType chosenRace1 = static_cast<RaceType>(player1CharChoice - 1);
        player1Character = createCharacter(player1Name, chosenRace1);

    }
    else if (gameMode == 2) { // Storyline Mode: Single Player Narrative
        cout << "\nEnter your name: ";
        getline(cin, player1Name);

        cout << "\n" << player1Name << ", please choose your character set:\n";
        cout << "1. Elves\n2. Dark Elves\n3. Kinder\n4. Dwarf\n5. Gully Dwarf\n";
        cout << "6. White Robes\n7. Red Robes\n8. Heroes of the Lance\n9. Enemies of the Lance\n";
        cout << "For a detailed breakdown on each character set, enter 0: ";
        cin >> player1CharChoice;
        cin.ignore();
        if (player1CharChoice == 0) {
            cout << "\nDisplaying detailed breakdown of character sets...\n";
        }
        else {
            cout << "\nYou selected option " << player1CharChoice << " for " << player1Name << ".\n";
        }
        RaceType chosenRace1 = static_cast<RaceType>(player1CharChoice - 1);
        player1Character = createCharacter(player1Name, chosenRace1);

    }
    else if (gameMode == 3) { // 2 Player Battle Mode: Two Human Players
        cout << "\nPlayer 1, please enter your name: ";
        getline(cin, player1Name);

        cout << "\n" << player1Name << ", please choose your character set:\n";
        cout << "1. Elves\n2. Dark Elves\n3. Kinder\n4. Dwarf\n5. Gully Dwarf\n";
        cout << "6. White Robes\n7. Red Robes\n8. Heroes of the Lance\n9. Enemies of the Lance\n";
        cout << "For a detailed breakdown on each character set, enter 0: ";
        cin >> player1CharChoice;
        cin.ignore();
        if (player1CharChoice == 0) {
            cout << "\nDisplaying detailed breakdown of character sets for " << player1Name << "...\n";
        }
        else {
            cout << "\nYou selected option " << player1CharChoice << " for " << player1Name << ".\n";
        }
        RaceType chosenRace1 = static_cast<RaceType>(player1CharChoice - 1);
        player1Character = createCharacter(player1Name, chosenRace1);

        cout << "\n" << player1Name << ", when you are finished with your turn, press Enter and pass the computer to Player 2.";
        waitForEnter();
        clearScreen();

        cout << "\nPlayer 2, please enter your name: ";
        getline(cin, player2Name);

        cout << "\n" << player2Name << ", please choose your character set:\n";
        cout << "1. Elves\n2. Dark Elves\n3. Kinder\n4. Dwarf\n5. Gully Dwarf\n";
        cout << "6. White Robes\n7. Red Robes\n8. Heroes of the Lance\n9. Enemies of the Lance\n";
        cout << "For a detailed breakdown on each character set, enter 0: ";
        cin >> player2CharChoice;
        cin.ignore();
        if (player2CharChoice == 0) {
            cout << "\nDisplaying detailed breakdown of character sets for " << player2Name << "...\n";
        }
        else {
            cout << "\nYou selected option " << player2CharChoice << " for " << player2Name << ".\n";
        }
        RaceType chosenRace2 = static_cast<RaceType>(player2CharChoice - 1);
        player2Character = createCharacter(player2Name, chosenRace2);
    }
    else {
        cout << "Invalid game mode selected. Exiting...\n";
        return 1;
    }

    // Display character information
    cout << "\nCharacter info for " << player1Name << ":\n";
    player1Character.displayInfo();
    if (gameMode == 3) {
        cout << "\nCharacter info for " << player2Name << ":\n";
        player2Character.displayInfo();
    }

    // -----------------------
    // Deck Setup and Card Drawing
    // -----------------------

    vector<Card> deck = createDeck();
    shuffleDeck(deck);

    const int handSize = 5;
    vector<Card> player1Hand, player2Hand;

    cout << "\nDrawing 5 cards for " << player1Name << "...\n";
    for (int i = 0; i < handSize; i++) {
        player1Hand.push_back(drawCard(deck));
    }

    cout << "\n" << player1Name << "'s hand:\n";
    for (const auto& card : player1Hand) {
        cout << card.rank << " of " << card.suit << "\n";
    }

    // For 2 Player Battle Mode, hide Player 1's hand before Player 2's turn.
    if (gameMode == 3) {
        cout << "\n" << player1Name << ", when you are finished with your turn, press Enter and pass the computer to " << player2Name << ".";
        waitForEnter();
        clearScreen();

        cout << "\nDrawing 5 cards for " << player2Name << "...\n";
        for (int i = 0; i < handSize; i++) {
            player2Hand.push_back(drawCard(deck));
        }

        cout << "\n" << player2Name << "'s hand:\n";
        for (const auto& card : player2Hand) {
            cout << card.rank << " of " << card.suit << "\n";
        }
    }

    // In Versus Mode, draw the computer's cards but keep them hidden.
    if (gameMode == 1) {
        for (int i = 0; i < handSize; i++) {
            player2Hand.push_back(drawCard(deck));
        }
        cout << "\nThe computer has drawn its cards. (These cards remain hidden.)\n";
    }

    // -----------------------
    // Demonstration of Card Effects on a Character
    // -----------------------

    cout << "\nApplying a magic card and a god card to " << player1Name << "'s character...\n";
    Card magicCard = { "J", "Hearts" };
    player1Character.applyMagicCard(magicCard);

    Card godCard = { "A", "Spades" };
    player1Character.applyGodCard(godCard);

    cout << "\nEnd of demonstration. Game logic continues here...\n";

    return 0;
}
