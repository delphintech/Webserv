/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabouab <dabouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:34:02 by dabouab           #+#    #+#             */
/*   Updated: 2024/12/20 15:28:14 by dabouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_HPP
# define CLIENT_HPP

#include "utils.h"

class Client
{
private:
	int					fd;
	struct sockaddr_in	sin;
	socklen_t			slen;

	Client(const Client &client);	// copy operator desactivé
	Client &operator=(const Client &client);	// operator assignement desactivé
	
public:
	Client();
	~Client();

	bool	connect(int	s_port);
	void	disconnect();
	int		msg() const;
	// bool 	send(const unsigned char* msg, unsigned int len);
};

#endif