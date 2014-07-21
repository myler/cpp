#include <iostream>
#include <string>
#include "ace/SOCK_Connector.h"
#include "ace/INET_Addr.h"
#include "ace/Log_Msg.h"

const int SIZE_BUF = 128;

class Client
{
private:
	ACE_SOCK_Stream client_stream_;
	ACE_INET_Addr remote_addr_;
	ACE_SOCK_Connector connector_;
	const char *data_buf_;
public:
	Client(char *hostname, int port, std::string &str)
	 : remote_addr_(port, hostname), data_buf_(str.data()) {}

	int connect_to_server()
	{
		ACE_DEBUG((LM_DEBUG, "(%P|%t) Starting connect to %s:%d\n",
			remote_addr_.get_host_name(), remote_addr_.get_port_number()));
		if (connector_.connect(client_stream_, remote_addr_) == -1)
		{
			ACE_ERROR_RETURN((LM_ERROR, "(%P|%t) %p\n", "connection failed"), -1);
		} else {
			ACE_DEBUG((LM_DEBUG, "(%P|%t) connected to %s:%d\n",
				remote_addr_.get_host_name()));
		}

		return 0;
	}

	int send_to_server()
	{
		if (client_stream_.send_n(data_buf_,
			ACE_OS::strlen(data_buf_) + 1, 0) == -1)
		{
			ACE_ERROR_RETURN((LM_ERROR, "(%P|%t) %p\n", "send_n"), 0);
		}

		close();
	}

	int close()
	{
		if (client_stream_.close() == -1)
		{
			ACE_ERROR_RETURN((LM_ERROR, "(%P|%t) %p\n", "close"), -1);
		} else {
			return 0;
		}
	}
};

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		ACE_DEBUG((LM_DEBUG, "Usage %s <hostname> <port_number>\n", argv[0]));
		ACE_OS::exit(1);
	}

	std::string str;
	std::cout << "Please enter what you want to say.\n";
	while(getline(std::cin, str)) {
	    Client client(argv[1], ACE_OS::atoi(argv[2]), str);
		client.connect_to_server();
		client.send_to_server();

		std::cout << "Enter again: ";
	}

	return 0;
}