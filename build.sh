#!/bin/bash

SOURCE_DIR=`pwd`
BUILD_DIR=${BUILD_DIR:-${SOURCE_DIR}/output/}
INSTALL_DIR=${INSTALL_DIR:-${BUILD_DIR}/bin/}

MODE="normal"
IS_CLEAR=""

while getopts "xc" arg; do
	case $arg in 
		x)
			MODE="xcode"
			;;
		c)
			IS_CLEAR="1"
			;;
		?)
			echo "error args"
			exit -1
			;;
	esac
done

if [ $IS_CLEAR == "1" ]; then
rm -fr ${BUILD_DIR}
fi

if [ ! -d ${BUILD_DIR} ]; then
mkdir ${BUILD_DIR}
fi

cd ${BUILD_DIR}

function build_normal()
{
	cmake -DCMAKE_INSTALL_PREFIX=${INSTALL_DIR} ${SOURCE_DIR}
	make 
}

function build_xcode()
{
	cmake -G Xcode ${SOURCE_DIR}
}


if [ $MODE == 'normal' ]; then
	build_normal
elif [ $MODE == 'xcode' ]; then
	build_xcode
fi


