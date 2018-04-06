#include "../include/RequestController.h"

namespace rock3rdiaz {

	RequestController::RequestController(Gtk::Main *main, NetworkHelper *networkHelper) {
		pMain = main;
		pNetworkHelper = networkHelper;
		init();
	}

	void RequestController::init() {
		Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("../ui/main_window.glade");
		builder->get_widget("main_window", pMainWindow);
		builder->get_widget("request_button", pRequestButton);

		//pRequestButton->signal_clicked().connect(sigc::ptr_fun(&onRequestButtonClick));
		pRequestButton->signal_clicked().connect(sigc::mem_fun(this, &RequestController::onRequestButtonClick));

		pMain->run(*pMainWindow);
	}

	void RequestController::onRequestButtonClick() {
		pNetworkHelper->doGet("https://jsonplaceholder.typicode.com/posts");
	}

	void RequestController::onRequestComplete(std::string response) {
		//std::cout << "text: " << response;
		Gtk::TextBuffer textBuffer = pOutputTextView->get_buffer();
		textBuffer->set_text("rocker");
		pOutputTextView.set_buffer(textBuffer);
	}

	RequestController::~RequestController() {
	}

}