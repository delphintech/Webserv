/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabouab <dabouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:31:35 by dabouab           #+#    #+#             */
/*   Updated: 2024/12/20 15:30:32 by dabouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "Server.hpp"
#include "Client.hpp"

int	main(int ac, char **av)
{
    Server		server;
	Client		client;
	int			nb_read = 1;

	(void)ac;
	(void)av;
	
    if (!server.start())
		return (EXIT_FAILURE);
	if (!client.connect(server.getSock_fd()))
		return (EXIT_FAILURE);
	while (nb_read)
		nb_read = client.msg();
	client.disconnect();
	server.stop();
	return (EXIT_SUCCESS);
}