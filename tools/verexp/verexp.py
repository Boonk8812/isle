#!/usr/bin/env python3

import argparse
import difflib
import subprocess
import os
import sys

from isledecomp.utils import print_diff

parser = argparse.ArgumentParser(
    allow_abbrev=False, description="Verify Exports: Compare the exports of two DLLs."
)
parser.add_argument("original", metavar="original-binary", help="The original binary")
parser.add_argument(
    "recompiled", metavar="recompiled-binary", help="The recompiled binary"
)
parser.add_argument(
    "--no-color", "-n", action="store_true", help="Do not color the output"
)

args = parser.parse_args()

if not os.path.isfile(args.original):
    parser.error(f"Original binary file {args.original} does not exist")

if not os.path.isfile(args.recompiled):
    parser.error(f"Recompiled binary {args.recompiled} does not exist")


def get_file_in_script_dir(fn):
    return os.path.join(os.path.dirname(os.path.abspath(sys.argv[0])), fn)


def get_exports(file):
    call = [get_file_in_script_dir("DUMPBIN.EXE"), "/EXPORTS"]

    if os.name != "nt":
        call.insert(0, "wine")
        file = subprocess.check_output(["winepath", "-w", file]).decode("utf-8").strip()

    call.append(file)

    raw = subprocess.check_output(call).decode("utf-8").split("\r\n")
    exports = []

    start = False

    for line in raw:
        if not start:
            if line == "            ordinal hint   name":
                start = True
        else:
            if line:
                exports.append(line[27 : line.rindex("  (")])
            elif exports:
                break

    return exports


og_exp = get_exports(args.original)
re_exp = get_exports(args.recompiled)

udiff = difflib.unified_diff(og_exp, re_exp)
has_diff = print_diff(udiff, args.no_color)

sys.exit(1 if has_diff else 0)
