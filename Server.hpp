/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabouab <dabouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:55:21 by dabouab           #+#    #+#             */
/*   Updated: 2024/12/20 15:56:59 by dabouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

#include "utils.h"
#include "Client.hpp"

class Server
{
private:
	int		_port;       // port d'ecoute du serveur
	int		_sfd;    	// fd de la socket de ommunication
	Client	*clients;
	
	Server(const Server &arg); // Copy operator desactivé
	Server& operator=(Server &arg); // assignment operator desactivé
	
public:
	Server();
	Server(int port); // Cree le serveur avec un port defini
	~Server();

	bool	start();
	void	stop();
	int		Send();
	
	int		getSock_fd();
};

#endif