#include "fcgi_stdio.h"
#include <stdlib.h>

int main(void)
{
	while(FCGI_Accept() >= 0)
	{
		printf("Content-type: text/html\r\nStatus: 200 OK\r\n\r\n");
		printf("<html><head><title>Jeez!</title></head>\n");
		printf("<body><h1>Hello!How are you?</h1></body>\n");
		printf("</html>\n");
	}
	return 0;
}
