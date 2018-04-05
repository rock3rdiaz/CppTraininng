#include <iostream>
#include <gtkmm.h>
#include "../include/NetworkHelper.h"

using namespace rock3rdiaz;

void uiConfiguration(Gtk::Main mW);

int main(int argc, char *argv[]) {
	Gtk::Main app(argc, argv);
	uiConfiguration(app);
	NetworkHelper *nH = new NetworkHelper();
	return 0;
}

void uiConfiguration(Gtk::Main mW) {
	Gtk::Window* pWindow = nullptr;
	Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("../ui/main_window.glade");
	builder->get_widget("main_window", pWindow);
	mW.run(*pWindow);
}

