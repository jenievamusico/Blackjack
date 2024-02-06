#include <iostream>
#include <iomanip>
using namespace std;

// abbreviation constants
const string P = "PLAYER";
const string D = "DEALER";

// basic constants
const int BLACKJACK = 21;
const int WIN = 1;
const int LOSS = -1;
const int DRAW = 0;
const int CONTINUE = 5;
const int SUITS = 4;
const int CARDS = 13;

// result constants
const int BLACKJACK_WIN = 30;
const int BLACKJACK_LOSS = 31;
const int BLACKJACK_DRAW = 32;
const int BUST_WIN = 33;
const int BUST_LOSS = 34;
const int BUST_DRAW = 35;


// Function Prototypes
string chooseSuit();
int getCard();
void displayCard(int card);
int cardScore(int card, int score);
int deal(bool isPlayer, bool isShown, int score);
int results(int playerScore, int dealerScore);
char hitOrStand();
int playHand();


int main()
{
    srand(time(nullptr));

    // initalize outcomes
    int wins = 0;
    int losses = 0;
    int draws = 0;

    // title
    cout << endl << "BLACKJACK" << endl;
    cout << "---------" << endl << endl;

    // initialize play character
    char play;

    cout << "Do you want to play Blackjack? (y to play): ";
    cin >> play;
    cout << endl;

    if(play == 'n'){
        // print out final game scores
        cout << "Thanks for playing, your record was:" << endl;
        cout << "Wins: " << wins << endl;
        cout << "Losses: " << losses << endl;
        cout << "Draws: " << draws << endl << endl;
    } 

    while(play != 'y' && play != 'n'){
        cout << "Please enter y to play or n to quit: ";
        cin >> play;

        if(play == 'n'){
            // print out final game scores
            cout << endl;
            cout << "Thanks for playing, your record was:" << endl;
            cout << "Wins: " << wins << endl;
            cout << "Losses: " << losses << endl;
            cout << "Draws: " << draws << endl << endl;
        } 
    }

    // keep playing as long as they input y for play
    while(play == 'y'){

        int outcome = playHand();

        // add to wins if the player wins
        if(outcome == WIN){
            wins += 1;
        }
        // add to losses if the player loses
        else if(outcome == LOSS){
            losses += 1;
        }
        // add to draws if they draw
        else if(outcome == DRAW){
            draws += 1;
        }

        cout << endl << endl;
        cout << "Do you want to play another hand? (y to play): ";
        cin >> play;

        if(play == 'n'){
            // print out final game scores
            cout << endl;
            cout << "Thanks for playing, your record was:" << endl;
            cout << "Wins: " << wins << endl;
            cout << "Losses: " << losses << endl;
            cout << "Draws: " << draws << endl << endl;
        }

        while(play != 'y' && play != 'n'){
            cout << endl << "Please enter y to play or n to quit: ";
            cin >> play;
            cout << endl;
            if(play == 'n'){
                // print out final game scores
                cout << "Thanks for playing, your record was:" << endl;
                cout << "Wins: " << wins << endl;
                cout << "Losses: " << losses << endl;
                cout << "Draws: " << draws << endl << endl;
            } 
        }

        cout << endl;
    }
    
}


string chooseSuit()
{
    // picl a random number between 0 and 3
    int suitChoice = rand() % SUITS;

    // if random number is 1 its hearts
    if(suitChoice == 1){
        string suit = "hearts";
        return suit;
    // if random number is 2 its clubs
    }else if(suitChoice == 2){
        string suit = "clubs";
        return suit;
    // if random number is 3 its spade
    }else if(suitChoice == 3){
        string suit = "spades";
        return suit;
    // if random number is 0 its diamonds
    }else{
        string suit = "diamonds";
        return suit;
    }
}


int getCard()
{
    // pick a random number between 0 and 12
    int card = rand() % CARDS;
    return card;
}


