#!/bin/bash

# Ĭ�ϲ���
OPTIMIZATION="-O0"
CLEAN=no
DEBUG=no

# ���������в���
while getopts "go:c" opt; do
  case $opt in
    g)
      DEBUG=yes
      ;;
    o)
      if [[ "$OPTARG" =~ ^[0123]$ ]]; then
        OPTIMIZATION="-O$OPTARG"
      else
        echo "Error: -o argument must be 0, 1, 2 or 3." >&2
        exit 1
      fi
      ;;
    c)
      CLEAN=yes
      ;;
    *)
      echo "Usage: $0 [-g] [-o <0|1|2|3>] [-c]" >&2
      exit 1
      ;;
  esac
done

# ���ͬʱָ�� -g �� -o����ϲ�ʹ��
if [[ "$DEBUG" == "yes" && "$OPTIMIZATION" != "-O0" ]]; then
  MAKE_OPTION="$OPTIMIZATION -g"
elif [[ "$DEBUG" == "yes" ]]; then
  MAKE_OPTION="-g"
else
  MAKE_OPTION="$OPTIMIZATION"
fi

cd "./tools/" || { echo "Failed to enter tools directory"; exit 1; }

if [[ "$CLEAN" == "yes" ]]; then
  make clean
fi

if [[ -n "$MAKE_OPTION" ]]; then
  make OPTION="$MAKE_OPTION"
  make test.exe OPTION="$MAKE_OPTION"
else
  make
  make test.exe
fi