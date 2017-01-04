#pragma once
#include <SDL\SDL.h>

// Transform structure to store Game Objects (and UI Objects) position
struct Transform {
	union {//A union is a special class type that can hold only one of its non-static data members at a time.
		   //explained at the end of the hh
		//conclusio personal: fa un return unic : el rectangle 
		SDL_Rect rect;//sdl rect es per crear un rectangle (funcio de llibreria sdl)
		struct { Sint32 x, y, w, h; };//coul int x,.. also should works. Jordi use Sint32 for something related with memory (i suppose)
	};
	Transform(int x_, int y_) : x(x_), y(y_), w(0), h(0) {};
	Transform(int x_, int y_, int w_, int h_) : x(x_), y(y_), w(w_), h(h_) {};
	Transform() { x = y = w = h = 0; };//if dont recives nothing equale all to 0
	inline const SDL_Rect &operator()(void) const { return rect; };//funcio que retorna el rectangle(daqui el union)
	//pero com no pot acutar amb variables de clases (el struct en aquest cas)(perque no sabra si les variables seran int, double, barrejades..
	//ha dutilitzar el ordre operator per evitar el error de overload
		
	friend bool operator == (Transform &lhs, Transform &rhs) {//linea relacionada amb la overload y la seguent funcio
		return (lhs.x == rhs.x &&//iguala coordenades de dreta esquerra
			lhs.y == rhs.x &&//ENTENC QUE LHS =LEFT HIGH SQUARE o algo aixi
			lhs.w == rhs.w &&
			lhs.h == rhs.h);
	}
};

//info de union ttp://en.cppreference.com/w/cpp/language/union es comporta en aquest cas union like clase
//info inline: crea una copia del cos de la funcio declarada sense la necesitat de rescirureu, daquesta manera per exemple 
	//la maquina no ha de repetir ho realitzar un retor y no la sobrecarregas
	//mes info de www.youtube.com/watch?v=-j65C9P7-6s