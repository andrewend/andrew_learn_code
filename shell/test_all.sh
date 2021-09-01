#!/bin/bash

find ./ -type f | xargs file | grep ELF | awk -F ":" '{print $1}' | sh > 1.txt
