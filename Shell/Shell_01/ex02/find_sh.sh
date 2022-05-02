#!/bin/sh
find -type f -and -name "*.sh" -printf "%f\n" | sed 's/\.[^.]*$//'
