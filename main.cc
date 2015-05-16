#include <time.h>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Card{
	public:
	int number;
	string suit;
	Card(int number, string suit): number(number),suit(suit) {}
};

ostream& operator<< (ostream &out, Card &cCard){
       	out << cCard.number << " " << cCard.suit << " ";
	return out;
}

vector<Card*> deck;
int recorder[104];
int v1, v2, v3, s1, s2, s3; 		//dealer's hand
int dealstage = 1;
int bet1 = 0;
int bet2 = 0;
int bet3 = 0;
int bet;
int cash = 500;

int getRandom(){
	int v1;
	while(true){
                v1 = rand() % 104;    
             	if(recorder[v1] == 0){
                     	recorder[v1] = 1;
                        break;
                }
        }
	return v1;
}

string Bester(Card* c1, Card* c2){
	int num8 = 0;
	int suit8 = 0;
	if(c1->number == c2->number){
		num8 = 1;
	}
	if(c1->suit == c2->suit){
		suit8 = 1;
	}
	if(num8 == 1 && suit8 == 1){
		return "C";
	}
	if(num8 == 0 && suit8 == 1){
		return "S";
	}
	if(num8 == 1 && suit8 == 0){
		return "N";
	}
	return "nothing";
}

string Best(){
	string states[10] = {"CCC","CCN","CCS","CNN","CNS","CSS","NNN","NNS","NSS","SSS"};
	int states1[10];
	for(int i = 0; i < 10; i++){
		states1[i] = 0;
	}
	string a;
	string b;
	string c;
	int C;
	int N;
	int S;
	C = 0;
	N = 0;
	S = 0;
	a = Bester(deck[v1],deck[s1]);
	b = Bester(deck[v2],deck[s2]);
	c = Bester(deck[v3],deck[s3]);
	if(a == "C"){ C++; }
	if(a == "N"){ N++; }
	if(a == "S"){ S++; }
	if(b == "C"){ C++; }
        if(b == "N"){ N++; }
        if(b == "S"){ S++; }
	if(c == "C"){ C++; }
        if(c == "N"){ N++; }
        if(c == "S"){ S++; }
	if(C+N+S == 3){
		if(C == 3){ states1[0]++; }
		if(C == 2 && N == 1){ states1[1]++; }
		if(C == 2 && S == 1){ states1[2]++; }
		if(C == 1 && N == 2){ states1[3]++; }
		if(C == 1 && N == 1 && S == 1){ states1[4]++; }
		if(C == 1 && S == 2){states1[5]++; }
		if(N == 3){ states1[6]++; }
		if(N == 2 && S == 1){ states1[7]++; }
		if(N == 1 && S == 2){ states1[8]++; }
		if(S == 3){ states1[9]++; }
	}

	C = 0;
        N = 0;
        S = 0;
       	a = Bester(deck[v1],deck[s1]);
       	b = Bester(deck[v2],deck[s3]);
        c = Bester(deck[v3],deck[s2]);
        if(a == "C"){ C++; }
        if(a == "N"){ N++; }
        if(a == "S"){ S++; }
        if(b == "C"){ C++; }
        if(b == "N"){ N++; }
        if(b == "S"){ S++; }
        if(c == "C"){ C++; }
        if(c == "N"){ N++; }
        if(c == "S"){ S++; }
        if(C+N+S == 3){
                if(C == 3){ states1[0]++; }
                if(C == 2 && N == 1){ states1[1]++; }
                if(C == 2 && S == 1){ states1[2]++; }
                if(C == 1 && N == 2){ states1[3]++; }
                if(C == 1 && N == 1 && S == 1){ states1[4]++; }
                if(C == 1 && S == 2){states1[5]++; }
                if(N == 3){ states1[6]++; }
                if(N == 2 && S == 1){ states1[7]++; }
                if(N == 1 && S == 2){ states1[8]++; }
                if(S == 3){ states1[9]++; }
        }

	C = 0;
        N = 0;
        S = 0;
        a = Bester(deck[v1],deck[s2]);
        b = Bester(deck[v2],deck[s1]);
        c = Bester(deck[v3],deck[s3]);
        if(a == "C"){ C++; }
        if(a == "N"){ N++; }
        if(a == "S"){ S++; }
        if(b == "C"){ C++; }
        if(b == "N"){ N++; }
        if(b == "S"){ S++; }
        if(c == "C"){ C++; }
        if(c == "N"){ N++; }
        if(c == "S"){ S++; }
        if(C+N+S == 3){
                if(C == 3){ states1[0]++; }
                if(C == 2 && N == 1){ states1[1]++; }
                if(C == 2 && S == 1){ states1[2]++; }
                if(C == 1 && N == 2){ states1[3]++; }
                if(C == 1 && N == 1 && S == 1){ states1[4]++; }
                if(C == 1 && S == 2){states1[5]++; }
                if(N == 3){ states1[6]++; }
                if(N == 2 && S == 1){ states1[7]++; }
                if(N == 1 && S == 2){ states1[8]++; }
                if(S == 3){ states1[9]++; }
        }

	C = 0;
        N = 0;
        S = 0;
        a = Bester(deck[v1],deck[s2]);
        b = Bester(deck[v2],deck[s3]);
        c = Bester(deck[v3],deck[s1]);
        if(a == "C"){ C++; }
        if(a == "N"){ N++; }
        if(a == "S"){ S++; }
        if(b == "C"){ C++; }
        if(b == "N"){ N++; }
        if(b == "S"){ S++; }
        if(c == "C"){ C++; }
        if(c == "N"){ N++; }
        if(c == "S"){ S++; }
        if(C+N+S == 3){
                if(C == 3){ states1[0]++; }
                if(C == 2 && N == 1){ states1[1]++; }
                if(C == 2 && S == 1){ states1[2]++; }
                if(C == 1 && N == 2){ states1[3]++; }
                if(C == 1 && N == 1 && S == 1){ states1[4]++; }
                if(C == 1 && S == 2){states1[5]++; }
                if(N == 3){ states1[6]++; }
                if(N == 2 && S == 1){ states1[7]++; }
                if(N == 1 && S == 2){ states1[8]++; }
                if(S == 3){ states1[9]++; }
        }
	
	C = 0;
        N = 0;
        S = 0;
        a = Bester(deck[v1],deck[s3]);
        b = Bester(deck[v2],deck[s1]);
        c = Bester(deck[v3],deck[s2]);
        if(a == "C"){ C++; }
        if(a == "N"){ N++; }
        if(a == "S"){ S++; }
        if(b == "C"){ C++; }
        if(b == "N"){ N++; }
        if(b == "S"){ S++; }
        if(c == "C"){ C++; }
        if(c == "N"){ N++; }
        if(c == "S"){ S++; }
        if(C+N+S == 3){
                if(C == 3){ states1[0]++; }
                if(C == 2 && N == 1){ states1[1]++; }
                if(C == 2 && S == 1){ states1[2]++; }
                if(C == 1 && N == 2){ states1[3]++; }
                if(C == 1 && N == 1 && S == 1){ states1[4]++; }
                if(C == 1 && S == 2){states1[5]++; }
                if(N == 3){ states1[6]++; }
                if(N == 2 && S == 1){ states1[7]++; }
                if(N == 1 && S == 2){ states1[8]++; }
                if(S == 3){ states1[9]++; }
        }

	C = 0;
        N = 0;
        S = 0;
        a = Bester(deck[v1],deck[s3]);
        b = Bester(deck[v2],deck[s2]);
        c = Bester(deck[v3],deck[s1]);
        if(a == "C"){ C++; }
        if(a == "N"){ N++; }
        if(a == "S"){ S++; }
        if(b == "C"){ C++; }
        if(b == "N"){ N++; }
        if(b == "S"){ S++; }
        if(c == "C"){ C++; }
        if(c == "N"){ N++; }
        if(c == "S"){ S++; }
        if(C+N+S == 3){
                if(C == 3){ states1[0]++; }
                if(C == 2 && N == 1){ states1[1]++; }
                if(C == 2 && S == 1){ states1[2]++; }
                if(C == 1 && N == 2){ states1[3]++; }
                if(C == 1 && N == 1 && S == 1){ states1[4]++; }
                if(C == 1 && S == 2){states1[5]++; }
                if(N == 3){ states1[6]++; }
                if(N == 2 && S == 1){ states1[7]++; }
                if(N == 1 && S == 2){ states1[8]++; }
                if(S == 3){ states1[9]++; }
        }
	for(int y = 0; y < 10; y++){
		if(states1[y] != 0){
			return states[y];
		}
	}
	return "nothing";
}	
	