void displayCard(int card)
{
    // if random number is 1 say ace of random suit
    if(card == 1){
        string card = "ace";
        cout << card << " of " << chooseSuit() << endl;
    }
    // if random number is 2 say two of random suit
    if(card == 2){
        string card = "two";
        cout << card << " of " << chooseSuit() << endl;
    }
    // if random number is 3 say three of random suit
    if(card == 3){
        string card = "three";
        cout << card << " of " << chooseSuit() << endl;
    }
    // if random number is 4 say four of random suit
    if(card == 4){
        string card = "four";
        cout << card << " of " << chooseSuit() << endl;
    }
    // if random number is 5 say five of random suit
    if(card == 5){
        string card = "five";
        cout << card << " of " << chooseSuit() << endl;
    }
    // if random number is 6 say six of random suit
    if(card == 6){
        string card = "six";
        cout << card << " of " << chooseSuit() << endl;
    }
    // if random number is 7 say seven of random suit
    if(card == 7){
        string card = "seven";
        cout << card << " of " << chooseSuit() << endl;
    }
    // if random number is 8 say eight of random suit
    if(card == 8){
        string card = "eight";
        cout << card << " of " << chooseSuit() << endl;
    }
    // if random number is 9 say nine of random suit
    if(card == 9){
        string card = "nine";
        cout << card << " of " << chooseSuit() << endl;
    }
    // if random number is 10 say ten of random suit
    if(card == 10){
        string card = "ten";
        cout << card << " of " << chooseSuit() << endl;
    }
    // if random number is 11 say jack of random suit
    if(card == 11){
        string card = "jack";
        cout << card << " of " << chooseSuit() << endl;
    }
    // if random number is 12 say queen of random suit
    if(card == 12){
        string card = "queen";
        cout << card << " of " << chooseSuit() << endl;
    }
    // if random number is 0 say king of random suit
    if(card == 0){
        string card = "king";
        cout << card << " of " << chooseSuit() << endl;
    }
}


int cardScore(int card, int score)
{
    // if the card is an ace add 11 to the score
    if(card == 1){
        score += (card + 10);
        return score;
    }
    // if the card is a two add 2 to the score
    if(card == 2){
        score += card;
        return score;
    }
    // if the card is a three add 3 to the score
    if(card == 3){
        score += 3;
        return score;
    }
    // if the card is a four add 4 to the score
    if(card == 4){
        score += card;
        return score;
    }
    // if the card is a five add 5 to the score
    if(card == 5){
        score += card;
        return score;
    }
    // if the card is a six add 6 to the score
    if(card == 6){
        score += card;
        return score;
    }
    // if the card is a seven add 7 to the score
    if(card == 7){
        score += card;
        return score;
    }
    // if the card is a eight add 8 to the score
    if(card == 8){
        score += card;
        return score;
    }
    // if the card is a nine add 9 to the score
    if(card == 9){
        score += card;
        return score;
    }
    // if the card is a ten add 10 to the score
    if(card == 10){
        score += card;
        return score;
    }
    // if the card is a jack add 10 to the score
    if(card == 11){
        score += (card - 1);
        return score;
    }
    // if the card is a queen add 10 to the score
    if(card == 12){
        score += (card - 2);
        return score;
    }
    // if the card is a king add 10 to the score
    if(card == 0){
        score += (card + 10);
        return score;
    }
    
    return score;
}


int deal(bool isPlayer, bool isShown, int score)
{
    // if its the player's turn
    if(isPlayer){
        // get new player card
        int playerCard = getCard();
        cout << P << " was dealt ";

        // if the card is shown
        if(isShown){
            // type out players new card
            displayCard(playerCard);
        }

        // return the score of the card
        int playerScore = cardScore(playerCard, score);
        
        // let player choose if ace score is 11 or 1
        int aceScore = 11;
        if(playerScore == aceScore){
            cout << "Would you like this ace to add 1 or 11 to your score? ";
            cin >> aceScore;
            return aceScore;
        }else{
            return playerScore;
        }
    }
    // if its the dealer's turn
    else{
        // get new dealer card
        int dealerCard = getCard();
        cout << D << " was dealt ";

        // if the card is shown
        if(isShown){
            // type out players new card
            displayCard(dealerCard);
        }
        // if the card is hidden
        else{
            cout << "a hidden card";
        }
        // return the score of the card
        int dealerScore = cardScore(dealerCard, score);
        return dealerScore;
    }
}


