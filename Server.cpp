/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabouab <dabouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:34:28 by dabouab           #+#    #+#             */
/*   Updated: 2024/12/20 15:59:09 by dabouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

Server::Server() : _port(4243) {} // vPort part defaut

Server::Server(int port) : _port(port) {}

Server::~Server() {}

bool	Server::start() {
	struct protoent		*proto;     // protocol structure a utiliser
    struct sockaddr_in	sin;        // Describes an IPv4 Internet domain socket address
    
    // On recupere les information concernant le protocole voulu
    proto =  getprotobyname("tcp");
    if (!proto)
        return (notif("Proto failed", false));

    // On ouvre la socket de communication
    this->_sfd = socket(PF_INET, SOCK_STREAM, proto->p_proto); 
    sin.sin_family = AF_INET; // precise IPv4 Internet protocols
    sin.sin_port = htons(this->_port); // traduit le port en host to network endian
    // precise que la socket accept les connexions de toutes les IP de la machine (traduit en host to network endian)
    sin.sin_addr.s_addr = htonl(INADDR_ANY); 
    
	// On lie la socket a l'adresse
    if (bind(this->_sfd, (const struct sockaddr *)&sin, sizeof(sin)) < 0)
        notif("Bind failed", false);
    // Precise le nombre de connexion simultanees acceptess par la socket
    listen(this->_sfd, 42);
	return (notif("Server on", true));
}

void	Server::stop() {
	close(this->_sfd);
}

int		Server::getSock_fd() { return (this->_sfd); }