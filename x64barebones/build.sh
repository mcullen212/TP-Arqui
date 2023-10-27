#!/bin/bash

result=${PWD##*/}
docker start $result
docker exec -w /root/Toolchain -it $result make clean all
docker exec -w /root/ -it $result make clean all
docker exec -w /root/Image -it $result chmod 777 *
docker stop $result
