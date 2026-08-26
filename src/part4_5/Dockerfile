FROM ubuntu:22.04
WORKDIR /app
RUN apt update && apt install -y \
    gcc \
    libfcgi-dev \
    nginx \
    spawn-fcgi \
    && rm -rf /var/lib/apt/lists/* \
    && rm -f /etc/nginx/sites-enabled/default \
    && useradd -r -s /bin/false pickle_rick
COPY main.c .
COPY index.html .
RUN gcc main.c -o main -lfcgi
COPY nginx/nginx.conf /etc/nginx/nginx.conf
COPY nginx/fastcgi_params /etc/nginx/fastcgi_params
RUN chown -R pickle_rick:pickle_rick /app /var/lib/nginx /var/log/nginx /run
HEALTHCHECK --interval=30s --timeout=3s \
  CMD curl -f http://localhost/ || exit 1
USER pickle_rick
CMD ["/bin/bash", "-c", "spawn-fcgi -p 8080 ./main && nginx -g 'daemon off;'"]