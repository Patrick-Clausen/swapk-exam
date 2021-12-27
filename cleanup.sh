#!/bin/bash
LG='\e[1;32m'
Y='\e[1;33m'

if [[ $EUID -ne 0 ]]; then
   echo -e "${LG}This script must be run as root${Y}" 
   exec sudo -- "$0" "$@"
fi
