#include "../include/RequestController.h"

namespace rock3rdiaz {

	RequestController::RequestController(Gtk::Main* main, NetworkHelper* networkHelper) {
		pMain = main;
		pNetworkHelper = networkHelper;
		init();
	}

	void RequestController::init() {
		Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("../ui/main_window.glade");
		builder->get_widget("main_window", pMainWindow);
		builder->get_widget("request_button", pRequestButton);
		builder->get_widget("output_textView", pOutputTextView);
		builder->get_widget("search_entryText", pSearchEntryText);

		//pRequestButton->signal_clicked().connect(sigc::ptr_fun(&onRequestButtonClick));
		pRequestButton->signal_clicked().connect(sigc::mem_fun(*this, &RequestController::onRequestButtonClick));
	}

	void RequestController::onRequestButtonClick() {
		pNetworkHelper->doGet(pSearchEntryText->get_text());
	}

	void RequestController::onRequestComplete(std::string response) {
		Glib::RefPtr<Gtk::TextBuffer> textBuffer = pOutputTextView->get_buffer();
		textBuffer->set_text(response);
	}

	RequestController::~RequestController() {
		delete pMain;
		delete pNetworkHelper;
		delete pMainWindow;
		delete pRequestButton;
		delete pSearchEntryText;
		delete pOutputTextView;
	}
}