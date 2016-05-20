#include "Map.h"

Map::Map(){
	for (int x = 0; x < 3; x++){
		for (int y = 0; y < 3; y++){
			grid[x][y] = 0;
		}
	}
	pOneTurn = true;
	pOne.resetScore();
	pTwo.resetScore();
}
void Map::setNameOne(string value){
	pOne.setName(value);
}
void Map::setNameTwo(string value){
	pTwo.setName(value);
}
void Map::chooseTile(int x, int y){
	if (pOneTurn == true){
		grid[x][y] = 1;
		pOneTurn = false;
	} else {
		grid[x][y] = 2;
		pOneTurn = true;
	}
}
void Map::printMap(){
			if (grid[0][2] == 0)
				cout << " |";
			if (grid[0][2] == 1)
				cout << "X|";
			if (grid[0][2] == 2)
				cout << "O|";

			if (grid[1][2] == 0)
				cout << " ";
			if (grid[1][2] == 1)
				cout << "X";
			if (grid[1][2] == 2)
				cout << "O";

			if (grid[2][2] == 0)
				cout << "| ";
			if (grid[2][2] == 1)
				cout << "|X";
			if (grid[2][2] == 2){
				cout << "|O";
			}
			cout << endl << "------" << endl;

			if (grid[0][1] == 0)
				cout << " |";
			if (grid[0][1] == 1)
				cout << "X|";
			if (grid[0][1] == 2)
				cout << "O|";

			if (grid[1][1] == 0)
				cout << " ";
			if (grid[1][1] == 1)
				cout << "X";
			if (grid[1][1] == 2)
				cout << "O";

			if (grid[2][1] == 0)
				cout << "| ";
			if (grid[2][1] == 1)
				cout << "|X";
			if (grid[2][1] == 2){
				cout << "|O";
			}
			cout << endl << "------" << endl;

			if (grid[0][0] == 0)
				cout << " |";
			if (grid[0][0] == 1)
				cout << "X|";
			if (grid[0][0] == 2)
				cout << "O|";

			if (grid[1][0] == 0)
				cout << " ";
			if (grid[1][0] == 1)
				cout << "X";
			if (grid[1][0] == 2)
				cout << "O";

			if (grid[2][0] == 0)
				cout << "| ";
			if (grid[2][0] == 1)
				cout << "|X";
			if (grid[2][0] == 2)
				cout << "|O";
			cout << endl << endl;
	}
void Map::resetMap(){
	for (int x = 0; x < 3; x++){
		for (int y = 0; y < 3; y++){
			grid[x][y] = 0;
		}
	}
}
bool Map::win(int player){
	for (int i = 0; i < 3; i++){
		if (isSame(grid[i][0], grid[i][1], grid[i][2], player) == true
			|| isSame(grid[0][i], grid[1][i], grid[2][i], player) == true
			|| isSame(grid[0][0], grid[1][1], grid[2][2], player) == true
			|| isSame(grid[2][0], grid[1][1], grid[0][2], player) == true){
			return true;
		}
	}return false;
}
bool Map::isSame(int p1, int p2, int p3, int mark){
	return (p1 == mark) && (p2 == mark) && (p3 == mark);
}
void Map::run(){
	string name[2];
	char option = 'p';
	do{
		pOne.resetScore();
		pTwo.resetScore();
		do{
			cout << "Please Enter player1(X's) name: ";
			cin >> name[0];
			if (name[0].length() < 3){
				cout << "name must be at least 3 letters long..." << endl;
			}
		} while (name[0].length() < 3);
		pOne.setName(name[0]);
		do{
			cout << "Please Enter player2(O's) name: ";
			cin >> name[1];
			if (name[1].length() < 3){
				cout << "name must be at least 3 letters long..." << endl;
			}
		} while (name[1].length() < 3);
		pTwo.setName(name[1]);
		do{
			resetMap();
			printMap();
			pOneTurn = true;
			int x, y = 0;
			cout << "TIP: coordinate 1 1 is bottom left corner, 3 3 is top right." << endl;
			do{
				do{
					cout << pOne.getName() << "(X's) enter a coordinate in this form \"2(space)3\": ";
					cin >> x >> y;
					if (x > 3 || y > 3 || x < 0 || y < 0 || grid[x - 1][y - 1] == 1 || grid[x - 1][y - 1] == 2){
						cout << "ERROR: coordinate uses invalid numbers. Select numbers 1-3" << endl;
					}
				} while (x > 3 || y > 3 || x < 0 || y < 0 || grid[x - 1][y - 1] == 1 || grid[x - 1][y - 1] == 2);
				chooseTile(x - 1, y - 1);
				system("cls");
				printMap();
				if (win(1) == true){
					cout << pOne.getName() << " wins!" << endl;
					pOne.addScore();
					break;
				}
				if (draw() == true){
					cout << "Draw!" << endl;
					break;
				}
				do{
					cout << pTwo.getName() << "(O's) enter a coordinate in this form \"2(space)3\": ";
					cin >> x >> y;
					if (x > 3 || y > 3 || x < 0 || y < 0 || grid[x - 1][y - 1] == 1 || grid[x - 1][y - 1] == 2){
						cout << "ERROR: coordinate uses invalid numbers. Select numbers 1-3" << endl;
					}
				} while (x > 3 || y > 3 || x < 0 || y < 0 || grid[x - 1][y - 1] == 1 || grid[x - 1][y - 1] == 2);
				chooseTile(x - 1, y - 1);
				system("cls");
				printMap();
				if (win(2) == true){
					cout << pTwo.getName() << " wins!" << endl;
					pTwo.addScore();
					break;
				}
				if (draw() == true){
					cout << "Draw!" << endl;
					break;
				}

			} while (win(1) == false && win(2) == false);
			cout << "Score:    " << pOne.getName() << ": " << pOne.getScore() << endl;
			cout << "          " << pTwo.getName() << ": " << pTwo.getScore() << endl;
			cout << "Enter p to keep score and play again." << endl;
			cout << "Enter r to reset score and players and play again." << endl;
			cout << "Enter q to quit game and exit." << endl;
			cin >> option;
			system("cls");
		} while (option == 'p');
	} while (option == 'r');
}

bool Map::draw(){
	int count = 0;
	for (int x = 0; x < 3; x++){
		for (int y = 0; y < 3; y++){
			if (grid[x][y] == 1 || grid[x][y] == 2){
				count++;
			}
		}
	}
	if (count == 9)
		return true;
	else
		return false;
}
