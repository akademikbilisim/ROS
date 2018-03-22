#!/bin/bash

# sudo apt-get update

ROSDISTRO=kinetic
DISTRO=ubuntu
CODENAME=xenial
DIR=$(rospack find ab18ros)
PACKAGES=$(find $DIR/.. -name package.xml | rev | cut -d/ -f2 | rev)
for package in $PACKAGES; do 
  echo "$(tput bold)Scanning dependencies for $package$(tput sgr0)"
  rosdep install -y $package --rosdistro $ROSDISTRO --os $DISTRO:$CODENAME 
  echo "===="
done 
