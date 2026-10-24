#!/usr/bin/env python3
import sys
import subprocess

if len(sys.argv) < 2:
    print("Error: The clang-tidy executable was not specified.", file=sys.stderr)
    sys.exit(1)

clang_tidy_exe = sys.argv[1]
args = sys.argv[2:]

filtered_args = []
for arg in args:
    if arg == "-mno-direct-extern-access" or arg.startswith(
        "-mno-direct-extern-access="
    ):
        continue
    filtered_args.append(arg)

cmd = [clang_tidy_exe] + filtered_args
sys.exit(subprocess.run(cmd).returncode)
