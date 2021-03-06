# include <iostream>
# include <string>
# include "../headers/inetclientstream.hpp"
# include "../headers/exception.hpp"

// HTTP client demonstrating the use of stream operators
// on STREAM sockets

int main(void)
{
	using std::string;

	using libsocket::inet_stream;

	try {
		string host = "176.28.21.82";
		string port = "80";
		string answer;
		string request1("GET / HTTP/1.1\n");
		string request2("Host: spheniscida.de\n\n");

		libsocket::inet_stream sock(host.c_str(),port.c_str(),IPv4,0);

		sock << request1 << request2;

		sock.shutdown(WRITE);

		answer.resize(2000);


		while ( answer.size() > 0 )
		{
			sock >> answer;

			std::cout << answer;
		}

		sock.destroy();
	} catch (libsocket::socket_exception exc)
	{
		std::cerr << exc.mesg;
	}

	return 0;
}
