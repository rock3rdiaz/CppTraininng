#include "../include/NetworkHelper.h"

namespace rock3rdiaz {

	NetworkHelper::NetworkHelper() {
		headers = nullptr;
		curl = curl_easy_init();
		curl_slist_append(headers, "Content-Type: Application/json;charset=utf-8");
		curl_slist_append(headers, "Accept: Application/json");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers); 
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION , NetworkHelper::requestBodyWriteCallback); 
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, static_cast<void *>(&requestResponse)); 
	}

	void NetworkHelper::finalize() {
		curl_easy_cleanup(curl);
	}

	void NetworkHelper::doGet(std::string url) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
		curlCode = curl_easy_perform(curl);
		if(curlCode == CURLE_OK) {
			pRequestCallbacks->onRequestComplete(requestResponse);
		} else {
			pRequestCallbacks->onRequestError();
		}

	}

	void NetworkHelper::doPost(std::string url) {
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_POST, 1L);
		curlCode = curl_easy_perform(curl);
	}

	size_t NetworkHelper::requestBodyWriteCallback(char* ptr, size_t size, size_t nmemb, void* userdata) {
		std::string* p = static_cast<std::string*>(userdata);
		int realSize = size * nmemb;
		
		for(int i = 0; i < realSize; i++) {
			p->push_back(ptr[i]);
		}
    	
		return realSize;
	}

	NetworkHelper::~NetworkHelper() {
		delete this;
	}

}