int main(){
	srand (time(NULL));
	for(int j = 0; j < 104; j++){
		recorder[j] = 0;
	}
	string suits[4] = {"HEART","DIAMOND","CLUB","SPAID"};
	int Number = 1;
	int Suit = 0;
	for(int i = 0; i < 104; i++){
		deck.push_back(new Card(Number, suits[Suit]));
		Number++;
		Suit++;
		if(Number == 14){ Number = 1; }
		if(Suit == 4){ Suit = 0; }
	}
	cout << "Are you ready to play some Sweet Matches?" << endl;
	cout << "Choose your command: deal or done?" << endl;
	cout << "Starting with $" << cash << " Yes GUY ;) " << endl;
	string s;
	while(cin >> s){
		if(s == "deal" && dealstage){
			v1 = getRandom();
			v2 = getRandom();
			v3 = getRandom();
			cout << *deck[v1] << *deck[v2] << *deck[v3] << endl;
			s1 = getRandom();
			cout << *deck[s1] << endl << endl;
			cout << "Enter fold or play" << endl;
			dealstage = 0;
			bet1 = 1;
		}
		else if(s == "play" && bet1){
			cout << "Enter initial bet: " << endl;
			int beti;
			while(true){
				cin >> beti;
				if(cin.fail()){
					cin.clear();
					cin.ignore();
				}
				else{
					bet = beti;
					break;
				}
			}
			s2 = getRandom();
			cout << *deck[v1] << *deck[v2] << *deck[v3] << endl;
			cout << *deck[s1] << *deck[s2] << endl << endl;
			bet1 = 0;
			bet2 = 1;
			cout << "Enter fold or play: play with automatic bet of: " << 2*bet << endl;
		}
		else if(s == "play" && bet2){
			cout << "You have agreed to bet " << 2*bet << " Total on the line is " << 3*bet << endl;
			s3 = getRandom();
			cout << *deck[v1] << *deck[v2] << *deck[v3] << endl;
                        cout << *deck[s1] << *deck[s2] << *deck[s3] << endl << endl;
			string hold = Best();
			cout << "Best combo is: " << hold << endl;
			if(hold == "nothing"){
				cout << "You lost a total of: $" << 3*bet << endl;
				cash = cash - 3*bet;
				cout << "Your bank has: $" << cash << endl;
			}
			else{
				cout << "WINNER WINNER WINNER" << " You made an extra: " << 3*bet << endl;
				cash = cash + 3*bet;
				cout << "Your bank has: $" << cash << endl;
			}
			dealstage = 1;
			bet1 = 0;
			bet2 = 0;
			if(cash <= 0){
				cout << "You are out of money, press deal to restart with $500" << endl;
				cash = 500;
			}
			cout << "Type deal to play again!" << endl;	
		}				
		else if(s == "fold"){
			for(int i = 0; i < 104; i++){
				recorder[i] = 0;
			}
			if(bet2 == 1){
				cout << "You lost: $" << bet << endl;
				cash = cash - bet;
				cout << "Your net worth is now: $" << cash << endl;
			}
			if(bet1 == 1){
				cout << "You lost a $3 playing fee" << endl;
				cash = cash - 3;
				cout << "Your net worth is now: $" << cash << endl;
			}
			dealstage = 1;
			bet = 0;
			bet1 = 0;
			bet2 = 0;
			bet3 = 0;
			if(cash <= 0){
				cout << "You are out of money, press deal to restart with $500" << endl;
				cash = 500;
			}
			cout << "Choose your command: deal or done?" << endl;
		}
		else if(s == "done"){
			break;
		}
	}
	for(int i = 0; i < 104; i++){
		delete deck[i];
	}
	return 0;
}
