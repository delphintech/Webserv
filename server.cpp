/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabouab <dabouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:34:28 by dabouab           #+#    #+#             */
/*   Updated: 2024/12/20 14:18:20 by dabouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.hpp"

void create_server(t_server *server)
{
    struct protoent		*proto;     // protocol structure a utiliser
    struct sockaddr_in	sin;        // Describes an IPv4 Internet domain socket address
    
    // On recupere les information concernant le protocole voulu
    proto =  getprotobyname("tcp");
    if (!proto)
        notif("Proto failed", true);
    // On ouvre la socket de communication
    server->sock_fd = socket(PF_INET, SOCK_STREAM, proto->p_proto); 
    sin.sin_family = AF_INET; // precise IPv4 Internet protocols
    sin.sin_port = htons(server->port); // traduit le port en host to network endian
    // precise que la socket accept les connexions de toutes les IP de la machine (traduit en host to network endian)
    sin.sin_addr.s_addr = htonl(INADDR_ANY); 
    // On lie la socket a l'adresse
    if (bind(server->sock_fd, (const struct sockaddr *)&sin, sizeof(sin)) < 0)
        notif("bind failed", true);
    // Precise le nombre de connexion simultanees acceptess par la socket
    listen(server->sock_fd, 42);
	notif("Server on", false);
}

int	main(int ac, char **av)
{
    t_server	server;
    t_client	client;
	int			nb_read = 1;
	char		buf[1024];

	// valeurs par defaut
	server.port = 4243;
	(void)ac;
	(void)av;
	
    create_server(&server);
	// On accept la connection client et renvoie un fd de la socket connectee au client
    client.fd = accept(server.sock_fd, (struct sockaddr*)&client.sin, &client.slen);
	if (client.fd < 0)
		notif("Client connection failed", true);
	// On lit ce que le client nous envoie
	while (nb_read)
	{
		nb_read = read(client.fd, buf, 1023);
		buf[nb_read] = '\0';
		if (nb_read > 0)
			std::cout << buf << std::endl;
	}
	// On stoppe la connection avec le client
	close(client.fd);
	// on ferme le serveur
    close(server.sock_fd);
    return (EXIT_SUCCESS);
}
