#!/bin/bash
export LD_PRELOAD="/absolute/path/to/stderred/build/libstderred.so${LD_PRELOAD:+:$LD_PRELOAD}"
