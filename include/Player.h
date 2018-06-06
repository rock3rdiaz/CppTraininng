#ifndef PLAYER_H
#define PLAYER_H

#include "Person.h"
#include <iostream>

namespace rock3rdiaz {

	class Player : public Person {
		private:
			std::string position;
		public:
			inline std::string getPosition() { return position; }
	};

}

#endif