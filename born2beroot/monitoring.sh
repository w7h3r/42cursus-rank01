#!/bin/bash

#github.com/w7h3r
BANNER=$(cat << 'EOF'
                                                                                                                                  
   dP"8 Y88b Y8P  dP"8   888 Y88b Y88 888'Y88   e88 88e   
  C8b Y  Y88b Y  C8b Y   888  Y88b Y8 888 ,'Y  d888 888b  
   Y8b    Y88b    Y8b    888 b Y88b Y 888C8   C8888 8888D 
  b Y8D    888   b Y8D   888 8b Y88b  888 "    Y888 888P  
  8edP     888   8edP    888 88b Y88b 888       "88 88"   

EOF
)

ARC_INFO=$(uname -a)
CPU_INFO=$(cat /proc/cpuinfo)
CPU_LOAD=$(cat /proc/loadavg)
MEM_INFO=$(free -m)
DISK_INFO=$(df --total -h | grep 'total')
NETWORK_INFO=$(hostname -I)
MAC_INFO=$(ip link show)
TCP_CON_INFO=$(ss -t state established | wc -l)
USER_INFO=$(who | wc -l)
BOOT_INFO=$(uptime -s)
SUDO_COMM_INFO=$(cat /var/log/sudo/sudo.log | grep "COMMAND" | wc -l)
LVM_USAGE=$(
  if [ $(lsblk | grep 'LVMGroup' | wc -l) -eq 0 ]; then
    echo "NOT AVAILABLE"
  else
    echo "AVAILABLE"
  fi
)


wall "
  $BANNER

  Operating System Info
-----------------------------
# Hostname: $(echo "$ARC_INFO" | awk '{print $2}')
# OS/Type: $(echo "$ARC_INFO" | awk '{print $1 " / " $11}')
# Kernel Version: $(echo "$ARC_INFO" | awk '{print $3}')
# Kernel Build: $(echo "$ARC_INFO" | awk '{print $4, $5, $6, $7, $8, $9}')
# Architecture: $(echo "$ARC_INFO" | awk '{print $10}')

  CPU Resources Status
-----------------------------
# PCPU: $(echo "$CPU_INFO" | grep "cpu cores" | uniq | awk '{print $4}')
# VCPU: $(nproc)
# CPU Load: $(echo "$CPU_LOAD"| awk '{print "("$1"%)"}')

  Disk and Memory Usage
-----------------------------
# RAM: $(echo "$MEM_INFO" | grep "Mem:" | awk '{print $3"/"$2"MB"}') $(echo "$MEM_INFO" | awk '/Mem/ {print"(" $3/$2 *100"%)"}')
# Disk: $(echo "$DISK_INFO" | awk '{print $3 "/" $2 " ("$5")"}')

  Connection and Moderation
-----------------------------
# Network: $(echo "$NETWORK_INFO" | awk '{print "IP "$1 " /"}') $(echo "$MAC_INFO" | grep 'link/ether' | awk '{print $2}')
# TCP Connections: $(echo "$TCP_CON_INFO" "ESTABLISHED")
# Logged Users: $(echo "$USER_INFO")
# Last Boot: $(echo "$BOOT_INFO")
# LVM: $(echo "$LVM_USAGE")
# Sudo Command(s): $(echo "$SUDO_COMM_INFO" "cmd")
"
