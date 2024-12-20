/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabouab <dabouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 13:23:14 by dabouab           #+#    #+#             */
/*   Updated: 2024/12/20 14:49:37 by dabouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	notif(std::string msg, bool ok)
{
	std::cout << COLOR(90) << msg;
	if (!ok)
	{
		std::cout << ": " << std::strerror(errno);
	}
	std::cout << COLOR(0) << std::endl;
	return (ok);
}