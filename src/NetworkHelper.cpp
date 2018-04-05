#include "../include/NetworkHelper.h"

namespace rock3rdiaz {

	NetworkHelper::NetworkHelper() {
		curl = curl_easy_init();
	}

	void NetworkHelper::init() {
		curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/posts");
	}

	void NetworkHelper::doGet() {

	}

	void NetworkHelper::doPost() {

	}

}