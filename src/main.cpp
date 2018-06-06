#include <iostream>
#include <gtkmm.h>
#include "../include/RequestCallbacks.h"
#include "../include/RequestController.h"
#include "../include/NetworkHelper.h"

using namespace rock3rdiaz;

int main(int argc, char* argv[]) {
	NetworkHelper* pNetworkHelper = new NetworkHelper();
	RequestController pRequestController = RequestController(new Gtk::Main(argc, argv), pNetworkHelper);
	RequestCallbacks* callbacks = &pRequestController;
	pNetworkHelper->setCallbacks(callbacks);
	pRequestController.getMain()->run(*pRequestController.getMainWindow());

	return 0;
}