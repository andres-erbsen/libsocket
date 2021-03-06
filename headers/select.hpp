# ifndef _SELECT_H
# define _SELECT_H

# include <vector>
# include <map>
# include <utility>
# include <list>
# include <cstring>

# include <sys/select.h>

/*
The committers of the libsocket project, all rights reserved
(c) 2012, dermesser <lbo@spheniscida.de>

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the
following conditions are met:

	1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following
	disclaimer.
	2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following
	disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS “AS IS” AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT
NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.

*/

# include "socket.hpp"

# define READ 1
# define WRITE 2

namespace libsocket
{
	class selectset
	{
		private:
		std::vector<int> filedescriptors;
		std::map<int,socket*> fdsockmap;

		bool set_up;

		fd_set readset;
		fd_set writeset;

		public:

		selectset();

		void add_fd(socket& sock, int method);

		std::pair<std::vector<socket*>, std::vector<socket*> > wait(long long microsecs=0);
	};

	typedef std::pair<std::vector<libsocket::socket*>, std::vector<libsocket::socket*> > ready_socks;

}

#endif
