#ifndef NETWORK_HELPER_H
#define NETWORK_HELPER_H

#include <string>
#include <curl/curl.h>

namespace rock3rdiaz {

	class NetworkHelper {
		private:
			std::string url;
			CURL *curl;
			void init();
		public:
			NetworkHelper();
			~NetworkHelper();
			void doGet();
			void doPost();
	};
}

#endif