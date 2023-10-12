#!/bin/bash
PORT=50002
BIN=./challenge02

socat tcp-l:$PORT,reuseaddr,fork EXEC:"$BIN",pty,stderr,echo=0
