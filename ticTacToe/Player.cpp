#include "Player.h"

void Player::setName(string value){
	name = value;
}
void Player::addScore(){
	score++;
}
void Player::resetScore(){
	score = 0;
}
string Player::getName(){
	return name;
}
int Player::getScore(){
	return score;
}