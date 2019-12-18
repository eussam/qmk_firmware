#!/bin/sh

# PF: optimisation pour docker build sous OSX

# NOTE: This script uses tabs for indentation

errcho() {
	echo "$@" >&2
}

USAGE="Usage: $0 [keyboard[:keymap[:target]]]"

# Check preconditions
for arg; do
	if [ "$arg" = "--help" ]; then
		echo "$USAGE"
		exit 0
	fi
done
if [ $# -gt 1 ]; then
	errcho "$USAGE"
	exit 1
elif ! command -v docker >/dev/null 2>&1; then
	errcho "Error: docker not found"
	errcho "See https://docs.docker.com/install/#supported-platforms for installation instructions"
	exit 2
fi

# Determine arguments
if [ $# -eq 0 ]; then
	printf "keyboard=" && read -r keyboard
	[ -n "$keyboard" ] && printf "keymap=" && read -r keymap
	[ -n "$keymap"   ] && printf "target=" && read -r target
else
	IFS=':' read -r keyboard keymap target x <<-EOF
	$1
	EOF
	if [ -n "$x" ]; then
		errcho "$USAGE"
		exit 1
	fi
fi
if [ -n "$target" ]; then
	if [ "$(uname)" = "Linux" ] || docker-machine active >/dev/null 2>&1; then
		usb_args="--privileged -v /dev/bus/usb:/dev/bus/usb"
	else
		errcho "Error: target requires docker-machine to work on your platform"
		errcho "See http://gw.tnode.com/docker/docker-machine-with-usb-support-on-windows-macos"
		errcho "Consider flashing with QMK Toolbox (https://github.com/qmk/qmk_toolbox) instead"
		exit 3
	fi
fi
dir=$(pwd -W 2>/dev/null) || dir=$PWD  # Use Windows path if on Windows

# PF: compilation des lib quand nécesaire
# docker run --rm -it -w /qmk_firmware -v $PWD:/qmk_firmware qmkfm/base_container make git-submodule

docker run --rm -it $usb_args \
	-w /qmk_firmware \
	-v "$dir":/qmk_firmware:delegated \
	-e ALT_GET_KEYBOARDS=true \
	-e SKIP_GIT="$SKIP_GIT" \
	-e MAKEFLAGS="$MAKEFLAGS" \
	qmkfm/base_container \
	make "$keyboard${keymap:+:$keymap}${target:+:$target}"
