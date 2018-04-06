#ifndef REQUEST_CONTROLLER_H
#define REQUEST_CONTROLLER_H

#include <iostream>
#include <gtkmm.h>
#include "BaseController.h"
#include "NetworkHelper.h"

namespace rock3rdiaz {

	class RequestController : public BaseController {
		private:
			Gtk::Main *pMain;
			Gtk::Window *pMainWindow;
			Gtk::Button *pRequestButton;
			Gtk::TextView *pOutputTextView;
			Gtk::Entry *pSearchEntryText;

			NetworkHelper *pNetworkHelper;

			void onRequestButtonClick();
			void init();
		public:
			RequestController(Gtk::Main *main, NetworkHelper *pNetworkHelper);
			virtual ~RequestController();
			void onRequestComplete(std::string response);

	};

}

#endif