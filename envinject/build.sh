#!/usr/bin/env bash

cc -fPIC -shared -o envinject.so envinject.c -ldl
