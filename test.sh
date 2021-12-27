#!/bin/bash
LG='\e[1;32m'
Y='\e[1;33m'
REQUIRED_PKG=("cmake" "gnome-terminal" "libboost-all-dev")
SCRIPTDIR="$(dirname "$0")"
MAKEFILE="$SCRIPTDIR/Makefile"

if [[ $EUID -ne 0 ]]; then
   echo -e "${LG}This script must be run as root${Y}" 
   exec sudo -- "$0" "$@"
fi


PKG_OK=$(dpkg-query -W --showformat='${Status}\n' $REQUIRED_PKG|grep "install ok installed")
echo Checking for $REQUIRED_PKG: $PKG_OK
if [ "" = "$PKG_OK" ]; then
  echo "No $REQUIRED_PKG. Setting up $REQUIRED_PKG."
  sudo apt-get --yes install $REQUIRED_PKG
fi

if [ ! -f "$MAKEFILE" ]; then
  cmake CMakeLists.txt -DCMAKE_BUILD_TYPE=Release
fi

echo -e "${LG}Running Make${Y}"
make
echo -e "${LG}Giving execute permissions${Y}"
chmod +x swapk_exam

echo -e "${LG}Opening terminal and starting web api${Y}"
sudo gnome-terminal -- sudo ./swapk_exam

echo -e "${LG}Testing GET with command: curl localhost/weather${Y}:"
curl localhost/weather

echo -e "${LG}Testing POST with command: curl --data ""POST"" localhost/weather${Y}:"
curl --data "POST" localhost/weather

echo -e "${LG}Testing valid endpoint but not valid method with command: curl -X PUT localhost/test${Y}:"
curl -X PUT localhost/weather

echo -e "${LG}Testing nonexisting endpoint with command: curl localhost/test${Y}:"
curl localhost/test