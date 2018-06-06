#ifndef REQUEST_CONTROLLER_H
#define REQUEST_CONTROLLER_H

#include <iostream>
#include <gtkmm.h>
#include "RequestCallbacks.h"
#include "NetworkHelper.h"

namespace rock3rdiaz {

	class RequestController : public RequestCallbacks {
		private:
			Gtk::Main* pMain;
			Gtk::Window* pMainWindow;
			Gtk::Button* pRequestButton;
			Gtk::TextView* pOutputTextView;
			Gtk::Entry* pSearchEntryText;

			NetworkHelper* pNetworkHelper;

			void onRequestButtonClick();
			void init();
		public:
			RequestController(Gtk::Main* main, NetworkHelper* pNetworkHelper);
			virtual ~RequestController();
			void onRequestComplete(std::string response);
			inline Gtk::Main* getMain() const { return pMain; }
			inline Gtk::Window* getMainWindow() const { return pMainWindow; }

	};

}

#endif