#include "AI.hpp"

AI::AI(std::list<Entity *> &entList) : entities_(entList){
}

AI::~AI(){

}

std::string AI::makeString() {
	std::string line;

	static irr::u32 number_of_line = 0;
	static irr::u32 number_of_cycle = 0;
	irr::s32 i = 0;
	for (std::list<Entity *>::const_iterator it = entities_.begin(); it != entities_.end(); it++) {
		line.clear();
		std::string tmp;
		irr::core::vector3df *v3df = new irr::core::vector3df((*it)->GetPos());
		irr::f32 f = v3df->X;
		tmp = std::to_string(f);
		line = line + tmp;
		line = line + "|";
		f = v3df->Z;
		tmp = std::to_string(f);
		line = line + tmp;
		line = line + "|";
		if ((*it)->GetAIState() == 0)
			line = line + "PLAYER";
		else if ((*it)->GetAIState() == 1)
			line = line + "AI";
		else if ((*it)->GetAIState() == 2)
			line = line + "WALL";
		else
			line = line + "OBJECT";
		number_of_line++;
		i++;
		parsedList_.push_back(line);
	}
	number_of_cycle++;
	return (line);
}

void AI::getActions(NonPlayerCharacter &callChar){

	if (callChar.GetState() == Character::DYING)
		return;
	this->makeString();
	this->makeStringCaller(callChar);
	if (callChar.GetRefresh() == 5) {
		callChar.SetOrder(this->setAction(callChar));
		callChar.SetRefresh(0);
	}
	else
		callChar.SetRefresh(callChar.GetRefresh() + 1);
	while (parsedList_.size() > 0)
		parsedList_.pop_front();
	switch (callChar.GetOrder()) {
		case (0):
			callChar.MoveRight();
			break;
		case (1):
			callChar.MoveLeft();
			break;
		case (2):
			callChar.MoveUp();
			break;
		case (3):
			callChar.MoveDown();
			break;
		case (4):
			callChar.MoveRightUp();
			break;
		case (5):
			callChar.MoveLeftDown();
			break;
		case (6):
			callChar.MoveRightDown();
			break;
		case (7):
			callChar.MoveLeftUp();
			break;
		case (8):
			callChar.Fire();
			break;
	}
}

void AI::makeStringCaller(NonPlayerCharacter& callChar) {
	std::string tmp;
	std::string line;

	irr::core::vector3df *v3df = new irr::core::vector3df((callChar).GetPos());
	irr::f32 f = v3df->X;
	tmp = std::to_string(f);
	line = line + tmp + "|";

	f = v3df->Z;
	tmp = std::to_string(f);
	line = line + tmp;
	parsedCaller_ = line;
}

void 	AI::extractPlayer() {
	irr::u32 i;

	i = 0;
	while (0 < parsedList_.size()) {
		if (parsedList_.front().find("PLAYER") != -1)
			playerList_.push_back(parsedList_.front());
		parsedList_.pop_front();
		i++;
	}

}

irr::s32 AI::setAction(NonPlayerCharacter& CallChar) {
	irr::f32 PPosX;
	irr::f32 PPosY;
	irr::f32 CPosX;
	irr::f32 CPosY;
	std::size_t cz;
	std::string playerstring;

	//extract de Caller X et Y
	cz = 0;
	std::istringstream iss(parsedCaller_);
	std::string token;
	std::getline(iss, token, '|');
	CPosX = std::round(std::stof(token, &cz));
	std::getline(iss, token, '|');
	cz++;
	CPosY = std::round(std::stof(token, &cz));

	//extract de Player X et Y
	this->extractPlayer();
	playerstring = this->extractNearestPlayer(CPosX, CPosY);
	cz = 0;
	std::istringstream iss2(playerstring);
	std::getline(iss2, token, '|'); //fefzeffze
	PPosX = std::round(std::stof(token, &cz));
	std::getline(iss2, token, '|');
	cz++;
	PPosY = std::round(std::stof(token, &cz));
	if ((PPosX - CPosX <= CallChar.GetAggroRange() && PPosX - CPosX >= (-1 * CallChar.GetAggroRange()))&& (PPosY - CPosY <= CallChar.GetAggroRange() && PPosY - CPosY >= (-1 * CallChar.GetAggroRange()))) {
		if ((PPosX <= (CPosX + 75) && PPosX >= (CPosX - 75)) && (PPosY <= (CPosY + 75) && PPosY >= (CPosY - 75))) {
			return (8);
		}
		else if (PPosX > CPosX && (PPosY <= (CPosY + 20) && PPosY >= (CPosY - 20))) {
			return (0);
		}
		else if (PPosX < CPosX && (PPosY <= (CPosY + 20) && PPosY >= (CPosY - 20))) {
			return (1);
		}
		else if (PPosY > CPosY && (PPosX <= (CPosX + 20) && PPosX>= (CPosX - 20))) {
			return (2);
		}
		else if (PPosY < CPosY && (PPosX <= (CPosX + 20) && PPosX>= (CPosX - 20))) {
			return (3);
		}
		else if (PPosX > CPosX && PPosY > CPosY) {
			return (4);
		}
		else if (PPosX < CPosX && PPosY < CPosY) {
			return (5);
		}
		else if (PPosX > CPosX && PPosY < CPosY) {
			return (6);
		}
		else if (PPosX < CPosX && PPosY > CPosY) {
			return (7);
		}
	}
	return (-1);
}

std::string AI::extractNearestPlayer(irr::f32 CPosX, irr::f32 CPosY) {
	std::string ext;
	std::size_t cz;
	std::string token;
	irr::f32 Fx;
	irr::f32 Fy;
	irr::f32 Nx;
	irr::f32 Ny;
	std::string sendString;

	ext = playerList_.front();
	playerList_.pop_front();
	cz = 0;
	std::istringstream iss(ext);
	std::getline(iss, token, '|');
	Fx = std::round(std::stof(token, &cz));
	std::getline(iss, token, '|');
	cz++;
	Fy = std::round(std::stof(token, &cz));
	sendString = ext;
	while (playerList_.size() > 0){
		ext = playerList_.front();
		playerList_.pop_front();
		cz = 0;
		std::istringstream iss(ext);
		std::getline(iss, token, '|');
		Nx = std::round(std::stof(token, &cz));
		std::getline(iss, token, '|');
		cz++;
		Ny = std::round(std::stof(token, &cz));
		if ((std::sqrt(std::pow((Nx - CPosX), 2)) + std::sqrt(std::pow((Ny - CPosY), 2))) < (std::sqrt(std::pow((Fx - CPosX), 2)) + std::sqrt(std::pow((Fy - CPosY), 2))))
			sendString = ext;
	}
	return (sendString);
}