int results(int playerScore, int dealerScore)
{
    // if the player wins
    if(playerScore == BLACKJACK && dealerScore < BLACKJACK){
        return BLACKJACK_WIN;
    }
    // if the dealer wins 
    if(playerScore < BLACKJACK && dealerScore == BLACKJACK){
        return BLACKJACK_LOSS;
    }
    // if the player and dealer tie (both get 21)
    if(playerScore == BLACKJACK && dealerScore == BLACKJACK){
        return BLACKJACK_DRAW;
    }
    // if the player busts
    if(playerScore > 21){
        return BUST_LOSS;
    }
    // if the dealer busts
    else if(dealerScore > 21){
        return BUST_WIN;
    }
    // if both the player and the dealer bust
    else if(playerScore > 21 && dealerScore > 21){
        return BUST_DRAW;
    }
    // if no one gets 21 or above then keep playing
    else{
        return CONTINUE;
    }
    return 0;
}


char hitOrStand(){
    char hitOrStand;

    // ask if they want to hit or stand
    cout << "Enter h to hit or s to stand: ";
    cin >> hitOrStand;
    cout << endl;

    // make sure the input is s, S, h, or H
    while(hitOrStand != 's' && hitOrStand != 'S' && hitOrStand != 'h' && hitOrStand != 'H'){
        cout << "Please enter \'s\', \'S\', \'h\', or \'H\' : ";
        cin >> hitOrStand;
    }

    return hitOrStand;
}


