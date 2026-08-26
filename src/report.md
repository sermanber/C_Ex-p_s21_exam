## Part 1. Готовый докер  
  
Возьми официальный докер-образ с nginx и выкачай его при помощи docker pull  
![alt text](images/5.1.png)  
Проверь наличие докер-образа через docker images  
![alt text](images/5.2.png)  
Создай и запусти контейнер на основе образа через docker run -d [image_id|repository]  
![alt text](images/5.3.png)  
Проверь, что контейнер запустился через docker ps  
![alt text](images/5.4.png)  
Посмотри информацию о контейнере через docker inspect [container_id|container_name]  
![alt text](images/5.5.png)  
По выводу команды определи и помести в отчёт размер контейнера, список замапленных портов и ip контейнера  
![alt text](images/5.6.png)  
![alt text](images/5.7.png)  
![alt text](images/5.8.png)  
Останови докер контейнер через docker stop [container_id|container_name]  
![alt text](images/5.9.png)  
Проверь, что контейнер остановился через docker ps  
![alt text](images/5.10.png)  
Запусти докер с портами 80 и 443 в контейнере, замапленными на такие же порты на локальной машине, через команду run  
![alt text](images/5.11.png)  
Проверь, что в браузере по адресу localhost:80 доступна стартовая страница nginx  
![alt text](images/5.12.png)  
Перезапусти докер контейнер через docker restart [container_id|container_name]  
Проверь любым способом, что контейнер запустился  
![alt text](images/5.13.png)  

## Part 2. Операции с контейнером  
Прочитай конфигурационный файл nginx.conf внутри докер контейнера через команду exec.  
![alt text](images/5.14.png)  
Создай на локальной машине файл nginx.conf.  
Настрой в нем по пути /status отдачу страницы статуса сервера nginx.  
![alt text](images/5.16.png)  
Скопируй созданный файл nginx.conf внутрь докер-контейнера через команду docker cp.  
Перезапусти nginx внутри докер-контейнера через команду exec.  
![alt text](images/5.17.png)  
наша блочная деректива server и порт и localhost игнорируется, так как перед реализацией есть строка  
include /etc/nginx/conf.d/*.conf;
а в дерриктории по этому адресу есть default.conf в котором прописаны порт 80 и localhost  
Для исправления, нужно удалить этот файл, перезагрузить контейнер.  
![alt text](images/5.20.png)  
Проверь, что по адресу localhost:80/status отдается страничка со статусом сервера nginx.  
![alt text](images/5.19.png)  
Экспортируй контейнер в файл container.tar через команду export.  
Останови контейнер.  
Удали образ через docker rmi [image_id|repository], не удаляя перед этим контейнеры.  
Удали остановленный контейнер.  
Создай образ из файла container.tar через команду import.  
Создай и запусти контейнер на основе импортированного образа.  
![alt text](images/5.21.png)  
Проверь, что по адресу localhost:80/status отдается страничка со статусом сервера nginx.  
![alt text](images/5.22.png)  

## Part 3. Мини веб-сервер  

