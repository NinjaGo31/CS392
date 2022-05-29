#!/bin/bash
# Name: Barry Diaz
# Course Section: CS 392-A
# Date: 31 January 2022
# File Name: junk.sh
# Pledge: I pledge my honor that I have abided by the Stevens Honor System

readonly JUNKDIR=$HOME/.junk
mkdir -p $JUNKDIR

function help {
    cat << HEREDOC
Usage: $(basename $0) [-hlp] [list of files]
   -h: Display help.
   -l: List junked files.
   -p: Purge all files.
   [list of files] with no other arguments to junk those files.
HEREDOC
}

# If # of args = 0

if [ $# -eq 0 ]; then
    help
    exit 1
fi

while getopts ":hlp" options; do
    case "${options}" in
        h)
        if [ $# -gt 1 ];then
            echo "Error: Too many options enabled."
            help
            exit 1
        else
            help
            exit 0
        fi
        ;;
        l)
        if [ $# -gt 1 ];then
            echo "Error: Too many options enabled."
            help
            exit 1
        else
            ls -lAF ~/.junk
            exit 0
        fi
        ;;
        p)
        if [ $# -gt 1 ];then
            echo "Error: Too many options enabled."
            help
            exit 1
        else
            for file in $JUNKDIR; do
                rm -rf $file
            done
            mkdir -p $JUNKDIR
        fi
        exit 0
        ;;
        *)
        echo "Error: Unknown option '-${OPTARG}'"
        help
        exit 1
        ;;
    esac
done

for i in $@; do
    if [ -f $i ] || [ -d $i ]; then
        mv $i $JUNKDIR
    else 
        echo "Warning: '$i' not found."
    fi
done
# CS392
