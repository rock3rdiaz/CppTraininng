/**
 *
 * A HTTP Requests callback 
 * 
 */



#ifndef BASE_CONTROLLER_H
#define BASE_CONTROLLER_H

#include <iostream>

namespace rock3rdiaz {

	class RequestCallbacks {

		public:
			virtual void onRequestComplete(std::string response) = 0;
			inline void onRequestError() { std::cout << "request error :(" << std::endl; }

	};

}

#endif