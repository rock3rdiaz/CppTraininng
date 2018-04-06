#ifndef BASE_CONTROLLER_H
#define BASE_CONTROLLER_H

#include <iostream>

namespace rock3rdiaz {

	class BaseController {

		public:
			virtual void onRequestComplete(std::string response) = 0;

	};

}

#endif