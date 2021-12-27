#!/bin/bash
LG='\e[1;32m'
Y='\e[1;33m'
packages=("cmake" "gnome-terminal" "libboost-all-dev" "curl")
SCRIPTDIR="$(dirname "$0")"
MAKEFILE="$SCRIPTDIR/Makefile"

if [[ $EUID -ne 0 ]]; then
   echo -e "${LG}This script must be run with sudo${Y}" 
   exec sudo -- "$0" "$@"
fi


for pkg in ${packages[@]}; do

    is_pkg_installed=$(dpkg-query -W --showformat='${Status}\n' ${pkg} | grep "install ok installed")

    if [ ! "${is_pkg_installed}" == "install ok installed" ]; 
    then
      echo ${pkg} is not installed.
      sudo apt-get --yes install ${pkg}
      echo "sudo apt-get remove -y $pkg" >> cleanup.sh
      if [ "${pkg}" == "libboost-all-dev" ]; 
      then
        echo "sudo apt-get autoremove -y" >> cleanup.sh
      fi
    fi
done

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