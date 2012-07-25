# ifndef _EXCEPTION_H
# define _EXCEPTION_H

# include <string>

using std::string;
namespace libsocket
{
	struct socket_exception
	{
		string mesg;

		socket_exception(string,int,string);
	};
}
# endif
