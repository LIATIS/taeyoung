ifconfig | sed -n '/ether /p' | awk '{print$2}'
