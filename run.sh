#!/bin/bash
rm -f mypipe.*
rm -f tmp_pty
mkfifo mypipe.map && mkfifo mypipe.cmd && mkfifo mypipe.adp && mkfifo mypipe.vm

MAP=./maps/map01
BOT=./bot/build/squid.filler
IMG1=./visualizer/resources/img/mario1.jpg
IMG2=./visualizer/resources/img/pacman1.jpg

wait_pseudoterminal() {
  while [ ! -f "tmp_pty" ]
  do
    echo "wait for creation of Pseudoterminal, name will be save to tmp_pty file"
    sleep 1
  done
}

control_msg() {
  echo -e "\nUse  ⬆️\n"
  echo -e "  ⬅️  ⬇️  ➡️\n"
  echo -e "For select press 'space' or 'enter' \n\n"
}

print_usage() {
  printf "Usage:\tyou can simple run ./run.sh\n"
  printf "\t-b \t: to set bot. Example: -t ./bot/build/squid.filler\n"
  printf "\t-m \t: to set bot. Example: -m ./maps/map01\n"
  printf "\t-i \t: to set img1. Example: -i ./visualizer/resources/img/mario1.jpg\n"
  printf "\t-j \t: to set img2. Example: -j ./visualizer/resources/img/pacman1.jpg\n"
  exit 1
}

while getopts 'b:m:i:j:' opts; do
  case "${opts}" in
    b) BOT=${OPTARG} ;;
    m) MAP=${OPTARG} ;;
	i) IMG1=${OPTARG} ;;
	j) IMG2=${OPTARG} ;;
    *) print_usage ;;
  esac
done

(./filler_visu_human $IMG1 $IMG2) &
PID_VISU=$!
echo $PID_VISU
#./74_human_adapter.filler &
open ./r_adapter.command

wait_pseudoterminal
TMP_PTY=$(cat tmp_pty)
echo Pseudoterminal= $TMP_PTY

echo "./filler_vm -p1 ./bot/build/70_human_model.filler " \
"-p2 $BOT -f $MAP -t 99 > $TMP_PTY"

control_msg

./filler_vm -p1 ./bot/build/70_human_model.filler \
-p2 $BOT -f $MAP -t 99 > $TMP_PTY
wait $PID_VISU
pgrep -f adapter | xargs kill -9
echo -e "Game over - 👇  check result with next command:\ncat filler.trace\n"
