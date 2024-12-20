/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabouab <dabouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:55:21 by dabouab           #+#    #+#             */
/*   Updated: 2024/12/20 13:43:31 by dabouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
# define SERVER_HPP

#include <iostream>
#include <cerrno>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <cstring>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>

#define COLOR(nb) "\e["#nb"m"

typedef struct	s_server
{
	int		port;       // port d'ecoute du serveur
	int		sock_fd;    // fd de la socket de ommunication
}   t_server;

typedef struct	s_client
{
    int					fd;
    struct sockaddr_in	sin;
    socklen_t			slen;
}	t_client;

void	notif(std::string msg, char *error);

#endif