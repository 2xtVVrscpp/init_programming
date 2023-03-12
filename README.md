# how to use this environment

It is three step.

1. build following by docker setting
	1. ```# docker-compose build```
2. create docker container
	1. ```# docker-compose up -d```
     ( -d means to execute on background )
3. run bash (command prompt)
	1. ```# docker-compose exec java bash```

congratulations!! you can use docker!!

とりあえず以下のコマンドを実行すれば動きます．
```
# docker-compose build
# docker-compose up -d
# docker-compose exec java bash
```


then if you can build java program, you put the target src to ./src/sectionN
If you create some code and directory in src, the container can access there.

# how to start/stop a container
server name is the name defined at docker-compose.yml.
In this case, it is **java**.

- start: ```docker-compose start [service name]```
- stop: ```docker-compose stop [service name]```
- status check: ```docker-compose ps```
- remove; ```docker-compose rm [service name]```

If you would like to know other command, please execute docker-compose only.

もしコンテナを起動，停止，状態確認をしたかったらこれで.
基本的なコマンドはLinuxコマンドなので慣れたらノリと勢いでいける．

```
# 起動 今回定義したサービス名はjavaです．
# docker-compose start java

# 停止
# docker-compose stop java

# 状態確認
# docker-compose ps

# コンテナの削除
# docker-compose rm java
```

もしlinuxコマンドが使える環境であれば，shellscriptおいてるのでぜひ使ってもらって


# How to use php code
## Click the link below to open the start page
- http://localhost:8082/start.php

## Each php sample code is accessed as follows
- http://localhost:8082/sectionXX/xxx.php

## reference site
### docker-compose
- https://ichi-station.com/php-xdebug-vscode-docker/