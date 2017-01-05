#pragma once
#include <iostream>

//Enum to ID the Game Objects IN the game
enum class ObjectID : const int {
	SNAKE, BLOCK, FOOD
	//BACKGROUND? pot ser no es necessari
	//block seran els blocks que delimitan el mapa
};

//Enum to ID the Fonts in the game
enum class FontID : int {
	//aqui basicament escrius situacions ens las que utilitzarem un tipus de lletra, no declares la tipografia,
	//exemple
	MENU, BEATSCORE, SCORE, GAMEOVER, EXIT

};

inline std::ostream &operator<<(std::ostream &os, const ObjectID &id) { return os << int(id); }
inline std::istream &operator >> (std::istream &is, ObjectID &id) { return is >> reinterpret_cast<int&>(id); };
//he mirat la linea 19 i 20, no sabria explicarte perque serveixen (inclus no ho acabo dentendre jo) pero ha destar si o si, aixo ho tinc
//bastant segur nose perqe, pero per lu que he llegit i esta relacionat amb la creacio del objecte en si

//output stream object / input stream object 
//www.cplusplus.com/reference/ostream/ostream/operator<</
//www.cplusplus.com/reference/ostream/ostream/operator-free/
//reinterpret_cast<int&> crec que el fa per eviitar problemes de punters 
/*Reinterpret_cast convierte cualquier tipo de puntero en cualquier otro tipo de puntero, incluso de clases no relacionadas. 
El resultado de la operaci�n es una simple copia binaria del valor de un puntero a otro.
Se permiten todas las conversiones de puntero: no se comprueba el contenido apuntado ni el tipo de puntero.*/
//ttp://stackoverflow.com/questions/573294/when-to-use-reinterpret-cast

//inline explicat en Transform.hh