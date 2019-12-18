#!/bin/bash

# PF: 30/06/2019  copie du rep qmk_firmware pour compiler mes layout facilement
# épuration du repo un max pour accélérer la comilation avec docker et vider le repo d'origine
# déplacement du fichier hex eussam généré dans répertoire ./hex
# TODO: épurer encore plus le rép qmk_firmware pour virer tout ce dont je ne me sers pas

# cd qmk_firmware
./util/docker_build_osx.sh ergodox_ez:bepo_eussam
