// Client.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "../Shared/ServerClientConnection.h"
#include "pch.h"
#include "rpc/client.h"

#include <glm/gtx/string_cast.hpp>

// Shared struct


using std::string;
/*
	Always test in release mode
	Set the IP address
*/

void setup_server() {	/* empty */ }
void run_server() {	/* empty */ }

rpc::client* c;
string s;

void setup_client() {
	// Setup an rpc client that connects to "localhost:8080"
	std::cout << "This is Client" << std::endl;
	std::cout << "Connecting..." << std::endl;
	c = new rpc::client("localhost", 8080);
	string server = c->call("handshake", "Nabi").get().as<string>();
	std::cout << "Connected to server: " << server << std::endl;
}

void run_client()
{

	// Client side logic
	string input = "hi";

	string result;
	string p;
	std::tie(result, p) = c->call("echo", input, p).get().as<std::tuple<string, string>/*cast back the respond message to string and Player*/>();

}
