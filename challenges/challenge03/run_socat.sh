#!/bin/bash
PORT=50003
BIN=./challenge03

socat tcp-l:$PORT,reuseaddr,fork EXEC:"$BIN",pty,stderr,echo=0
