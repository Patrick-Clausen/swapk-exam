if [[ $EUID -ne 0 ]]; then
   echo -e "${LG}This script must be run as root${Y}" 
   exec sudo -- "$0" "$@"
fi
 