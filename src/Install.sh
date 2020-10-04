#!/bin/bash
BASE_URL=https://git.youngchief.tk/gh/raw/youngchief-btw/YoungShell/master/;
wget ${BASE_URL}src/YoungShell.cpp;
curl ${BASE_URL}src/Setup.sh|sh;
echo "/bin/ys" >> /etc/shells;
chsh -s /bin/ys;
exit && exit