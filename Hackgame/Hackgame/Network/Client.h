#ifndef CLIENT_H
#define CLIENT_H

#include <SFML\Network.hpp>

class Client
{
public:
	Client();

	bool ConnectToServer();

private:
	sf::Socket m_client;

};

#endif