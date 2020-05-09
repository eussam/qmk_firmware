#!/bin/bash

# - si les sous module git ne sont pas à jour, lancer 'make git-submodule'
# - pour synchroniser la branche master avec le master de zsa: 
#     git fetch upstream
#     git merge upstream/master

# cd qmk_firmware
./util/docker_build_osx.sh ergodox_ez:bepo_eussam
