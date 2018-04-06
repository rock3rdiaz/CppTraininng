#include <iostream>
#include <gtkmm.h>
#include "../include/RequestController.h"
#include "../include/NetworkHelper.h"

using namespace rock3rdiaz;

int main(int argc, char *argv[]) {
	Gtk::Main *main = new Gtk::Main(argc, argv);
	NetworkHelper *pNetworkHelper = new NetworkHelper();
	RequestController *pRequestController = new RequestController(main, pNetworkHelper);
	pNetworkHelper->setBaseController(pRequestController);
	return 0;
}

