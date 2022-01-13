#include <stdio.h>
#include <netdb.h>
#include <cstdlib>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

int main(int argc, char **argv)
{
        struct sockaddr_in remote;
        struct hostent *h;
	int nret, startp, endp;
        int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        memset(&remote, sizeof(remote), 0);
        remote.sin_family = AF_INET;
        if (! inet_aton(argv[1], &remote.sin_addr) )
        {
                perror("inet_aton(): ");
                exit(1);
        }
	startp = atoi(argv[2]);
	endp = atoi(argv[3]);
	for (int i = startp; i <= endp; i++)
	{
	        remote.sin_port = htons(i);
       		nret = connect(sock, (struct sockaddr*) &remote, sizeof(remote));
		if (nret != 0 && nret != -1) {
			printf ("PORT %d:     FILTERED\n", i);
        	} else if (nret < 0) {
                	printf("PORT %d:      CLOSED\n", i);
		} else {
        		printf("PORT %d:      OPEN\n", i);
		}
	}
}
