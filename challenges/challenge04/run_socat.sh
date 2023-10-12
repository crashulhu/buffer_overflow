#!/bin/bash
PORT=50004
BIN=./challenge04

socat tcp-l:$PORT,reuseaddr,fork EXEC:"$BIN",pty,stderr,echo=0
