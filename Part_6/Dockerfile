FROM nginx
WORKDIR /home/
COPY ./nginx/nginx.conf /etc/nginx/nginx.conf
COPY ./start.sh start.sh
RUN apt-get update && apt-get install -y gcc spawn-fcgi libfcgi-dev; \
	apt-get clean && rm -rf /var/lib/apt/lists/*; \
	chown -R nginx:nginx /etc/nginx/nginx.conf; \
	chown -R nginx:nginx /var/cache/nginx; \
	chown -R nginx:nginx /home; \
	touch /var/run/nginx.pid; \
	chown -R nginx:nginx /var/run/nginx.pid; \
	chmod u-s /bin/mount; \
	chmod u-s /bin/umount; \
	chmod u-s /usr/bin/newgrp; \
	chmod u-s /usr/bin/chfn; \
	chmod u-s /usr/bin/chsh; \
	chmod u-s /usr/bin/passwd; \
	chmod u-s /usr/bin/gpasswd; \
	chmod u-s /bin/su; \
	chmod g-s /usr/bin/chage; \
	chmod g-s /usr/bin/wall; \
	chmod g-s /sbin/unix_chkpwd; \
	chmod g-s /usr/bin/expiry
USER nginx
HEALTHCHECK --interval=15s --retries=2 --start-period=5s --timeout=5s CMD curl -sS 127.0.0.1:8080 || exit 1
ENTRYPOINT ["sh", "./start.sh"]
