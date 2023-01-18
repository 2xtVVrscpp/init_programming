#!/bin/sh

mode=$1
target=$2

if [ -z $mode ]; then
  mode='err'
elif [ ! $mode = 'ps' ] && [ -z $target ]; then
  mode='err'
fi

# ------------------- command -------------------
# docker-compose start target <- start container
# docker-compose stop target  <- stop container
# docker-compose ps           <- process status
# -----------------------------------------------

if [ "$mode" = "start" ]; then
  if [ "$target" = all ]; then
    # get all target
    target_list=`docker-compose ps | awk '{print $3}' | sed 1d`
    for target in  $target_list
    do
      docker-compose start "$target"
    done
  else
    docker-compose start "$target"
  fi
elif [ "$mode" = "stop" ]; then
  if [ "$target" = all ]; then
    # get all target
    target_list=`docker-compose ps | awk '{print $3}' | sed 1d`
    for target in  $target_list
    do
      docker-compose stop "$target"
    done
  else
    docker-compose stop "$target"
  fi
elif [ "$mode" = "ps" ]; then
  docker-compose ps
else
  echo "syntax is below"
  echo "-------------------------------------------------------------------"
  echo "sh ./container_operation.sh mode target"
  echo "mode: start/stop/ps"
  echo "target: container name when ps, it isn't needed."
  echo "you can use 'all' to start/stop all container"
  echo "if you don't know container name, you should execute the mode 'ps' "
  echo "-------------------------------------------------------------------"
fi