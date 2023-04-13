#pragma once
#include "settings.h"
#include "Player.h"
class Bonus {
public:
	enum BonusType {KABOOM, MEDKIT, SPEED_BOOST, MAX_BONUS_TYPE };
	Bonus(size_t bonustype, sf::Vector2f meteorPos);
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();
	void setDel();
	bool isToDel();
	bool offScreen();
	void act(Player& player);

private:
	sf::Sprite sprite;
	sf::Texture texture;
	BonusType type;
	bool del = false;
};

Bonus::Bonus(size_t bonustype, sf::Vector2f meteorPos) {
	switch (type) {
	case KABOOM:
		this->type = type;
		texture.loadFromFile(KABOOM_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setPosition(meteorPos);
		break;

	case MEDKIT:
		this->type = type;
		texture.loadFromFile(MEDKIT_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setPosition(meteorPos);
		break;

	case  SPEED_BOOST:
		this->type = type;
		texture.loadFromFile(SPEED_BOOST_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setPosition(meteorPos);
		break;
	}
}

void update() {  }

void draw(sf::RenderWindow& window) { window.draw(sprite); }

sf::FloatRect Bonus::getHitBox() { return sprite.getGlobalBounds(); }

sf::Vector2f Bonus::getPosition() { return sprite.getPosition(); }

bool Bonus::isToDel() { return del; }

void Bonus::setDel() { del = true; }

bool Bonus::offScreen() {
	if (sprite.getPosition().y > WINDOW_HEIGHT) return true;
	return false;
}

void Bonus::act(Player& player) {
	switch (type) {
	case  KABOOM:
		player.FIRE_UP();
		break;
	case MEDKIT:
		player.HP_UP();
			break;
	case SPEED_BOOST: 
		player.Speed_Boost();
		break;
	}
}