int playHand()
{
    // new game beginning score
    int playerScore = 0;
    int dealerScore = 0;

    // first deal
    playerScore += deal(1, 1, 0);
    int dealerScoreHidden = dealerScore += deal(0, 1, 0);

    // second deal
    playerScore += deal(1, 1, 0);
    dealerScore += deal(0, 0, 0);

    cout << endl << endl;

    // player's score after 2nd deal
    cout << P << " score = " << playerScore;

    cout << endl;

    // dealer's score after first deal (second deal is hidden)
    cout << D << " score = " << dealerScoreHidden;

    cout << endl << endl;

    // AFTER FIRST TWO DEALS

    // if the player get 21 after the first two deals, return a win
    if(results(playerScore, dealerScore) == BLACKJACK_WIN){
        cout << D << " reveals its second card" << endl;
        cout << P << " score: " << playerScore << endl;
        cout << D << " score: " << dealerScore << endl << endl;
        cout << "Blackjack! You win!";
        return WIN;
    }
    // if the dealer gets 21 after the first two deals, return a loss
    else if(results(playerScore, dealerScore) == BLACKJACK_LOSS){
        cout << D << " reveals card to show 21" << endl;
        cout << D << " score: " << dealerScore << endl << endl;
        cout << D << " wins, you lose.";
        return LOSS;
    }
    // if both the player and dealer get 21 after the first two deals, return a draw
    else if(results(playerScore, dealerScore) == BLACKJACK_DRAW){
        cout << D << " reveals card to show that they also got 21!" << endl;
        cout << P << " score: " << playerScore << endl;
        cout << D << " score: " << dealerScore << endl << endl;
        cout << "Draw";
        return DRAW;
    }
    // if the dealer busts after the first two deals, the player wins, return a win
    else if(results(playerScore, dealerScore) == BUST_WIN){
        cout << D << " reveals its second card" << endl;
        cout << P << " score: " << playerScore << endl;
        cout << D << " score: " << dealerScore << endl << endl;
        cout << "Dealer\'s bust. You win!";
        return WIN;
    }
    // if  the player busts after the first two deals, return a loss
    else if(results(playerScore, dealerScore) == BUST_LOSS){
        cout << D << " reveals its second card" << endl;
        cout << P << " score: " << playerScore << endl;
        cout << D << " score: " << dealerScore << endl << endl;
        cout << "Bust! You lose.";
        return LOSS;
    }
    // if both the player and dealer bust after the first two deals, return a draw
    else if(results(playerScore, dealerScore) == BUST_DRAW){
        cout << D << " reveals its second card" << endl;
        cout << P << " score: " << playerScore << endl;
        cout << D << " score: " << dealerScore << endl << endl;
        cout << "Both you and the dealer are bust, draw";
        return DRAW;
    }
    // if no one got 21 or busted after the first two deals, continue
    else if(results(playerScore, dealerScore) == CONTINUE){
        char decision = hitOrStand();

        //while the player chooses to hit
        while(decision == 'h' || decision == 'H'){
            // deal player a new card
            playerScore += deal(1, 1, 0);
            cout << endl;

            // AFTER THIRD DEAL

            // if the player is still under 21 - deal another card to player and then ask if they want to hit or stand again
            if(results(playerScore, dealerScore) == CONTINUE){
                cout << P << " score: " << playerScore << endl;
                cout << D << " score: " << dealerScoreHidden << endl << endl;
                decision = hitOrStand();
            }
            // if the player busts - player loses
            if(results(playerScore, dealerScore) == BUST_LOSS){                
                cout << D << " reveals its second card" << endl;
                cout << P << " score: " << playerScore << endl;
                cout << D << " score: " << dealerScore << endl << endl;
                cout << "Bust! You lose.";
                return LOSS;
                break;
            }
            // if the player gets 21 - player wins
            if(results(playerScore, dealerScore) == BLACKJACK_WIN){
                cout << D << " reveals its second card" << endl;
                cout << P << " score: " << playerScore << endl;
                cout << D << " score: " << dealerScore << endl << endl;
                cout << "Blackjack! You win!";
                return WIN;
                break;
            }
        }

        //if the player chooses to stand
        if(decision == 's' || decision == 'S'){
            cout << D << " reveals its second card" << endl;
            cout << P << " score: " << playerScore << endl;
            cout << D << " score: " << dealerScore << endl << endl;

            while(dealerScore < 17){
                // deal dealer a new card
                dealerScore += deal(0, 1, 0);
                cout << endl;

                // AFTER THIRD DEAL

                // if the dealer is still under 21 - deal another card to dealer
                if(results(playerScore, dealerScore) == CONTINUE){
                    cout << P << " score: " << playerScore << endl;
                    cout << D << " score: " << dealerScore << endl << endl;
                }
                // if the dealer busts - player wins
                if(results(playerScore, dealerScore) == BUST_WIN){                
                    cout << D << " reveals its second card" << endl;
                    cout << P << " score: " << playerScore << endl;
                    cout << D << " score: " << dealerScore << endl << endl;
                    cout << "Dealer\'s bust. You win!";
                    return WIN;
                    break;
                }
                // if the dealer gets 21 - player loses
                if(results(playerScore, dealerScore) == BLACKJACK_LOSS){
                    cout << D << " reveals card to show 21" << endl;
                    cout << D << " score: " << dealerScore << endl << endl;
                    cout << D << " wins, you lose.";
                    return LOSS;
                    break;
                }
            }
            // if the player stands and the dealer has to stand, but the player is higher than the dealer - player wins
            if(dealerScore >= 17 && playerScore > dealerScore){
                cout << "Your score is higher, you win!";
                return WIN;

            }
            // if the player stands and the dealer has to stand, but the dealer is higher than the player - dealer wins
            if(dealerScore >= 17 && playerScore < dealerScore){
                cout << "Dealer\'s score is higher, you lose.";
                return LOSS;
            }
            // if the player stands and the dealer has to stand, but the dealer is the same as the player - draw
            if(dealerScore >= 17 && playerScore == dealerScore){
                cout << "Your scores are the same, draw";
                return DRAW;
            }

            
        }

    }

    return 0;

}