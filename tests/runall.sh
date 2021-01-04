#!/bin/bash

cp ../get* GNL_lover/copy_in_here_GNL_files
curdir=$(pwd)
for folder in *; do
	[ -d "$folder" ] && cd "$folder" && ./runall.sh; cd ..
done
cd $curdir
cd gnl-war-machine-v2019 && ./runall.sh; cd ..
rm GNL_lover/copy_in_here_GNL_files/get*
