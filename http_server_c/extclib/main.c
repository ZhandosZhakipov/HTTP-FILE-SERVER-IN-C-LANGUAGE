#include <string.h>
#include "extclib/http.h"

void index_page(int conn, HTTPreq *request);
void about_page(int conn, HTTPreq *request);

int main(void) {
	HTTP *serve = new_http("127.0.0.1:80");
	
	handle_http(serve, "/", index_page);
	handle_http(serve, "/about", about_page);
	
	listen_http(serve);
	free_http(serve);
	return 0;
}

void index_page(int conn, HTTPreq *req) {
	if(strcmp(req->path, "/") != 0){
		parsehtml_http(conn, "page404.html");
		return;
	}
	parsehtml_http(conn, "index.html");
}

void about_page(int conn, HTTPreq *req) {
	if(strcmp(req->path, "/about") != 0){
		parsehtml_http(conn, "page404.html");
		return;
	}
	parsehtml_http(conn, "about.html");
}

