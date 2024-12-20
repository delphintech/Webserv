/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabouab <dabouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:54:54 by dabouab           #+#    #+#             */
/*   Updated: 2024/12/20 15:28:37 by dabouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

Client::Client() {}
Client::~Client() {}

bool	Client::connect(int	s_port) {
	// On accept la connection client et renvoie un fd de la socket connectee au client
    this->fd = accept(s_port, (struct sockaddr*)&this->sin, &this->slen);
	if (this->fd < 0)
		return (notif("Client connection failed", false));
	return (notif("Client connected", true));
}

void	Client::disconnect() { close(this->fd); }

int		Client::msg() const {
	int		nb_read = 1;
	char	buf[1024];
	
	nb_read = read(this->fd, buf, 1023);
	buf[nb_read] = '\0';
	if (nb_read > 0)
		std::cout << buf << std::endl;
	return (nb_read);
}
