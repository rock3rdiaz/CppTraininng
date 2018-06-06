#ifndef PERSON_H
#define PERSON_H

#include <iostream>

namespace rock3rdiaz {

	class Person {
		private:
			std::string firstName, lastName;
		public:
			Person(std::string fName, std::string lName) : firstName(fName), lastName(lName) {}
			~Person();
			inline std::string getFullName() { return firstName + " " + lastName;  }
	};
	
}


#endif