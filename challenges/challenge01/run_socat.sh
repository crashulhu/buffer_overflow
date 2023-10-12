#!/bin/bash
PORT=50001
BIN=./challenge01

socat tcp-l:$PORT,reuseaddr,fork EXEC:"$BIN",pty,stderr,echo=0
