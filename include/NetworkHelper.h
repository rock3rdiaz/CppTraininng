#ifndef NETWORK_HELPER_H
#define NETWORK_HELPER_H

#include <string>
#include <curl/curl.h>
#include <iostream>

#include "PostStruct.h"
#include "BaseController.h"

namespace rock3rdiaz {

	class NetworkHelper {
		private:
			BaseController *pBaseController;
			curl_slist *headers;
			CURL *curl;
			CURLcode curlCode;
			
			std::string requestResponse;
			std::string url;

			void finalize();
			static size_t requestBodyWriteCallback(char *ptr, size_t size, size_t nmemb, void *userdata);
		public:
			NetworkHelper();
			~NetworkHelper();
			void doGet(std::string url);
			void doPost(std::string url);
			inline void setBaseController(BaseController *pBC) { pBaseController = pBC; }
	};
}

#endif