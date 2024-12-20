/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabouab <dabouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:23:14 by dabouab           #+#    #+#             */
/*   Updated: 2024/12/20 13:43:18 by dabouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

void	notif(std::string msg, char *error)
{
	std::cout << COLOR(90) << msg;
	if (error)
	{
		std::cout << ": " << error;
		exit(EXIT_FAILURE);
	}
		exit(EXIT_FAILURE);
	std::cout << COLOR(0) << std::endl;
}