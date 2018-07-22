#!/bin/bash
# Upgrades permissions of all files for bash on windows as permissions are 
# removed when modifying files within windows then trying to use them in bash 
# for windows.
echo Updating permissions
chmod -R 777 src
chmod -R 777 include
chmod -R 777 examples
chmod -R 777 python
chmod 777 Makefile
chmod 777 Makefile.config

