# importing modules
from __future__ import print_function
from colorama import Fore, Style
from argparse import ArgumentParser, RawTextHelpFormatter
from pynimations import typewriter   # pynimation is coded by tbhaxor ~ me
import splity.config as c
import splity.join as joiner
import splity.split as splitter
import sys
import os
# about function to print coder related details
def about():
    msg = [
        "{0}Coded By{1} : {2}{coder}{3}".format(
            Fore.LIGHTCYAN_EX,
            Style.RESET_ALL,
            Fore.LIGHTRED_EX,
            Style.RESET_ALL,
            coder=c.CODER_NAME),
        "{0}Submitted To{1} : {2}{sbto}{3}".format(
            Fore.LIGHTCYAN_EX, Style.RESET_ALL, Fore.LIGHTRED_EX,
            Style.RESET_ALL, sbto=c.SUBMITTED_TO),
        "{0}Institution{1} : {2}{insti}{3}".format(
            Fore.LIGHTCYAN_EX, Style.RESET_ALL, Fore.LIGHTRED_EX,
            Style.RESET_ALL, insti=c.INSTITUTION)
    ]
    animate = typewriter.Animator(label=msg, interval=50, wait_unitl=500)
    animate.animate()
    pass

# banner function to print program banner
def banner():
    print("""{0}
+++++++++++++++++++++++++++++++++++++++++++++++++
+      _________      .__  .__  __              +
+     /   _____/_____ |  | |__|/  |_ ___.__.    +
+     \_____  \\\\____ \|  | |  \   __<   |  |    +
+     /        \  |_> >  |_|  ||  |  \___  |    +
+    /_______  /   __/|____/__||__|  / ____|    +
+            \/|__|                  \/         +
+                                               +
+         {1}https://ed-down.herokuapp.com{2}         +
+++++++++++++++++++++++++++++++++++++++++++++++++
{3}
""".format(Fore.LIGHTGREEN_EX, Fore.LIGHTBLUE_EX, Fore.LIGHTGREEN_EX, Style.RESET_ALL))
    pass

def main():
    parser = ArgumentParser(description=c.DESCRIPTION, formatter_class=RawTextHelpFormatter)
    parser.add_argument("-k", "--keep", help="if this flag passed, it will keep .{ext} files\ndefault : False".format(ext=c.SPLIT_EXT), default=False, action="store_true")
    parser.add_argument("-o", "--output-dir", help="sets the output directory of splitted files\ndefault : {0}".format(os.getcwd()), default=os.getcwd())
    parser.add_argument("--about", help="show about text message and exit", action="store_true", default=False)
    parser.add_argument("--split", help="accepts filename to split", metavar="FILENAME.EXT")
    parser.add_argument("--join", help="accepts filename to join in same folder", metavar="FILENAME.EXT")
    parser.add_argument("--chunk", help="accept a non zero chunk size in bytes.\ndefault : {0} bytes".format(c.CHUNK_SIZE), metavar="CHUNK_SIZE", type=int, default=c.CHUNK_SIZE)
    args = parser.parse_args()
    if not(args.about or args.split or args.join):
        parser.parse_args(["-h"])
        pass
    
    if args.about:
        about()
        sys.exit(0)
        pass
    if args.join is not None:
        joiner.main(args.join, args.keep)
        pass
    else:
        splitter.main(args.split, args.chunk, args.keep, args.output_dir)
        pass
    pass