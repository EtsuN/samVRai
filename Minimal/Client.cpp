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

void init_server() {	/* empty */ }
void run_server() {	/* empty */ }

rpc::client* c;
string s;

int player_num;

int init_client() {
	// Setup an rpc client that connects to "localhost:8080"
	std::cout << "This is Client" << std::endl;
	std::cout << "Connecting..." << std::endl;
	c = new rpc::client("localhost", 8080);
	player_num = c->call("handshake", "Nabi").get().as<int>();
	std::cout << "Connected to server, and I am: " << player_num << "P" << std::endl;
	return player_num;
}

void run_client()
{

	// Client side logic
	/*c->call()

	string input = "hi";



	string result;
	string p;
	std::tie(result, p) = c->call("echo", input, p).get().as<std::tuple<string, string>>();*/

}
