#!/bin/bash

echo "==> Test 1: PATH is empty, run ls"
PATH="" echo "ls" | ./hsh

echo "==> Test 2: PATH is empty, run fake command"
PATH="" echo "notacommand" | ./hsh

echo "==> Test 3: Remove PATH, set PATH1 only"
env -u PATH PATH1="/bin:/usr/bin" echo "ls" | ./hsh

echo "==> Test 4: Confirm fork not called (manual)"
PATH="" echo "fakecommand" | ./hsh
