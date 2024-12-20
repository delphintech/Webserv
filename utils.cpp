/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabouab <dabouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:23:14 by dabouab           #+#    #+#             */
/*   Updated: 2024/12/20 14:16:08 by dabouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

void	notif(std::string msg, bool err)
{
	std::cout << COLOR(90) << msg;
	if (err)
	{
		std::cout << ": " << std::strerror(errno);
		exit(EXIT_FAILURE);
	}
	std::cout << COLOR(0) << std::endl;
}