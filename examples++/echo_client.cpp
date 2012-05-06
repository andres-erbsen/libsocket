# include <iostream>
# include <unistd.h>
# include "../headers++/inetclientdgram.hpp"

int main(void)
{
	using std::string;

	string host = "localhost";
	string port = "1234";

	char buf[10];

	buf[9] = 0;

	libsocket::inet_dgram_client sock(IPv4);

	try {
		std::cout << sock.gethost();
	} catch (libsocket::inet_exception exc)
	{
		std::cerr << exc.mesg;
	}

	for ( int i = 0; i < 20; i++ )
	{
		sock.sndto("abcdefghi",9,host.c_str(),port.c_str());
		sock.rcvfrom(buf,9,0,0,0,0);
		std::cout << buf;

		std::cout.flush();
	}

	sock.destroy();

	return 0;
}
